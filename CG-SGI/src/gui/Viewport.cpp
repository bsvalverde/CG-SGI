#include "gui/Viewport.h"

#include <cfloat>
#include <iostream>
using namespace std;

Viewport::Viewport(QGraphicsView* const janelaGrafica,
		const unsigned int largura, const unsigned int altura) {
	this->janelaGrafica = janelaGrafica;
	this->largura = largura;
	this->altura = altura;
	this->clipping = 0;
	this->rasterizador = new Rasterizador(this->largura, this->altura);
	this->iluminador = new Iluminador(this->largura, this->altura);
	this->setAlgoritmoClippingLinhas(Clipping::COHEN_SUTHERLAND);
	this->matrizPixels = new Pixel*[this->largura];
	for (unsigned int i = 0; i < this->largura; i++) {
		this->matrizPixels[i] = new Pixel[this->altura];
	}

	// Área de clipping
	QGraphicsScene* scene = this->janelaGrafica->scene();

	if (scene)
		delete scene;

	scene = new QGraphicsScene(0, 0, this->largura - 5, this->altura - 5,
			this->janelaGrafica);
	this->desenharAreaClipping(scene);
	this->janelaGrafica->setScene(scene);
}

Viewport::~Viewport() {
	if (this->clipping)
		delete this->clipping;

	if (this->rasterizador)
		delete this->rasterizador;

	if (this->iluminador)
		delete this->iluminador;

	for (unsigned int i = 0; i < this->largura; i++) {
		delete this->matrizPixels[i];
	}
	delete this->matrizPixels;
}

void Viewport::atualizarCena(const QList<ObjetoGeometrico*>& objetos) {
	this->reiniciarMatrizPixels();
	QGraphicsScene* scene = this->janelaGrafica->scene();

	if (scene)
		delete scene;

	scene = new QGraphicsScene(0, 0, this->largura - 5, this->altura - 5,
			this->janelaGrafica);

	for (int i = 0; i < objetos.size(); i++) {
		ObjetoGeometrico* objeto = objetos.at(i)->clonar();
		ObjetoGeometrico* objetoRecortado = this->clipping->clip(objeto);

		// Objeto está fora da window
		if (objetoRecortado == 0) {
			delete objeto;
			continue;
		}
		QList<Pixel> pixels;
		if (objetoRecortado->getTipo() == ObjetoGeometrico::OBJETO3D) {
			QList<Faceta> facetas = ((Objeto3D*) objetoRecortado)->getFacetas();
			for (Faceta f : facetas) {
				QList<Ponto> pontos = f.getPontos();
				Poligono p("", pontos, f.getCor());
				pixels.append(this->rasterizador->rasterizarObjeto(&p));
			}

		} else {
			pixels = this->rasterizador->rasterizarObjeto(objetoRecortado);
		}
		for (Pixel px : pixels) {
			/*px = iluminador->iluminarPixel(px);
			QPen pen(px.getCor());
			scene->addLine(px.getX(), px.getY(), px.getX(), px.getY(), pen);*/
			int x = px.getX();
			int y = px.getY();
			int z = px.getZ();
			if (this->matrizPixels[x][y].getZ() > z) {
				this->matrizPixels[x][y] = px;
			}
		}

		delete objetoRecortado;

		if (objetoRecortado != objeto)
			delete objeto;
	}

	this->desenharCena(scene);
	this->desenharAreaClipping(scene);
	this->janelaGrafica->setScene(scene);
	this->janelaGrafica->repaint();
}

void Viewport::setAlgoritmoClippingLinhas(
		Clipping::AlgoritmoClippingLinha algoritmo) {
	if (this->clipping)
		delete this->clipping;

	double larguraD = (double) this->largura;
	double alturaD = (double) this->altura;

	double xvMin = 2 * MARGEM_CLIPPING / larguraD - 1;
	double xvMax = 2 * (larguraD - MARGEM_CLIPPING) / larguraD - 1;
	double yvMin = 2 * MARGEM_CLIPPING / alturaD - 1;
	double yvMax = 2 * (alturaD - MARGEM_CLIPPING - 1) / alturaD - 1;

	switch (algoritmo) {
	case Clipping::COHEN_SUTHERLAND:
		this->clipping = new ClippingCohenSutherland(xvMin, xvMax, yvMin,
				yvMax);
		break;
	case Clipping::LIANG_BARSKY:
		this->clipping = new ClippingLiangBarsky(xvMin, xvMax, yvMin, yvMax);
		break;
	}
}

QList<Ponto> Viewport::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, Ponto("vwp-p1", MARGEM_CLIPPING, MARGEM_CLIPPING, 0));
	pontos.insert(1,
			Ponto("vwp-p2", this->largura - MARGEM_CLIPPING, MARGEM_CLIPPING,
					0));
	pontos.insert(2,
			Ponto("vwp-p3", this->largura - MARGEM_CLIPPING,
					this->altura - MARGEM_CLIPPING, 0));
	pontos.insert(3,
			Ponto("vwp-p4", MARGEM_CLIPPING, this->altura - MARGEM_CLIPPING,
					0));

	return pontos;
}

void Viewport::reiniciarMatrizPixels() {
	Pixel px = Pixel();
	for (unsigned int x = 0; x < this->largura; x++) {
		for (unsigned int y = 0; y < this->altura; y++) {
			this->matrizPixels[x][y] = px;
		}
	}
}

void Viewport::desenharCena(QGraphicsScene * const scene) {
	for (unsigned int x = 0; x < this->largura; x++) {
		for (unsigned int y = 0; y < this->altura; y++) {
			Pixel px = this->matrizPixels[x][y];
			px = iluminador->iluminarPixel(px);
			cout << "iluminou" << x << "," << y << endl;
			QPen pen(px.getCor());
			scene->addLine(px.getX(), px.getY(), px.getX(), px.getY(), pen);
			//scene->addEllipse(px.getX(), px.getY(), 1, 1, pen,
			//		QBrush(px.getCor()));
			//cout << "pixel:" << px.getX() << "," << px.getY() << endl;
		}
	}
}

void Viewport::desenharAreaClipping(QGraphicsScene* const scene) {
	QPen pen(QColor(255, 0, 0));
	QLineF linha1 = QLineF(MARGEM_CLIPPING, MARGEM_CLIPPING,
			this->largura - MARGEM_CLIPPING, MARGEM_CLIPPING);
	QLineF linha2 = QLineF(this->largura - MARGEM_CLIPPING, MARGEM_CLIPPING,
			this->largura - MARGEM_CLIPPING, this->altura - MARGEM_CLIPPING);
	QLineF linha3 = QLineF(MARGEM_CLIPPING, MARGEM_CLIPPING, MARGEM_CLIPPING,
			this->altura - MARGEM_CLIPPING);
	QLineF linha4 = QLineF(MARGEM_CLIPPING, this->altura - MARGEM_CLIPPING,
			this->largura - MARGEM_CLIPPING, this->altura - MARGEM_CLIPPING);

	scene->addLine(linha1, pen);
	scene->addLine(linha2, pen);
	scene->addLine(linha3, pen);
	scene->addLine(linha4, pen);
}

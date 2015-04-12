#include "gui/Viewport.h"
#include <iostream>

Viewport::Viewport(QGraphicsView* const janelaGrafica, const double largura, const double altura) {
	this->janelaGrafica = janelaGrafica;
	this->largura = largura;
	this->altura = altura;
	this->clipping = 0;
	this->setAlgoritmoClippingLinhas(Clipping::COHEN_SUTHERLAND);

	// Área de clipping
	QGraphicsScene* scene = this->janelaGrafica->scene();

	if(scene)
		delete scene;

	scene = new QGraphicsScene(0, 0, this->largura - 4,
								this->altura - 6, this->janelaGrafica);
	this->desenharAreaClipping(scene);
	this->janelaGrafica->setScene(scene);
}

Viewport::~Viewport() {
	if(this->clipping)
		delete this->clipping;
}

void Viewport::atualizarObjetos(const QList<ObjetoGeometrico*>& objetos) {
	QGraphicsScene* scene = this->janelaGrafica->scene();

	if(scene)
		delete scene;

	scene = new QGraphicsScene(0, 0, this->largura - 4,
								this->altura - 6, this->janelaGrafica);

	for(int i = 0; i < objetos.size(); i++) {
		ObjetoGeometrico* objeto = objetos.at(i)->clonar();

		if(this->clipping->clip(objeto)) {
			QList<Ponto> pontos = objeto->getPontos();
			pontos = this->transformarObjeto(pontos);

			if(pontos.size() == 0)
				continue;

			QPen pen(objeto->getCor());
			QLineF line;
			Ponto ponto1 = pontos.at(0);

			if(pontos.size() > 1) {
				Ponto ant = ponto1;

				for(int i = 1; i < pontos.size(); i++) {
					line = QLineF(ant.getX(), ant.getY(), pontos.at(i).getX(), pontos.at(i).getY());
					scene->addLine(line, pen);
					ant = pontos.at(i);
				}
				if(objeto->getTipo() == ObjetoGeometrico::POLIGONO) {
					line = QLineF(ant.getX(), ant.getY(), ponto1.getX(), ponto1.getY());
					scene->addLine(line, pen);
				}
			} else {
				scene->addEllipse(ponto1.getX(), ponto1.getY(), 3, 3, pen, QBrush(objeto->getCor()));
			}
		}

		delete objeto;
	}

	this->desenharAreaClipping(scene);
	this->janelaGrafica->setScene(scene);
	this->janelaGrafica->repaint();
}

void Viewport::setAlgoritmoClippingLinhas(Clipping::AlgoritmoClippingLinha algoritmo) {
	if(this->clipping)
		delete this->clipping;

	double xvMin = 2 * CLIPPING_MARGIN / this->largura - 1;
	double xvMax = 2 * (this->largura - CLIPPING_MARGIN) / this->largura - 1;
	double yvMin = 2 * CLIPPING_MARGIN / this->altura - 1;
	double yvMax = 2 * (this->altura - CLIPPING_MARGIN) / this->altura - 1;

	switch(algoritmo) {
		case Clipping::COHEN_SUTHERLAND:
			this->clipping = new ClippingCohenSutherland(xvMin, xvMax, yvMin, yvMax);
			break;
		case Clipping::LIANG_BARSKY:
			this->clipping = new ClippingLiangBarsky(xvMin, xvMax, yvMin, yvMax);
			break;
	}
}

QList<Ponto> Viewport::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, Ponto("vwp-p1", CLIPPING_MARGIN, CLIPPING_MARGIN, 0));
	pontos.insert(1, Ponto("vwp-p2", this->largura - CLIPPING_MARGIN, CLIPPING_MARGIN, 0));
	pontos.insert(2, Ponto("vwp-p3", this->largura - CLIPPING_MARGIN, this->altura - CLIPPING_MARGIN, 0));
	pontos.insert(3, Ponto("vwp-p4", CLIPPING_MARGIN, this->altura - CLIPPING_MARGIN, 0));

	return pontos;
}

QVector<double> Viewport::transformarPonto(const QVector<double>& coordenadas) {
	double xwMin = -1;
	double xwMax = 1;
	double ywMin = -1;
	double ywMax = 1;

	double xp = ((coordenadas[0] - xwMin) / (xwMax - xwMin)) * this->largura;
	double yp = (1 - (coordenadas[1] - ywMin) / (ywMax - ywMin)) * this->altura;
	QVector<double> novoPonto = {xp, yp, 1};
	return novoPonto;
}

QList<Ponto> Viewport::transformarObjeto(const QList<Ponto>& pontos) {
	QList<Ponto> novosPontos;

	for(int i = 0; i < pontos.size(); i++) {
		Ponto p = pontos.at(i);
		QVector<double> coordenadas = {p.getX(), p.getY(), p.getZ()};
		QVector<double> novoPonto = this->transformarPonto(coordenadas);
		novosPontos.insert(i, Ponto(p.getNome(), novoPonto[0], novoPonto[1], novoPonto[2], p.getCor()));
	}

	return novosPontos;
}

void Viewport::desenharAreaClipping(QGraphicsScene* const scene) {
	QPen pen(QColor(255, 0, 0));
	QLineF linha1 = QLineF(CLIPPING_MARGIN, CLIPPING_MARGIN, this->largura - CLIPPING_MARGIN, CLIPPING_MARGIN);
	QLineF linha2 = QLineF(this->largura - CLIPPING_MARGIN, CLIPPING_MARGIN, this->largura - CLIPPING_MARGIN, this->altura - CLIPPING_MARGIN);
	QLineF linha3 = QLineF(CLIPPING_MARGIN, CLIPPING_MARGIN, CLIPPING_MARGIN, this->altura - CLIPPING_MARGIN);
	QLineF linha4 = QLineF(CLIPPING_MARGIN, this->altura - CLIPPING_MARGIN, this->largura - CLIPPING_MARGIN, this->altura - CLIPPING_MARGIN);

	scene->addLine(linha1, pen);
	scene->addLine(linha2, pen);
	scene->addLine(linha3, pen);
	scene->addLine(linha4, pen);
}

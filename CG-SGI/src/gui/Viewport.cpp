#include "gui/Viewport.h"

Viewport::Viewport(QGraphicsView* const janelaGrafica, const double largura, const double altura) {
	this->janelaGrafica = janelaGrafica;
	this->largura = largura;
	this->altura = altura;
}

Viewport::~Viewport() {}

void Viewport::atualizarObjetos(const QList<ObjetoGeometrico*>& objetos) {
	QGraphicsScene* scene = this->janelaGrafica->scene();

	if(scene)
		delete scene;

	scene = new QGraphicsScene(0, 0, this->largura - 4,
								this->altura - 6, this->janelaGrafica);

	for(int i = 0; i < objetos.size(); i++) {
		QList<Ponto> pontos = objetos.at(i)->getPontos();
		pontos = this->transformarObjeto(pontos);

		QPen pen(objetos.at(i)->getCor());
		QLineF line;
		Ponto ponto1 = pontos.at(0);

		if(pontos.size() > 1) {
			Ponto ant = ponto1;

			for(int i = 1; i < pontos.size(); i++) {
				line = QLineF(ant.getX(), ant.getY(), pontos.at(i).getX(), pontos.at(i).getY());
				scene->addLine(line, pen);
				ant = pontos.at(i);
			}
			line = QLineF(ant.getX(), ant.getY(), ponto1.getX(), ponto1.getY());
			scene->addLine(line, pen);
		} else {
			scene->addEllipse(ponto1.getX(), ponto1.getY(), 3, 3, pen, QBrush(objetos.at(i)->getCor()));
		}
	}

	this->janelaGrafica->setScene(scene);
	this->janelaGrafica->repaint();
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

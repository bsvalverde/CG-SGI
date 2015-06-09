#include "gui/clipping/Clipping.h"
#include <iostream>

Clipping::Clipping(const double xvMin, const double xvMax, const double yvMin,
		const double yvMax) {
	this->xvMin = xvMin;
	this->xvMax = xvMax;
	this->yvMin = yvMin;
	this->yvMax = yvMax;
}

Clipping::~Clipping() {
}

ObjetoGeometrico* Clipping::clip(ObjetoGeometrico* const objeto) const {
	switch (objeto->getTipo()) {
		case ObjetoGeometrico::CURVA_BEZIER:
		case ObjetoGeometrico::CURVA_BSPLINE:
			return this->clipCurva((Curva* const) objeto);
		case ObjetoGeometrico::POLIGONO:
			return this->clipPoligono((Poligono* const) objeto);
		case ObjetoGeometrico::PONTO:
			return this->clipPonto((Ponto* const) objeto);
		case ObjetoGeometrico::RETA:
			return this->clipReta((Reta* const) objeto);
		default:
			return 0;
	}
}

ObjetoGeometrico* Clipping::clipObjeto3D(Objeto3D* const objeto) const {
//	QList<Aresta> arestas = objeto->getArestas();
//	QList<Aresta> novasArestas;
//
//	for(Aresta a : arestas) {
//		Reta r("", a.getPontos().at(0), a.getPontos().at(1));
//		this->clipReta(&r);
//
//		if(pontos.size() == 2) {
//			novasArestas.append(Aresta(new Ponto(pontos.at(0)), new Ponto(pontos.at(1)), a.getCor()));
//		}
//	}

	return 0; // TODO new Objeto3D(objeto->getNome(), novasArestas);
}

ObjetoGeometrico* Clipping::clipCurva(const Curva* const curva) const {
	QList<Ponto> pontosCurva = curva->getPontos();
	QList<Ponto> novosPontos;
	QList<BordaClipping> bordas = { DIREITA, ESQUERDA, FUNDO, TOPO };

	for (BordaClipping borda : bordas) {
		for (int i = 1; i < pontosCurva.size(); i++) {
			Ponto p1 = pontosCurva.at(i - 1);
			Ponto p2 = pontosCurva.at(i);

			if (this->clipPontosPorBorda(&p1, &p2, borda)) {
				if (novosPontos.size() > 0 && novosPontos.last() == p1)
					novosPontos.removeLast();

				novosPontos.insert(novosPontos.size(), p1);
				novosPontos.insert(novosPontos.size(), p2);
			}
		}
		pontosCurva = novosPontos;
		novosPontos.clear();
	}

	return 0; // TODO
}

ObjetoGeometrico* Clipping::clipPoligono(const Poligono* const poligono) const {
	QList<Ponto> pontosPoligono = poligono->getPontos();
	QList<BordaClipping> bordas = { DIREITA, ESQUERDA, FUNDO, TOPO };

	std::cout << pontosPoligono.size() << std::endl;

	for (BordaClipping borda : bordas) {

		QList<Ponto> novosPontos;
		for (int i = 0; i < pontosPoligono.size(); i++) {
			Ponto p1 = pontosPoligono.at(i);
			Ponto p2 = pontosPoligono.at((i + 1) % pontosPoligono.size());

			if (this->clipPontosPorBorda(&p1, &p2, borda)) {
				if (novosPontos.size() > 0 && novosPontos.last() == p1)
					novosPontos.removeLast();

				novosPontos.insert(novosPontos.size(), p1);
				novosPontos.insert(novosPontos.size(), p2);
			}
		}
		std::cout << pontosPoligono.size() << std::endl;
		pontosPoligono.clear();

		for(Ponto p : novosPontos)
			pontosPoligono.append(p);
		std::cout << pontosPoligono.size() << std::endl;
	}

	return new Poligono(poligono->getNome(), pontosPoligono, poligono->getCor());
}

ObjetoGeometrico* Clipping::clipPonto(const Ponto* const ponto) const {
	if((ponto->getX() > xvMin && ponto->getX() < xvMax
			&& ponto->getY() > yvMin && ponto->getY() < yvMax)) {
		return new Ponto(*ponto);
	}
	return 0;
}

bool Clipping::clipPontosPorBorda(Ponto* const p1, Ponto* const p2,
		BordaClipping borda) const {
	Reta reta("", *p1, *p2);

	this->clipRetaPorBorda(&reta, borda);

	Ponto p1n = reta.getPontos().at(0);
	Ponto p2n = reta.getPontos().at(1);

	bool p1Dentro = this->pontoDentroDaViewport(p1, borda);
	bool p2Dentro = this->pontoDentroDaViewport(p2, borda);

	if (p1Dentro && !p2Dentro) { // p1 dentro e p2 fora
		p2->setX(p2n.getX());
		p2->setY(p2n.getY());
		return true;
	} else if (!p1Dentro && p2Dentro) { // p1 fora e p2 dentro
		p1->setX(p1n.getX());
		p1->setY(p1n.getY());
		return true;
	}

	return p1Dentro || p2Dentro;
}

void Clipping::clipRetaPorBorda(Reta* const reta, BordaClipping borda) const {
	double coefAngular = reta->coeficienteAngular();
	Ponto* p1 = reta->getPontosObjeto().at(0);
	Ponto* p2 = reta->getPontosObjeto().at(1);
	double valX1 = 0;
	double valY1 = 0;
	double valX2 = 0;
	double valY2 = 0;

	switch (borda) {
	case BordaClipping::DIREITA:
		valX1 = xvMax;
		valY1 = coefAngular * (xvMax - p1->getX()) + p1->getY();
		valX2 = xvMax;
		valY2 = coefAngular * (xvMax - p2->getX()) + p2->getY();
		break;
	case BordaClipping::ESQUERDA:
		valX1 = xvMin;
		valY1 = coefAngular * (xvMin - p1->getX()) + p1->getY();
		valX2 = xvMin;
		valY2 = coefAngular * (xvMin - p2->getX()) + p2->getY();
		break;
	case BordaClipping::FUNDO:
		valX1 = p1->getX() + (yvMin - p1->getY()) / coefAngular;
		valY1 = yvMin;
		valX2 = p2->getX() + (yvMin - p2->getY()) / coefAngular;
		valY2 = yvMin;
		break;
	case BordaClipping::TOPO:
		valX1 = p1->getX() + (yvMax - p1->getY()) / coefAngular;
		valY1 = yvMax;
		valX2 = p2->getX() + (yvMax - p2->getY()) / coefAngular;
		valY2 = yvMax;
		break;
	}
	p1->setX(valX1);
	p1->setY(valY1);
	p2->setX(valX2);
	p2->setY(valY2);
}

bool Clipping::pontoDentroDaViewport(Ponto* const p,
		BordaClipping borda) const {
	switch (borda) {
		case BordaClipping::DIREITA:
			return p->getX() <= xvMax;
		case BordaClipping::ESQUERDA:
			return p->getX() >= xvMin;
		case BordaClipping::FUNDO:
			return p->getY() >= yvMin;
		default:
			return p->getY() <= yvMax;
	}
}

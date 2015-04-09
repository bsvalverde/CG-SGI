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

bool Clipping::clip(ObjetoGeometrico* const objeto) const {
	switch (objeto->getTipo()) {
	case ObjetoGeometrico::POLIGONO:
		return this->clipPoligono((Poligono* const ) objeto);
	case ObjetoGeometrico::PONTO:
		return this->clipPonto((Ponto* const ) objeto);
	case ObjetoGeometrico::RETA:
		return this->clipReta((Reta* const ) objeto);
	default:
		return false;
	}
}

bool Clipping::clipPoligono(Poligono* const poligono) const {
	QList<Ponto> pontosPoligono = poligono->getPontos();
	QList<Ponto> novosPontos;
	QList<BordaClipping> bordas = {DIREITA, ESQUERDA, FUNDO, TOPO};

	for(BordaClipping borda : bordas) {
		for(int i = 0; i < pontosPoligono.size(); i++) {
			Ponto p1 = pontosPoligono.at(i);
			Ponto p2 = pontosPoligono.at((i+1)%pontosPoligono.size());

			if(this->clipRetaEmBorda(&p1, &p2, borda)) {
				if(novosPontos.size() > 0 && novosPontos.last() == p1)
					novosPontos.removeLast();

				novosPontos.insert(novosPontos.size(), p1);
				novosPontos.insert(novosPontos.size(), p2);
			}
		}
		pontosPoligono = novosPontos;
		novosPontos.clear();
	}
	poligono->setPontos(pontosPoligono);

	return true;
}

bool Clipping::clipPonto(Ponto* const ponto) const {
	return (ponto->getX() > xvMin && ponto->getX() < xvMax
			&& ponto->getY() > yvMin && ponto->getY() < yvMax);
}

bool Clipping::clipRetaEmBorda(Ponto* const p1, Ponto* const p2, BordaClipping borda) const {
	Reta reta("", *p1, *p2);
	this->clipReta(&reta);
	Ponto p1n = reta.getPontos().at(0);
	Ponto p2n = reta.getPontos().at(1);

	bool p1Dentro = this->pontoDentroDaViewport(p1, borda);
	bool p2Dentro = this->pontoDentroDaViewport(p2, borda);

	if(p1Dentro && !p2Dentro) { // p1 dentro e p2 fora
		p2->setX(p2n.getX());
		p2->setY(p2n.getY());
		return true;
	} else if(!p1Dentro && p2Dentro) { // p1 fora e p2 dentro
		p1->setX(p1n.getX());
		p1->setY(p1n.getY());
		return true;
	}

	return p1Dentro || p2Dentro;
}

bool Clipping::pontoDentroDaViewport(Ponto* const p, BordaClipping borda) const {
	switch(borda) {
		case BordaClipping::DIREITA:
			return p->getX() <= xvMax;
		case BordaClipping::ESQUERDA:
			return p->getX() >= xvMin;
		case BordaClipping::FUNDO:
			return p->getY() >= yvMin;
		case BordaClipping::TOPO:
			return p->getY() <= yvMax;
		default:
			return false;
	}
}

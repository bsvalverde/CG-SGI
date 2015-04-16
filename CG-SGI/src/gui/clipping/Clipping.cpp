#include "gui/clipping/Clipping.h"

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
	case ObjetoGeometrico::CURVA_BEZIER:
		return this->clipCurvaBezier((CurvaBezier* const ) objeto);
	case ObjetoGeometrico::CURVA_BSPLINE:
		return this->clipCurvaBSpline((CurvaBSpline* const ) objeto);
	case ObjetoGeometrico::POLIGONO:
		return this->clipPoligono((Poligono* const ) objeto);
	case ObjetoGeometrico::PONTO:
		return this->clipPonto((Ponto* const ) objeto);
	case ObjetoGeometrico::RETA:
		return this->clipReta((Reta* const ) objeto);
	default:
		return true;
	}
}

bool Clipping::clipCurvaBSpline(CurvaBSpline* const curva) const {
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
	curva->setPontosParametricos(pontosCurva);

	return true;
}
bool Clipping::clipCurvaBezier(CurvaBezier* const curva) const {
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
	curva->setPontosParametricos(pontosCurva);

	return true;
}

bool Clipping::clipPoligono(Poligono* const poligono) const {
	QList<Ponto> pontosPoligono = poligono->getPontos();
	QList<Ponto> novosPontos;
	QList<BordaClipping> bordas = { DIREITA, ESQUERDA, FUNDO, TOPO };

	for (BordaClipping borda : bordas) {
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

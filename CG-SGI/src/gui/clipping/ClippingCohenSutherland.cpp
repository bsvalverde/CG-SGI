#include "gui/clipping/ClippingCohenSutherland.h"

ClippingCohenSutherland::ClippingCohenSutherland(const double xvMin,
		const double xvMax, const double yvMin, const double yvMax) :
		Clipping(xvMin, xvMax, yvMin, yvMax) {}

ClippingCohenSutherland::~ClippingCohenSutherland() {
}

bool ClippingCohenSutherland::clipReta(Reta* const reta) const {
	QList<Ponto*> pontos = reta->getPontosObjeto();
	Ponto* p1 = pontos.at(0);
	Ponto* p2 = pontos.at(1);
	double coefAngular = reta->coeficienteAngular();

	/*
	short test = 0b100;
	std::cout << (test | 0b1) << std::endl;
	 */

	int rc1[4] = { 0, 0, 0, 0 };
	if (p1->getX() > xvMax) {
		rc1[0] = 1;
	} else if (p1->getX() < xvMin) {
		rc1[1] = 1;
	}
	if (p1->getY() > yvMax) {
		rc1[3] = 1;
	} else if (p1->getY() < yvMin) {
		rc1[4] = 1;
	}
	int rc2[4] = { 0, 0, 0, 0 };
	if (p2->getX() > xvMax) {
		rc2[0] = 1;
	} else if (p2->getX() < xvMin) {
		rc2[1] = 1;
	}
	if (p2->getY() > yvMax) {
		rc2[3] = 1;
	} else if (p2->getY() < yvMin) {
		rc2[4] = 1;
	}
	if ((rc1[0] == 1 && rc2[0] == 1) || (rc1[1] == 1 && rc2[1] == 1)
			|| (rc1[2] == 1 && rc2[2] == 1) || (rc1[3] == 1 && rc2[3] == 1))
		return false;
	if (rc1 == rc2)
		return true;
	if (rc1[0] == 1) {
		if (!this->clippingTopo(p1, coefAngular))
			return false;
	} else if (rc1[1] == 1) {
		if (!this->clippingFundo(p1, coefAngular))
			return false;
	}
	if (rc1[2] == 1) {
		if (!this->clippingDireita(p1, coefAngular))
			return false;
	} else if (rc1[3] == 1) {
		if (!this->clippingEsquerda(p1, coefAngular))
			return false;
	}
	return true;
}

bool ClippingCohenSutherland::clippingDireita(Ponto *p, const double coefAngular) const {
	double y = coefAngular * (xvMax - p->getX()) + p->getY();
	if (y < yvMin || y > yvMax)
		return false;
	p->setX(xvMax);
	p->setY(y);
	return true;
}

bool ClippingCohenSutherland::clippingEsquerda(Ponto *p, const double coefAngular) const {
	double y = coefAngular * (xvMin - p->getX()) + p->getY();
	if (y < yvMin || y > yvMax)
		return false;
	p->setX(xvMin);
	p->setY(y);
	return true;
}

bool ClippingCohenSutherland::clippingFundo(Ponto *p, const double coefAngular) const {
	double x = p->getX() + 1 / (coefAngular * (yvMin - p->getY()));
	if (x < xvMin || x > xvMax)
		return false;
	p->setX(x);
	p->setY(yvMin);
	return true;
}

bool ClippingCohenSutherland::clippingTopo(Ponto *p, const double coefAngular) const {
	double x = p->getX() + 1 / (coefAngular * (yvMax - p->getY()));
	if (x < xvMin || x > xvMax)
		return false;
	p->setX(x);
	p->setY(yvMax);
	return true;
}

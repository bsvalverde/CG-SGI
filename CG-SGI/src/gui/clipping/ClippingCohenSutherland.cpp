#include "gui/clipping/ClippingCohenSutherland.h"

ClippingCohenSutherland::ClippingCohenSutherland(const double xvMin,
		const double xvMax, const double yvMin, const double yvMax) :
		Clipping(xvMin, xvMax, yvMin, yvMax) {
}

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

	// Region Code = Topo [0] Fundo [1] Direita [2] Esquerda [3]
	int rc1[4] = { 0, 0, 0, 0 };

	if (p1->getX() > xvMax) {
		rc1[2] = 1;
	} else if (p1->getX() < xvMin) {
		rc1[3] = 1;
	}

	if (p1->getY() > yvMax) {
		rc1[0] = 1;
	} else if (p1->getY() < yvMin) {
		rc1[1] = 1;
	}

	int rc2[4] = { 0, 0, 0, 0 };

	if (p2->getX() > xvMax) {
		rc2[2] = 1;
	} else if (p2->getX() < xvMin) {
		rc2[3] = 1;
	}
	if (p2->getY() > yvMax) {
		rc2[0] = 1;
	} else if (p2->getY() < yvMin) {
		rc2[1] = 1;
	}

	if ((rc1[0] && rc2[0]) || (rc1[1] && rc2[1]) || (rc1[2] && rc2[2])
			|| (rc1[3] && rc2[3]))
		return false;

	if ((rc1[0] == rc2[0]) && (rc1[1] == rc2[1]) && (rc1[2] == rc2[2])
			&& (rc1[3] == rc2[3]))
		return true;

	switch (rc1[0] + rc1[1] + rc1[2] + rc1[3]) {
	case 1:
		if (!this->clippingBasico(rc1, p1, coefAngular))
			return false;
		break;
	case 2:
		this->clippingComposto(rc1, p1, coefAngular);
		break;
	default:
		break;
	}

	switch (rc2[0] + rc2[1] + rc2[2] + rc2[3]) {
	case 1:
		if (!this->clippingBasico(rc2, p2, coefAngular))
			return false;
		break;
	case 2:
		this->clippingComposto(rc2, p2, coefAngular);
		break;
	default:
		break;
	}
	return true;
}

bool ClippingCohenSutherland::clippingBasico(int *rc, Ponto* const p,
		const double coefAngular) const {
	if (rc[0]) {
		if (!this->clippingTopo(p, coefAngular))
			return false;
	} else if (rc[1]) {
		if (!this->clippingFundo(p, coefAngular))
			return false;
	}
	if (rc[2]) {
		if (!this->clippingDireita(p, coefAngular))
			return false;
	} else if (rc[3]) {
		if (!this->clippingEsquerda(p, coefAngular))
			return false;
	}
	return true;
}

bool ClippingCohenSutherland::clippingComposto(int *rc, Ponto* const p,
		const double coefAngular) const {
	if (rc[0]) {
		this->clippingTopo(p, coefAngular);
	} else if (rc[1]) {
		this->clippingFundo(p, coefAngular);
	}
	if (rc[2] && p->getX() > xvMax) {
		this->clippingDireita(p, coefAngular);
	} else if (rc[3] && p->getX() < xvMin) {
		this->clippingEsquerda(p, coefAngular);
	}
	return true;
}

bool ClippingCohenSutherland::clippingDireita(Ponto* const p,
		const double coefAngular) const {
	double y = coefAngular * (xvMax - p->getX()) + p->getY();
	if (y < yvMin || y > yvMax)
		return false;
	p->setX(xvMax);
	p->setY(y);
	return true;
}

bool ClippingCohenSutherland::clippingEsquerda(Ponto* const p,
		const double coefAngular) const {
	double y = coefAngular * (xvMin - p->getX()) + p->getY();
	if (y < yvMin || y > yvMax)
		return false;
	p->setX(xvMin);
	p->setY(y);
	return true;
}

bool ClippingCohenSutherland::clippingFundo(Ponto* const p,
		const double coefAngular) const {
	double x = p->getX() + (yvMin - p->getY()) / coefAngular;
	if (x < xvMin || x > xvMax)
		return false;
	p->setX(x);
	p->setY(yvMin);
	return true;
}

bool ClippingCohenSutherland::clippingTopo(Ponto* const p,
		const double coefAngular) const {
	double x = p->getX() + (yvMax - p->getY()) / coefAngular;
	if (x < xvMin || x > xvMax)
		return false;
	p->setX(x);
	p->setY(yvMax);
	return true;
}

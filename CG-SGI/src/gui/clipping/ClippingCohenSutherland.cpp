#include "gui/clipping/ClippingCohenSutherland.h"

ClippingCohenSutherland::ClippingCohenSutherland(const double xvMin,
		const double xvMax, const double yvMin, const double yvMax) :
		Clipping(xvMin, xvMax, yvMin, yvMax) {
}

ClippingCohenSutherland::~ClippingCohenSutherland() {
}

QList<Ponto> ClippingCohenSutherland::clipReta(const Reta* const reta) const {
	QList<Ponto> pontos = reta->getPontos();
	Ponto p1 = pontos.at(0);
	Ponto p2 = pontos.at(1);

	// Region Code = Topo [0] Fundo [1] Direita [2] Esquerda [3]
	short rc1[4] = {0, 0, 0, 0};
	short rc2[4] = {0, 0, 0, 0};
	this->carregarRcPonto(&p1, rc1);
	this->carregarRcPonto(&p2, rc2);

	if ((rc1[0] * rc2[0] + rc1[1] * rc2[1] + rc1[2] * rc2[2] + rc1[3] * rc2[3])
			!= 0)
		return QList<Ponto>();

	if ((rc1[0] + rc2[0] + rc1[1] + rc2[1] + rc1[2] + rc2[2] + rc1[3] + rc2[3])
			== 0)
		return pontos;

	double coefAngular = reta->coeficienteAngular();

	switch (rc1[0] + rc1[1] + rc1[2] + rc1[3]) {
		case 1:
			if (!this->clippingBasico(rc1, &p1, coefAngular))
				return QList<Ponto>();
			break;
		case 2:
			if (!this->clippingComposto(rc1, &p1, coefAngular))
				return QList<Ponto>();
			break;
		default:
			break;
	}

	pontos.clear();
	pontos.append(p1);

	switch (rc2[0] + rc2[1] + rc2[2] + rc2[3]) {
		case 1:
			this->clippingBasico(rc2, &p2, coefAngular);
			pontos.append(p2);
			return pontos;
		case 2:
			this->clippingComposto(rc2, &p2, coefAngular);
			pontos.append(p2);
			return pontos;
		default:
			break;
	}

	return QList<Ponto>();
}

void ClippingCohenSutherland::carregarRcPonto(const Ponto* const p, short rc[4]) const {
	if (p->getY() > yvMax) {
		rc[0] = 1;
	} else if (p->getY() < yvMin) {
		rc[1] = 1;
	}
	if (p->getX() > xvMax) {
		rc[2] = 1;
	} else if (p->getX() < xvMin) {
		rc[3] = 1;
	}
}

bool ClippingCohenSutherland::clippingBasico(short *rc, Ponto* const p,
		const double coefAngular) const {
	if (rc[0]) {
		return this->clippingTopo(p, coefAngular);
	} else if (rc[1]) {
		return this->clippingFundo(p, coefAngular);
	}
	if (rc[2]) {
		return this->clippingDireita(p, coefAngular);
	} else if (rc[3]) {
		return this->clippingEsquerda(p, coefAngular);
	}

	return true;
}

bool ClippingCohenSutherland::clippingComposto(short *rc, Ponto* const p,
		const double coefAngular) const {
	bool continua = true;
	if (rc[0]) {
		continua = !this->clippingTopo(p, coefAngular);
	} else if (rc[1]) {
		continua = !this->clippingFundo(p, coefAngular);
	}
	if (rc[2] && continua) {
		return this->clippingDireita(p, coefAngular);
	} else if (rc[3] && continua) {
		return this->clippingEsquerda(p, coefAngular);
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

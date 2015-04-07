#include "gui/clipping/ClippingLiangBarsky.h"

ClippingLiangBarsky::ClippingLiangBarsky(const double xvMin, const double xvMax,
		const double yvMin, const double yvMax) :
		Clipping(xvMin, xvMax, yvMin, yvMax) {
}

ClippingLiangBarsky::~ClippingLiangBarsky() {
}

bool ClippingLiangBarsky::clipReta(Reta* const reta) const {
	QList<Ponto*> pontos = reta->getPontosObjeto();
	Ponto* p1 = pontos.at(0);
	Ponto* p2 = pontos.at(1);
	double coefAngular = reta->coeficienteAngular();

	int p[4];
	p[0] = -(p2->getX() - p1->getX());
	p[1] = (p2->getX() - p1->getX());
	p[2] = -(p2->getY() - p1->getY());
	p[3] = (p2->getY() - p1->getY());

	int q[4];
	q[0] = p1->getX() - xvMin;
	q[1] = xvMax - p1->getX();
	q[2] = p1->getY() - yvMin;
	q[3] = yvMax - p1->getX();

	double sigma1 = this->sigma1(p, q);
	if (sigma1 != 0) {
		double x = p1->getX() + sigma1 * p[1];
		double y = p1->getY() + sigma1 * p[3];
		p1->setX(x);
		p1->setY(y);
	}
	double sigma2 = this->sigma2(p, q);
	if (sigma1 > sigma2)
		return false;
	if (sigma2 != 1) {
		double x = p2->getX() + sigma2 * p[1];
		double y = p2->getY() + sigma2 * p[3];
		p2->setX(x);
		p2->setY(y);
	}
	return true;
}

double ClippingLiangBarsky::sigma1(int *p, int *q) const {
	double sigma = 0;
	for (int i = 0; i < 4; i++) {
		if (p[i] < 0) {
			double r = q[i] / p[i];
			if (r > sigma)
				sigma = r;
		}
	}
	return sigma;
}

double ClippingLiangBarsky::sigma2(int *p, int *q) const {
	double sigma = 1;
	for (int i = 0; i < 4; i++) {
		if (p[i] > 0) {
			double r = q[i] / p[i];
			if (r < sigma)
				sigma = r;
		}
	}
	return sigma;
}

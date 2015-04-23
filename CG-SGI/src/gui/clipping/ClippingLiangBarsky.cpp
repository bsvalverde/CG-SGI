#include "gui/clipping/ClippingLiangBarsky.h"
#include <iostream>

ClippingLiangBarsky::ClippingLiangBarsky(const double xvMin, const double xvMax,
		const double yvMin, const double yvMax) :
		Clipping(xvMin, xvMax, yvMin, yvMax) {
}

ClippingLiangBarsky::~ClippingLiangBarsky() {
}

QList<Ponto> ClippingLiangBarsky::clipReta(const Reta* const reta) const {
	QList<Ponto> pontos = reta->getPontos();
	Ponto p1 = pontos.at(0);
	Ponto p2 = pontos.at(1);

	double x1 = p1.getX();
	double y1 = p1.getY();
	double dX = p2.getX() - p1.getX();
	double dY = p2.getY() - p1.getY();

	double p[4] = { -dX, dX, -dY, dY };
	double q[4] = { x1 - xvMin,
					xvMax - x1,
					y1 - yvMin,
					yvMax - y1};

	double csi1 = this->csi1(p, q);
	double csi2 = this->csi2(p, q);

	if (csi1 > csi2) // Reta está fora da viewport
		return QList<Ponto>();

	if (csi1 != 0) {
		double x = x1 + csi1 * p[1];
		double y = y1 + csi1 * p[3];
		p1.setX(x);
		p1.setY(y);
	}

	if (csi2 != 1) {
		double x = x1 + csi2 * p[1];
		double y = y1 + csi2 * p[3];
		p2.setX(x);
		p2.setY(y);
	}
	pontos.clear();
	pontos.append(p1);
	pontos.append(p2);
	return pontos;
}

double ClippingLiangBarsky::csi1(double *p, double *q) const {
	double csi = 0;
	for (int i = 0; i < 4; i++) {
		if (p[i] < 0) {
			double r = q[i] / p[i];
			if (r > csi)
				csi = r;
		}
	}

	return csi;
}

double ClippingLiangBarsky::csi2(double *p, double *q) const {
	double csi = 1;
	for (int i = 0; i < 4; i++) {
		if (p[i] > 0) {
			double r = q[i] / p[i];
			if (r < csi)
				csi = r;
		}
	}

	return csi;
}

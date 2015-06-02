#include "geometria/SuperficieBSpline.h"

SuperficieBSpline::SuperficieBSpline() :
		Superficie() {
}

SuperficieBSpline::SuperficieBSpline(const SuperficieBSpline& superficie) :
		Superficie(superficie) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->pontos[i][j] = superficie.pontos[i][j];
		}
	}
	this->pontosParametricos = superficie.pontosParametricos;
}

SuperficieBSpline::SuperficieBSpline(const String& nome,
		const QList<Ponto>& pontos, const QColor& cor) :
		Superficie(nome, Tipo::SUPERFICIE_BSPLINE, cor) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->pontos[i][j] = pontos.at(i * 4 + j);
		}
	}
	this->calcularPontosParametricos();
}

SuperficieBSpline::~SuperficieBSpline() {
}

SuperficieBSpline& SuperficieBSpline::operator=(
		const SuperficieBSpline& superficie) {
	this->Superficie::operator =(superficie);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->pontos[i][j] = superficie.pontos[i][j];
		}
	}
	this->pontosParametricos = superficie.pontosParametricos;
	return *this;
}

ObjetoGeometrico* SuperficieBSpline::clonar() const {
	return new SuperficieBSpline(*this);
}

QList<Ponto> SuperficieBSpline::getPontos() const {
	QList<Ponto> pontos;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pontos.insert(i * 4 + j, this->pontos[i][j]);
		}
	}
	return pontos;
}

QList<Ponto*> SuperficieBSpline::getPontosObjeto() {
	QList<Ponto*> pontos;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pontos.insert(i * 4 + j, &this->pontos[i][j]);
		}
	}
	return pontos;
}

const String SuperficieBSpline::toString() const {
	String r = "[";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			r += this->pontos[i][j].toString();
			if (i != 4 && j != 4)
				r += ", ";
		}
	}
	r += "]";
	return r;
}

QList<QList<Ponto>> SuperficieBSpline::getPontosParametricos() const {
	return this->pontosParametricos;
}

void SuperficieBSpline::calcularPontosParametricos(const double t) {
	// TODO
}

QList<Ponto> SuperficieBSpline::geraCurva(double x1, double x2, double x3,
		double x4, double y1, double y2, double y3, double y4, double z1,
		double z2, double z3, double z4, double t) {
	QList<Ponto> pontos;
	double x[4] = { x1, x2, x3, x4 };
	double y[4] = { y1, y2, y3, y4 };
	double z[4] = { z1, z2, z3, z4 };
	pontos.append(Ponto("", x[0], y[0], z[0]));
	for (double i = 0; i < 1; i += t) {
		for (int j = 0; j < 3; j++) {
			x[j] += x[j + 1];
			y[j] += y[j + 1];
			z[j] += z[j + 1];
		}
		pontos.append(Ponto("", x[0], y[0], z[0]));
	}
	return pontos;
}

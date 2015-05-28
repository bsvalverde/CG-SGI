#include "geometria/SuperficieBezier.h"

SuperficieBezier::SuperficieBezier() :
		Superficie() {
}

SuperficieBezier::SuperficieBezier(const SuperficieBezier& superficie) :
		Superficie(superficie) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->pontos[i][j] = superficie.pontos[i][j];
		}
	}
	this->pontosParametricos = superficie.pontosParametricos;
}

SuperficieBezier::SuperficieBezier(const String& nome,
		const QList<Ponto>& pontos, const QColor& cor) :
		Superficie(nome, Tipo::SUPERFICIE_BEZIER, cor) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->pontos[i][j] = pontos.at(i * 4 + j);
		}
	}
	this->calcularPontosParametricos();
}

SuperficieBezier::~SuperficieBezier() {
}

SuperficieBezier& SuperficieBezier::operator=(
		const SuperficieBezier& superficie) {
	this->Superficie::operator =(superficie);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->pontos[i][j] = superficie.pontos[i][j];
		}
	}
	this->pontosParametricos = superficie.pontosParametricos;
	return *this;
}

ObjetoGeometrico* SuperficieBezier::clonar() const {
	return new SuperficieBezier(*this);
}

QList<Ponto> SuperficieBezier::getPontos() const {
	QList<Ponto> pontos;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 4; i++) {
			pontos.insert(i * 4 + j, this->pontos[i][j]);
		}
	}
	return pontos;
}

QList<Ponto*> SuperficieBezier::getPontosObjeto() {
	QList<Ponto*> pontos;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 4; i++) {
			pontos.insert(i * 4 + j, &this->pontos[i][j]);
		}
	}
	return pontos;
}

const String SuperficieBezier::toString() const {
	String r = "[";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 4; i++) {
			r += this->pontos[i][j].toString();
			if (i != 4 && j != 4)
				r += ", ";
		}
	}
	r += "]";
	return r;
}

QList<QList<Ponto>> SuperficieBezier::getPontosParametricos() const {
	return this->pontosParametricos;
}

void SuperficieBezier::calcularPontosParametricos(const double t) {
	double x[4][4];
	double y[4][4];
	double z[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			x[i][j] = pontos[i][j].getX();
			y[i][j] = pontos[i][j].getY();
			z[i][j] = pontos[i][j].getZ();
		}
	}

	pontosParametricos.clear();

	//calcular matrizes de coeficientes
	double bezier[4][4] = { { -1.0, 3.0, -3.0, 1.0 }, { 3.0, -6.0, 3.0, 0.0 }, {
			-3.0, 3.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0, 0.0 } };
	double coeficientesX[4][4];
	this->multiplicarMatrizes(bezier, x, coeficientesX);
	this->multiplicarMatrizes(coeficientesX, bezier, coeficientesX);
	double coeficientesY[4][4];
	this->multiplicarMatrizes(bezier, y, coeficientesY);
	this->multiplicarMatrizes(coeficientesY, bezier, coeficientesY);
	double coeficientesZ[4][4];
	this->multiplicarMatrizes(bezier, z, coeficientesZ);
	this->multiplicarMatrizes(coeficientesZ, bezier, coeficientesZ);

	//calcular matrizes de forward differences
	double dt[4][4] = { { 0.0, t * t * t, 6 * t * t * t, 6 * t * t * t }, { 0.0,
			t * t, 2 * t * t, 0.0 }, { 0.0, t, 0.0, 0.0 },
			{ 1.0, 0.0, 0.0, 0.0 } };
	double ds[4][4] = { { 0.0, 0.0, 0.0, 1.0 }, { t * t * t, t * t, t, 0.0 }, {
			6 * t * t * t, 2 * t * t, 0.0, 0.0 },
			{ 6 * t * t * t, 0.0, 0.0, 0.0 } };
	double fwdX[4][4];
	this->multiplicarMatrizes(ds, coeficientesX, fwdX);
	this->multiplicarMatrizes(fwdX, dt, fwdX);
	double fwdY[4][4];
	this->multiplicarMatrizes(ds, coeficientesY, fwdY);
	this->multiplicarMatrizes(fwdY, dt, fwdY);
	double fwdZ[4][4];
	this->multiplicarMatrizes(ds, coeficientesZ, fwdZ);
	this->multiplicarMatrizes(fwdZ, dt, fwdZ);

	//duplica e transpõe forward differences
	double fwdXs[4][4];
	double fwdYs[4][4];
	double fwdZs[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fwdXs[j][i] = fwdX[i][j];
			fwdYs[j][i] = fwdY[i][j];
			fwdZs[j][i] = fwdZ[i][j];
		}
	}

	//desenha curvas no sentido de t
	for (double i = 0; i < 1; i += t) {
		pontosParametricos.append(
				this->geraCurva(fwdX[0], fwdY[0], fwdZ[0], t));
		//atualiza forward differences
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				fwdX[i][j] += fwdX[i + 1][j];
				fwdY[i][j] += fwdY[i + 1][j];
				fwdZ[i][j] += fwdZ[i + 1][j];
			}
		}
	}

	//desenha curvas no sentido de s
	for (double i = 0; i < 1; i += t) {
		pontosParametricos.append(
				this->geraCurva(fwdXs[0], fwdYs[0], fwdZs[0], t));
		//atualiza forward differences
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				fwdXs[i][j] += fwdXs[i + 1][j];
				fwdYs[i][j] += fwdYs[i + 1][j];
				fwdZs[i][j] += fwdZs[i + 1][j];
			}
		}
	}
}

void SuperficieBezier::multiplicarMatrizes(double mat1[4][4], double mat2[4][4],
		double resultado[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			resultado[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				resultado[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

QList<Ponto> SuperficieBezier::geraCurva(double x[4], double y[4],
		double z[4], double t) {
	QList<Ponto> pontos;
	pontos.append(Ponto("", x[0], y[0], z[0]));
	for (int i = 0; i < 1; i += t) {
		for (int j = 0; j < 3; j++) {
			x[j] += x[j + 1];
			y[j] += y[j + 1];
			z[j] += z[j + 1];
		}
		pontos.append(Ponto("", x[0], y[0], z[0]));
	}
	return pontos;
}

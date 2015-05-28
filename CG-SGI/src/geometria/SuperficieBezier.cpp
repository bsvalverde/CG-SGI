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
	double x[4][4] = { { pontos[0][0].getX(), pontos[0][1].getX(),
			pontos[0][2].getX(), pontos[0][3].getX() }, { pontos[1][0].getX(),
			pontos[1][1].getX(), pontos[1][2].getX(), pontos[1][3].getX() }, {
			pontos[2][0].getX(), pontos[2][1].getX(), pontos[2][2].getX(),
			pontos[2][3].getX() }, { pontos[3][0].getX(), pontos[3][1].getX(),
			pontos[3][2].getX(), pontos[3][3].getX() } };
	double y[4][4] = { { pontos[0][0].getY(), pontos[0][1].getY(),
			pontos[0][2].getY(), pontos[0][3].getY() }, { pontos[1][0].getY(),
			pontos[1][1].getY(), pontos[1][2].getY(), pontos[1][3].getY() }, {
			pontos[2][0].getY(), pontos[2][1].getY(), pontos[2][2].getY(),
			pontos[2][3].getY() }, { pontos[3][0].getY(), pontos[3][1].getY(),
			pontos[3][2].getY(), pontos[3][3].getY() } };
	double z[4][4] = { { pontos[0][0].getZ(), pontos[0][1].getZ(),
			pontos[0][2].getZ(), pontos[0][3].getZ() }, { pontos[1][0].getZ(),
			pontos[1][1].getZ(), pontos[1][2].getZ(), pontos[1][3].getZ() }, {
			pontos[2][0].getZ(), pontos[2][1].getZ(), pontos[2][2].getZ(),
			pontos[2][3].getZ() }, { pontos[3][0].getZ(), pontos[3][1].getZ(),
			pontos[3][2].getZ(), pontos[3][3].getZ() } };

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

	//duplica forward differences p nao recalcular
	double fwdXt[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fwdXt[j][i] = fwdX[i][j];
		}
	}
	double fwdYt[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fwdYt[j][i] = fwdY[i][j];
		}
	}
	double fwdZt[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fwdZt[j][i] = fwdZ[i][j];
		}
	}

	//desenha curvas no sentido de t
	for (double i = 0; i < 1; i += t) {
		pontosParametricos.append(
				this->desenhaCurva(fwdX[0], fwdY[0], fwdZ[0], t));
		fwdX[0][0] += fwdX[1][0];
		fwdX[0][1] += fwdX[1][1];
		fwdX[0][2] += fwdX[1][2];
		fwdX[0][3] += fwdX[1][3];
		fwdY[0][0] += fwdY[1][0];
		fwdY[0][1] += fwdY[1][1];
		fwdY[0][2] += fwdY[1][2];
		fwdY[0][3] += fwdY[1][3];
		fwdZ[0][0] += fwdZ[1][0];
		fwdZ[0][1] += fwdZ[1][1];
		fwdZ[0][2] += fwdZ[1][2];
		fwdZ[0][3] += fwdZ[1][3];
		fwdX[0][0] += fwdX[2][0];
		fwdX[1][1] += fwdX[2][1];
		fwdX[1][2] += fwdX[2][2];
		fwdX[1][3] += fwdX[2][3];
		fwdY[1][0] += fwdY[2][0];
		fwdY[1][1] += fwdY[2][1];
		fwdY[1][2] += fwdY[2][2];
		fwdY[1][3] += fwdY[2][3];
		fwdZ[1][0] += fwdZ[2][0];
		fwdZ[1][1] += fwdZ[2][1];
		fwdZ[1][2] += fwdZ[2][2];
		fwdZ[1][3] += fwdZ[2][3];
		fwdX[2][0] += fwdX[3][0];
		fwdX[2][1] += fwdX[3][1];
		fwdX[2][2] += fwdX[3][2];
		fwdX[2][3] += fwdX[3][3];
		fwdY[2][0] += fwdY[3][0];
		fwdY[2][1] += fwdY[3][1];
		fwdY[2][2] += fwdY[3][2];
		fwdY[2][3] += fwdY[3][3];
		fwdZ[2][0] += fwdZ[3][0];
		fwdZ[2][1] += fwdZ[3][1];
		fwdZ[2][2] += fwdZ[3][2];
		fwdZ[2][3] += fwdZ[3][3];
	}
	//desenha curvas no sentido de s
	for (double i = 0; i < 1; i += t) {
		pontosParametricos.append(
				this->desenhaCurva(fwdXt[0], fwdYt[0], fwdZt[0], t));
		fwdXt[0][0] += fwdXt[1][0];
		fwdXt[0][1] += fwdXt[1][1];
		fwdXt[0][2] += fwdXt[1][2];
		fwdXt[0][3] += fwdXt[1][3];
		fwdYt[0][0] += fwdYt[1][0];
		fwdYt[0][1] += fwdYt[1][1];
		fwdYt[0][2] += fwdYt[1][2];
		fwdYt[0][3] += fwdYt[1][3];
		fwdZt[0][0] += fwdZt[1][0];
		fwdZt[0][1] += fwdZt[1][1];
		fwdZt[0][2] += fwdZt[1][2];
		fwdZt[0][3] += fwdZt[1][3];
		fwdXt[0][0] += fwdXt[2][0];
		fwdXt[1][1] += fwdXt[2][1];
		fwdXt[1][2] += fwdXt[2][2];
		fwdXt[1][3] += fwdXt[2][3];
		fwdYt[1][0] += fwdYt[2][0];
		fwdYt[1][1] += fwdYt[2][1];
		fwdYt[1][2] += fwdYt[2][2];
		fwdYt[1][3] += fwdYt[2][3];
		fwdZt[1][0] += fwdZt[2][0];
		fwdZt[1][1] += fwdZt[2][1];
		fwdZt[1][2] += fwdZt[2][2];
		fwdZt[1][3] += fwdZt[2][3];
		fwdXt[2][0] += fwdXt[3][0];
		fwdXt[2][1] += fwdXt[3][1];
		fwdXt[2][2] += fwdXt[3][2];
		fwdXt[2][3] += fwdXt[3][3];
		fwdYt[2][0] += fwdYt[3][0];
		fwdYt[2][1] += fwdYt[3][1];
		fwdYt[2][2] += fwdYt[3][2];
		fwdYt[2][3] += fwdYt[3][3];
		fwdZt[2][0] += fwdZt[3][0];
		fwdZt[2][1] += fwdZt[3][1];
		fwdZt[2][2] += fwdZt[3][2];
		fwdZt[2][3] += fwdZt[3][3];
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

QList<Ponto> SuperficieBezier::desenhaCurva(double x[4], double y[4],
		double z[4], double t) {
	QList<Ponto> pontos;
	pontos.append(Ponto("", x[0], y[0], z[0]));
	for (int i = t; i < 1; i += t) {
		x[0] += x[1];
		x[1] += x[2];
		x[2] += x[3];
		y[0] += y[1];
		y[1] += y[2];
		y[2] += y[3];
		z[0] += z[1];
		z[1] += z[2];
		z[2] += z[3];
		pontos.append(Ponto("", x[0], y[0], z[0]));
	}
	return pontos;
}

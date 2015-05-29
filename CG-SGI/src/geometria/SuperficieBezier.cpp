#include "geometria/SuperficieBezier.h"
#include <iostream>

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
		for (int j = 0; j < 4; j++) {
			pontos.insert(i * 4 + j, this->pontos[i][j]);
		}
	}
	return pontos;
}

QList<Ponto*> SuperficieBezier::getPontosObjeto() {
	QList<Ponto*> pontos;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pontos.insert(i * 4 + j, &this->pontos[i][j]);
		}
	}
	return pontos;
}

const String SuperficieBezier::toString() const {
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

QList<QList<Ponto>> SuperficieBezier::getPontosParametricos() const {
	for (int i = 0; i < pontosParametricos.size(); i++) {
		for (int j = 0; j < pontosParametricos.at(i).size(); j++) {
			std::cout << pontosParametricos.at(i).at(j).toString() << std::endl;
		}
	}
	return this->pontosParametricos;
}

void SuperficieBezier::calcularPontosParametricos(const double t) {
	double** x = new double*[4];
	double** y = new double*[4];
	double** z = new double*[4];

	for (int i = 0; i < 4; i++) {
		x[i] = new double[4];
		y[i] = new double[4];
		z[i] = new double[4];

		for (int j = 0; j < 4; j++) {
			x[i][j] = pontos[i][j].getX();
			y[i][j] = pontos[i][j].getY();
			z[i][j] = pontos[i][j].getZ();
		}
	}
	pontosParametricos.clear();

	//calcular matrizes de coeficientes
	double** bezier = new double*[4];
	double** coeficientesX = new double*[4];
	double** coeficientesY = new double*[4];
	double** coeficientesZ = new double*[4];

	for (int i = 0; i < 4; i++) {
		bezier[i] = new double[4];
		coeficientesX[i] = new double[4];
		coeficientesY[i] = new double[4];
		coeficientesZ[i] = new double[4];
	}

	bezier[0][0] = -1; bezier[0][1] = 3; bezier[0][2] = -3; bezier[0][3] = 1;
	bezier[1][0] = 3; bezier[1][1] = -6; bezier[1][2] = 3; bezier[1][3] = 0;
	bezier[2][0] = -3; bezier[2][1] = 3; bezier[2][2] = 0; bezier[2][3] = 0;
	bezier[3][0] = 1; bezier[3][1] = 0; bezier[3][2] = 0; bezier[3][3] = 0;

	this->multiplicarMatrizes(bezier, x, coeficientesX);
	this->multiplicarMatrizes(coeficientesX, bezier, coeficientesX);
	this->multiplicarMatrizes(bezier, y, coeficientesY);
	this->multiplicarMatrizes(coeficientesY, bezier, coeficientesY);
	this->multiplicarMatrizes(bezier, z, coeficientesZ);
	this->multiplicarMatrizes(coeficientesZ, bezier, coeficientesZ);

	double** ds = new double*[4];
	double** dt = new double*[4];
	double** fwdX = new double*[4];
	double** fwdY = new double*[4];
	double** fwdZ = new double*[4];

	for (int i = 0; i < 4; i++) {
		ds[i] = new double[4];
		dt[i] = new double[4];
		fwdX[i] = new double[4];
		fwdY[i] = new double[4];
		fwdZ[i] = new double[4];
	}

	//calcular matrizes de forward differences
	dt[0][0] = 0; dt[0][1] = t * t * t; dt[0][2] = 6 * t * t * t; dt[0][3] = 6 * t * t * t;
	dt[1][0] = 0; dt[1][1] = t * t; dt[1][2] = 2 * t * t; dt[1][3] = 0;
	dt[2][0] = 0; dt[2][1] = t; dt[2][2] = 0; dt[2][3] = 0;
	dt[3][0] = 1; dt[3][1] = 0; dt[3][2] = 0; dt[3][3] = 0;

	ds[0][0] = 0; ds[0][1] = 0; ds[0][2] = 0; ds[0][3] = 1;
	ds[1][0] = t * t * t; ds[1][1] = t * t; ds[1][2] = t; ds[1][3] = 0;
	ds[2][0] = 6 * t * t * t; ds[2][1] = 2 * t * t; ds[2][2] = 0; ds[2][3] = 0;
	ds[3][0] = 6 * t * t * t; ds[3][1] = 0; ds[3][2] = 0; ds[3][3] = 0;

	this->multiplicarMatrizes(ds, coeficientesX, coeficientesX);
	this->multiplicarMatrizes(coeficientesX, dt, fwdX);
	this->multiplicarMatrizes(ds, coeficientesY, coeficientesY);
	this->multiplicarMatrizes(coeficientesY, dt, fwdY);
	this->multiplicarMatrizes(ds, coeficientesZ, coeficientesZ);
	this->multiplicarMatrizes(coeficientesZ, dt, fwdZ);

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
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 4; b++) {
				fwdX[a][b] += fwdX[a + 1][b];
				fwdY[a][b] += fwdY[a + 1][b];
				fwdZ[a][b] += fwdZ[a + 1][b];
			}
		}
	}

	//desenha curvas no sentido de s
	for (double i = 0; i < 1; i += t) {
		pontosParametricos.append(
				this->geraCurva(fwdXs[0], fwdYs[0], fwdZs[0], t));
		//atualiza forward differences
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 4; b++) {
				fwdXs[a][b] += fwdXs[a + 1][b];
				fwdYs[a][b] += fwdYs[a + 1][b];
				fwdZs[a][b] += fwdZs[a + 1][b];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		delete bezier[i];
		delete coeficientesX[i];
		delete coeficientesY[i];
		delete coeficientesZ[i];
		delete ds[i];
		delete dt[i];
		delete fwdX[i];
		delete fwdY[i];
		delete fwdZ[i];
	}

	delete bezier;
	delete coeficientesX;
	delete coeficientesY;
	delete coeficientesZ;
	delete ds;
	delete dt;
	delete fwdX;
	delete fwdY;
	delete fwdZ;
}

void SuperficieBezier::multiplicarMatrizes(double** mat1, double** mat2,
		double** resultado) {
	double buffer[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				buffer[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			resultado[i][j] = buffer[i][j];
		}
	}
}

QList<Ponto> SuperficieBezier::geraCurva(double x[4], double y[4], double z[4],
		double t) {
	QList<Ponto> pontos;
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

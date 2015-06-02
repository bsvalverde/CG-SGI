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
	double bufferX[4][4];
	double bufferY[4][4];
	double bufferZ[4][4];

	for (int i = 0; i < 4; i++) {
		bufferX[0][i] = -x[0][i] + 3 * x[1][i] - 3 * x[2][i] + x[3][i];
		bufferX[1][i] = 3 * x[0][i] - 6 * x[1][i] + 3 * x[2][i];
		bufferX[2][i] = -3 * x[0][i] + 3 * x[1][i];
		bufferX[3][i] = x[0][i];
		bufferY[0][i] = -y[0][i] + 3 * y[1][i] - 3 * y[2][i] + y[3][i];
		bufferY[1][i] = 3 * y[0][i] - 6 * y[1][i] + 3 * y[2][i];
		bufferY[2][i] = -3 * y[0][i] + 3 * y[1][i];
		bufferY[3][i] = y[0][i];
		bufferZ[0][i] = -z[0][i] + 3 * z[1][i] - 3 * z[2][i] + z[3][i];
		bufferZ[1][i] = 3 * z[0][i] - 6 * z[1][i] + 3 * z[2][i];
		bufferZ[2][i] = -3 * z[0][i] + 3 * z[1][i];
		bufferZ[3][i] = z[0][i];
	}
	double cX[4][4];
	double cY[4][4];
	double cZ[4][4];
	for (int i = 0; i < 4; i++) {
		cX[i][0] = -bufferX[i][0] + 3 * bufferX[i][1] - 3 * bufferX[i][2]
				+ bufferX[i][3];
		cX[i][1] = 3 * bufferX[i][0] - 6 * bufferX[i][1] + 3 * bufferX[i][2];
		cX[i][2] = -3 * bufferX[i][9] + 3 * bufferX[i][1];
		cX[i][3] = bufferX[i][0];
		cY[i][0] = -bufferY[i][0] + 3 * bufferY[i][1] - 3 * bufferY[i][2]
				+ bufferY[i][3];
		cY[i][1] = 3 * bufferY[i][0] - 6 * bufferY[i][1] + 3 * bufferY[i][2];
		cY[i][2] = -3 * bufferY[i][9] + 3 * bufferY[i][1];
		cY[i][3] = bufferY[i][0];
		cZ[i][0] = -bufferZ[i][0] + 3 * bufferZ[i][1] - 3 * bufferZ[i][2]
				+ bufferZ[i][3];
		cZ[i][1] = 3 * bufferZ[i][0] - 6 * bufferZ[i][1] + 3 * bufferZ[i][2];
		cZ[i][2] = -3 * bufferZ[i][9] + 3 * bufferZ[i][1];
		cZ[i][3] = bufferZ[i][0];
	}

	//calcular matrizes de forward differences
	for (int i = 0; i < 4; i++) {
		bufferX[0][i] = cX[3][i];
		bufferX[1][i] = t * t * t * cX[0][i] + t * t * cX[1][i] + t * cX[2][i];
		bufferX[2][i] = 6 * t * t * t * cX[0][i] + 2 * t * t * cX[1][i];
		bufferX[3][i] = 6 * t * t * t * cX[0][i];
		bufferY[0][i] = cY[3][i];
		bufferY[1][i] = t * t * t * cY[0][i] + t * t * cY[1][i] + t * cY[2][i];
		bufferY[2][i] = 6 * t * t * t * cY[0][i] + 2 * t * t * cY[1][i];
		bufferY[3][i] = 6 * t * t * t * cY[0][i];
		bufferZ[0][i] = cZ[3][i];
		bufferZ[1][i] = t * t * t * cZ[0][i] + t * t * cZ[1][i] + t * cZ[2][i];
		bufferZ[2][i] = 6 * t * t * t * cZ[0][i] + 2 * t * t * cZ[1][i];
		bufferZ[3][i] = 6 * t * t * t * cZ[0][i];
	}

	double fX[4][4];
	double fY[4][4];
	double fZ[4][4];
	for (int i = 0; i < 4; i++) {
		fX[i][0] = bufferX[i][3];
		fX[i][1] = t * t * t * bufferX[i][0] + t * t * bufferX[i][1]
				+ t * bufferX[i][2];
		fX[i][2] = 6 * t * t * t * bufferX[i][0] + 2 * t * t * bufferX[i][1];
		fX[i][3] = 6 * t * t * t * bufferX[i][0];
		fY[i][0] = bufferY[i][3];
		fY[i][1] = t * t * t * bufferY[i][0] + t * t * bufferY[i][1]
				+ t * bufferY[i][2];
		fY[i][2] = 6 * t * t * t * bufferY[i][0] + 2 * t * t * bufferY[i][1];
		fY[i][3] = 6 * t * t * t * bufferY[i][0];
		fZ[i][0] = bufferZ[i][3];
		fZ[i][1] = t * t * t * bufferZ[i][0] + t * t * bufferZ[i][1]
				+ t * bufferZ[i][2];
		fZ[i][2] = 6 * t * t * t * bufferZ[i][0] + 2 * t * t * bufferZ[i][1];
		fZ[i][3] = 6 * t * t * t * bufferZ[i][0];
	}

	//duplica e transpõe forward differences
	double fXs[4][4];
	double fYs[4][4];
	double fZs[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fXs[j][i] = fX[i][j];
			fYs[j][i] = fY[i][j];
			fZs[j][i] = fZ[i][j];
		}
	}

	//desenha curvas no sentido de t
	for (double i = 0; i < 1; i += t) {
		pontosParametricos.append(
				this->gerarCurva(fX[0][0], fX[0][1], fX[0][2], fX[0][3],
						fY[0][0], fY[0][1], fY[0][2], fY[0][3], fZ[0][0],
						fZ[0][1], fZ[0][2], fZ[0][3], t));
		//atualiza forward differences
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 4; b++) {
				fX[a][b] += fX[a + 1][b];
				fY[a][b] += fY[a + 1][b];
				fZ[a][b] += fZ[a + 1][b];
			}
		}
	}

	//desenha curvas no sentido de s
	for (double i = 0; i < 1; i += t) {
		pontosParametricos.append(
				this->gerarCurva(fXs[0][0], fXs[0][1], fXs[0][2], fXs[0][3],
						fYs[0][0], fYs[0][1], fYs[0][2], fYs[0][3], fZs[0][0],
						fZs[0][1], fZs[0][2], fZs[0][3], t));
		//atualiza forward differences
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 4; b++) {
				fXs[a][b] += fXs[a + 1][b];
				fYs[a][b] += fYs[a + 1][b];
				fZs[a][b] += fZs[a + 1][b];
			}
		}
	}
}

QList<Ponto> SuperficieBezier::gerarCurva(double x1, double x2, double x3,
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

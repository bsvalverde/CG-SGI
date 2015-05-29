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
	double coefX[4][4];
	double coefY[4][4];
	double coefZ[4][4];

	for (int i = 0; i < 4; i++) {
		coefX[0][i] = -x[0][i] + 3 * x[1][i] - 3 * x[2][i] + x[3][i];
		coefX[1][i] = 3 * x[0][i] - 6 * x[1][i] + 3 * x[2][i];
		coefX[2][i] = -3 * x[0][i] + 3 * x[1][i];
		coefX[3][i] = x[0][i];
		coefY[0][i] = -y[0][i] + 3 * y[1][i] - 3 * y[2][i] + y[3][i];
		coefY[1][i] = 3 * y[0][i] - 6 * y[1][i] + 3 * y[2][i];
		coefY[2][i] = -3 * y[0][i] + 3 * y[1][i];
		coefY[3][i] = y[0][i];
		coefZ[0][i] = -z[0][i] + 3 * z[1][i] - 3 * z[2][i] + z[3][i];
		coefZ[1][i] = 3 * z[0][i] - 6 * z[1][i] + 3 * z[2][i];
		coefZ[2][i] = -3 * z[0][i] + 3 * z[1][i];
		coefZ[3][i] = z[0][i];
	}
	double cX[4][4];
	double cY[4][4];
	double cZ[4][4];
	for (int i = 0; i < 4; i++) {
		cX[i][0] = -coefX[i][0] + 3 * coefX[i][1] - 3 * coefX[i][2]
				+ coefX[i][3];
		cX[i][1] = 3 * coefX[i][0] - 6 * coefX[i][1] + 3 * coefX[i][2];
		cX[i][2] = -3 * coefX[i][9] + 3 * coefX[i][1];
		cX[i][3] = coefX[i][0];
		cY[i][0] = -coefY[i][0] + 3 * coefY[i][1] - 3 * coefY[i][2]
				+ coefY[i][3];
		cY[i][1] = 3 * coefY[i][0] - 6 * coefY[i][1] + 3 * coefY[i][2];
		cY[i][2] = -3 * coefY[i][9] + 3 * coefY[i][1];
		cY[i][3] = coefY[i][0];
		cZ[i][0] = -coefZ[i][0] + 3 * coefZ[i][1] - 3 * coefZ[i][2]
				+ coefZ[i][3];
		cZ[i][1] = 3 * coefZ[i][0] - 6 * coefZ[i][1] + 3 * coefZ[i][2];
		cZ[i][2] = -3 * coefZ[i][9] + 3 * coefZ[i][1];
		cZ[i][3] = coefZ[i][0];
	}

	//calcular matrizes de forward differences
	double fwdX[4][4];
	double fwdY[4][4];
	double fwdZ[4][4];
	for (int i = 0; i < 4; i++) {
		fwdX[0][i] = cX[3][i];
		fwdX[1][i] = t * t * t * cX[0][i] + t * t * cX[1][i] + t * cX[2][i];
		fwdX[2][i] = 6 * t * t * t * cX[0][i] + 2 * t * t * cX[1][i];
		fwdX[3][i] = 6 * t * t * t * cX[0][i];
		fwdY[0][i] = cY[3][i];
		fwdY[1][i] = t * t * t * cY[0][i] + t * t * cY[1][i] + t * cY[2][i];
		fwdY[2][i] = 6 * t * t * t * cY[0][i] + 2 * t * t * cY[1][i];
		fwdY[3][i] = 6 * t * t * t * cY[0][i];
		fwdZ[0][i] = cZ[3][i];
		fwdZ[1][i] = t * t * t * cZ[0][i] + t * t * cZ[1][i] + t * cZ[2][i];
		fwdZ[2][i] = 6 * t * t * t * cZ[0][i] + 2 * t * t * cZ[1][i];
		fwdZ[3][i] = 6 * t * t * t * cZ[0][i];
	}

	double fX[4][4];
	double fY[4][4];
	double fZ[4][4];
	for (int i = 0; i < 4; i++) {
		fX[i][0] = fwdX[i][3];
		fX[i][1] = t * t * t * fwdX[i][0] + t * t * fwdX[i][1] + t * fwdX[i][2];
		fX[i][2] = 6 * t * t * t * fwdX[i][0] + 2 * t * t * fwdX[i][1];
		fX[i][3] = 6 * t * t * t * fwdX[i][0];
		fY[i][0] = fwdY[i][3];
		fY[i][1] = t * t * t * fwdY[i][0] + t * t * fwdY[i][1] + t * fwdY[i][2];
		fY[i][2] = 6 * t * t * t * fwdY[i][0] + 2 * t * t * fwdY[i][1];
		fY[i][3] = 6 * t * t * t * fwdY[i][0];
		fZ[i][0] = fwdZ[i][3];
		fZ[i][1] = t * t * t * fwdZ[i][0] + t * t * fwdZ[i][1] + t * fwdZ[i][2];
		fZ[i][2] = 6 * t * t * t * fwdZ[i][0] + 2 * t * t * fwdZ[i][1];
		fZ[i][3] = 6 * t * t * t * fwdZ[i][0];
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
		pontosParametricos.append(this->geraCurva(fX[0], fY[0], fZ[0], t));
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
		pontosParametricos.append(this->geraCurva(fXs[0], fYs[0], fZs[0], t));
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

#include "geometria/CurvaBSpline.h"
#include <iostream>
CurvaBSpline::CurvaBSpline() :
		ObjetoGeometrico() {
	this->pontosParametricosRedefinidos = false;
}

CurvaBSpline::CurvaBSpline(const CurvaBSpline& curva) :
		ObjetoGeometrico(curva) {
	for (int i = 0; i < curva.pontos.size(); i++)
		this->pontos.insert(i, curva.pontos.at(i));
	this->pontosParametricos = curva.pontosParametricos;
	this->pontosParametricosRedefinidos = curva.pontosParametricosRedefinidos;
}

CurvaBSpline::CurvaBSpline(const String& nome, const QList<Ponto>& pontos,
		const QColor& cor) :
		ObjetoGeometrico(nome, Tipo::CURVA_BSPLINE, cor) {
	for (int i = 0; i < pontos.size(); i++)
		this->pontos.insert(i, pontos.at(i));
	this->pontosParametricos = this->calcularPontosParametricos();
	this->pontosParametricosRedefinidos = false;
}

CurvaBSpline::~CurvaBSpline() {}

CurvaBSpline& CurvaBSpline::operator=(const CurvaBSpline& curva) {
	this->ObjetoGeometrico::operator =(curva);
	this->pontos.clear();
	for (int i = 0; i < curva.pontos.size(); i++)
		this->pontos.insert(i, curva.pontos.at(i));
	this->pontosParametricos = curva.pontosParametricos;
	this->pontosParametricosRedefinidos = curva.pontosParametricosRedefinidos;
	return *this;
}

ObjetoGeometrico* CurvaBSpline::clonar() const {
	return new CurvaBSpline(*this);
}

QList<Ponto> CurvaBSpline::getPontos() const {
	if (!this->pontosParametricosRedefinidos)
		return this->calcularPontosParametricos();
	std::cout << this->pontosParametricos.size() << std::endl;
	return this->pontosParametricos;
}

QList<Ponto*> CurvaBSpline::getPontosObjeto() {
	QList<Ponto*> lista;

	for (int i = 0; i < this->pontos.size(); i++)
		lista.insert(i, (Ponto*) &this->pontos.at(i));

	return lista;
}

const String CurvaBSpline::toString() const {
	String retorno = "[" + this->pontos.at(0).toString();
	for (int i = 1; i < this->pontos.size(); i++) {
		retorno += ", " + this->pontos.at(i).toString();
	}
	retorno += "]";
	return retorno;
}

void CurvaBSpline::setPontosParametricos(const QList<Ponto>& pontos) {
	this->pontosParametricos = pontos;
	this->pontosParametricosRedefinidos = true;
}

QList<Ponto> CurvaBSpline::calcularPontosParametricos(const double t) const {
	QList<Ponto> pontos;
	int tam = this->pontos.size();

	// Calcular os pontos do segmento Qm (m-3 ... m)
	for (int m = 3; m < tam; m++) {
		Ponto p[4] = { this->pontos.at(m-3), this->pontos.at(m-2),
					   this->pontos.at(m-1), this->pontos.at(m) };
		QList<Ponto> novosPontos =
				this->calcularPontosParametricosIntermediario(p, t);
		for (int i = 0; i < novosPontos.size(); i++)
			pontos.insert(pontos.size(), novosPontos.at(i));
	}

//	*** NÃO ENTENDI O PQ DISSO ***

//	//pega os últimos 4 pontos para calcular a parte final da reta
//
//	Ponto p[4] = { this->pontos.at(tam - 4), this->pontos.at(tam - 3),
//			this->pontos.at(tam - 2), this->pontos.at(tam - 1) };
//	QList<Ponto> novosPontos = this->calcularPontosParametricosIntermediario(p,
//			t, 3);
//	for (int j = 0; j < novosPontos.size(); j++) {
//		pontos.insert(pontos.size(), novosPontos.at(j));
//	}

	/**
	 * Mbs
		1/6 x
		-1	3	-3	1
		3	-6	3	0
		-3	0	3	0
		1	3	1	0

		Mbs-1
		0	2/3	-1	1
		0	-1/3	0	1
		0	2/3	1	1
		6	11/3	2	1

		a = 2/3*p[1] - p[2] + p[3]
		b = -1/3*p[1] + p[3]
		c = 2/3*p[1] + p[2] + p[3]
		d = 6*p[0] + 11/3*p[1] + 2*p[2] + p[3]

	 */

	return pontos;
}

QList<Ponto> CurvaBSpline::calcularPontosParametricosIntermediario(Ponto *p, const double t) const {

	// Cálculo dos coeficientes (a, b, c, d)
	double p0[3] = { p[0].getX(), p[0].getY(), p[0].getZ() };
	double p1[3] = { p[1].getX(), p[1].getY(), p[1].getZ() };
	double p2[3] = { p[2].getX(), p[2].getY(), p[2].getZ() };
	double p3[3] = { p[3].getX(), p[3].getY(), p[3].getZ() };

	double cfA[3] = { 0, 0, 0 };
	double cfB[3] = { 0, 0, 0 };
	double cfC[3] = { 0, 0, 0 };
	double cfD[3] = { 0, 0, 0 };

	for(int i = 0; i < 4; i++) {
		cfA[i] = (2/3)*p1[i] - p2[i] + p3[i];
		cfB[i] = -(1/3)*p1[i] + p3[i];
		cfC[i] = (2/3)*p1[i] + p2[i] + p3[i];
		cfD[i] = 6*p0[i] + (11/3)*p1[i] + 2*p2[i] + p3[i];
	}

	// Cálculo das diferenças iniciais (f0, df0, d²f0, d³f0)
	double dt = t;
	double dt2 = pow(t, 2);
	double dt3 = pow(t, 3);

	double dInicialX[4] = { cfD[0],
							dt3*cfA[0] + dt2*cfB[0] + cfC[0],
							6*dt3*cfA[0] + 2*dt2*cfB[0],
							6*dt3*cfA[0] };
	double dInicialY[4] = { cfD[1],
							dt3*cfA[1] + dt2*cfB[1] + cfC[1],
							6*dt3*cfA[1] + 2*dt2*cfB[1],
							6*dt3*cfA[1] };
	double dInicialZ[4] = { cfD[2],
							dt3*cfA[2] + dt2*cfB[2] + cfC[2],
							6*dt3*cfA[2] + 2*dt2*cfB[2],
							6*dt3*cfA[2] };

	QList<Ponto> pontos;
	pontos.insert(0, Ponto("", 0, 0, 0));
	double n = 1/t;

	for(int i = 0; i < n; i++) {

	}

	while (x[0] < p[n].getX()) {
		x[0] += deltaX;
		deltaX += delta2X;
		delta2X += delta3X;
		y[0] += deltaY;
		deltaY += delta2Y;
		delta2Y += delta3Y;
		z[0] += deltaZ;
		deltaZ += delta2Z;
		delta2Z += delta3Z;
		pontos.insert(pontos.size(), Ponto("", x[0], y[0], z[0]));
	}
	return this->pontos;
}

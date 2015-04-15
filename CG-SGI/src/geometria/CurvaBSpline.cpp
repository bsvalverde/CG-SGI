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
	QList<Ponto> pontosParam;
	int tam = this->pontos.size();

	// Calcular os pontos do segmento Qm (m-3 ... m)
	for (int m = 3; m < tam; m++) {
		Ponto p[4] = { this->pontos.at(m-3), this->pontos.at(m-2),
					   this->pontos.at(m-1), this->pontos.at(m) };
		QList<Ponto> novosPontos =
				this->calcularPontosParametricosIntermediario(p, t);

		for (Ponto p : novosPontos)
			pontosParam.insert(pontosParam.size(), p);
	}

	return pontosParam;
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

	for(int i = 0; i < 3; i++) {
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
							dt3*cfA[0] + dt2*cfB[0] + dt*cfC[0],
							6*dt3*cfA[0] + 2*dt2*cfB[0],
							6*dt3*cfA[0] };
	double dInicialY[4] = { cfD[1],
							dt3*cfA[1] + dt2*cfB[1] + dt*cfC[1],
							6*dt3*cfA[1] + 2*dt2*cfB[1],
							6*dt3*cfA[1] };
	double dInicialZ[4] = { cfD[2],
							dt3*cfA[2] + dt2*cfB[2] + dt*cfC[2],
							6*dt3*cfA[2] + 2*dt2*cfB[2],
							6*dt3*cfA[2] };

	// Cálculo dos pontos paramétricos
	QList<Ponto> pontosParam;
	pontosParam.insert(0, Ponto("", dInicialX[0], dInicialY[0], dInicialZ[0]));
	double n = 1/t;

	for(int i = 1; i < n; i++) {
		dInicialX[0] += dInicialX[1];
		dInicialY[0] += dInicialY[1];
		dInicialZ[0] += dInicialZ[1];
		dInicialX[1] += dInicialX[2];
		dInicialY[1] += dInicialY[2];
		dInicialZ[1] += dInicialZ[2];
		dInicialX[2] += dInicialX[3];
		dInicialY[2] += dInicialY[3];
		dInicialZ[2] += dInicialZ[3];

		pontosParam.insert(i, Ponto("", dInicialX[0], dInicialY[0], dInicialZ[0]));
	}

	return pontosParam;
}

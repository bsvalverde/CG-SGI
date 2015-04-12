#include "geometria/CurvaBezier.h"

CurvaBezier::CurvaBezier() : ObjetoGeometrico() {
	this->pontosParametricosRedefinidos = false;
}

CurvaBezier::CurvaBezier(const CurvaBezier& curva) : ObjetoGeometrico(curva) {
	this->p1 = curva.p1;
	this->p2 = curva.p2;
	this->p3 = curva.p3;
	this->p4 = curva.p4;
	this->pontosParametricos = curva.pontosParametricos;
	this->pontosParametricosRedefinidos = curva.pontosParametricosRedefinidos;
}

CurvaBezier::CurvaBezier(const String& nome, const Ponto& p1, const Ponto& p2,
		const Ponto& p3, const Ponto& p4, const QColor& cor) : ObjetoGeometrico(nome, Tipo::CURVA_BEZIER, cor) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->pontosParametricos = this->calcularPontosParametricos();
	this->pontosParametricosRedefinidos = false;
}

CurvaBezier::~CurvaBezier() {}

CurvaBezier& CurvaBezier::operator=(const CurvaBezier& curva) {
	this->ObjetoGeometrico::operator =(curva);
	this->p1 = curva.p1;
	this->p2 = curva.p2;
	this->p3 = curva.p3;
	this->p4 = curva.p4;
	this->pontosParametricos = curva.pontosParametricos;
	this->pontosParametricosRedefinidos = curva.pontosParametricosRedefinidos;
	return *this;
}

ObjetoGeometrico* CurvaBezier::clonar() const {
	return new CurvaBezier(*this);
}

QList<Ponto> CurvaBezier::getPontos() const {
	if(!this->pontosParametricosRedefinidos)
		return this->calcularPontosParametricos();

	return this->pontosParametricos;
}

QList<Ponto*> CurvaBezier::getPontosObjeto() {
	QList<Ponto*> pontos;
	pontos.insert(0, &this->p1);
	pontos.insert(1, &this->p2);
	pontos.insert(2, &this->p3);
	pontos.insert(3, &this->p4);
	return pontos;
}

const String CurvaBezier::toString() const {
	return "[" + this->p1.toString() + ", " +
			this->p2.toString() + ", " +
			this->p3.toString() + ", " +
			this->p4.toString() + "]";
}

void CurvaBezier::setPontosParametricos(const QList<Ponto>& pontos) {
	this->pontosParametricos = pontos;
	this->pontosParametricosRedefinidos = true;
}

QList<Ponto> CurvaBezier::calcularPontosParametricos(const double t) const {
	QList<Ponto> pontos;
	double x[4] = {p1.getX(), p2.getX(), p3.getX(), p4.getX()};
	double y[4] = {p1.getY(), p2.getY(), p3.getY(), p4.getY()};
	double z[4] = {p1.getZ(), p2.getZ(), p3.getZ(), p4.getZ()};

	pontos.insert(0, this->p1);
	for(double i = t; i < 1; i += t) {
		double i3 = pow(i, 3);
		double i2 = pow(i, 2);

		double xi = -x[0]*i3 + 3*x[1]*i3 - 3*x[2]*i3 + x[3]*i3 +
					3*x[0]*i2 - 6*x[1]*i2 + 3*x[2]*i2 +
					-3*x[0]*i + 3*x[1]*i + x[0];
		double yi = -y[0]*i3 + 3*y[1]*i3 - 3*y[2]*i3 + y[3]*i3 +
					3*y[0]*i2 - 6*y[1]*i2 + 3*y[2]*i2 +
					-3*y[0]*i + 3*y[1]*i + y[0];
		double zi = -z[0]*i3 + 3*z[1]*i3 - 3*z[2]*i3 + z[3]*i3 +
					3*z[0]*i2 - 6*z[1]*i2 + 3*z[2]*i2 +
					-3*z[0]*i + 3*z[1]*i + z[0];

		pontos.insert(pontos.size(), Ponto("", xi, yi, zi));
	}
	pontos.insert(pontos.size(), this->p4);
	return pontos;
}

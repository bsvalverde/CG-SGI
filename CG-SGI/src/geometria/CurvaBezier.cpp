#include "geometria/CurvaBezier.h"

CurvaBezier::CurvaBezier() : ObjetoGeometrico() {}

CurvaBezier::CurvaBezier(const CurvaBezier& curva) : ObjetoGeometrico(curva) {}

CurvaBezier::CurvaBezier(const String& nome, const Ponto& p1, const Ponto& p2,
		const Ponto& p3, const Ponto& p4, const QColor& cor) : ObjetoGeometrico(nome, Tipo::CURVA_BEZIER, cor) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
}

CurvaBezier::~CurvaBezier() {}

CurvaBezier& CurvaBezier::operator=(const CurvaBezier& curva) {
	this->ObjetoGeometrico::operator =(curva);
	this->p1 = curva.p1;
	this->p2 = curva.p2;
	this->p3 = curva.p3;
	this->p4 = curva.p4;
	return *this;
}

ObjetoGeometrico* CurvaBezier::clonar() const {
	return new CurvaBezier(*this);
}

QList<Ponto> CurvaBezier::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, this->p1);
	pontos.insert(1, this->p2);
	pontos.insert(2, this->p3);
	pontos.insert(3, this->p4);
	return pontos;
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

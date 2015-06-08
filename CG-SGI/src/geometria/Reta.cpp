#include "geometria/Reta.h"

Reta::Reta() :
		ObjetoGeometrico() {
}

Reta::Reta(const Reta& reta) :
		ObjetoGeometrico(reta) {
	this->v_inicial = reta.v_inicial;
	this->v_final = reta.v_final;
}

Reta::Reta(const String& nome, const Ponto& inicial, const Ponto& final,
		const QColor& cor) :
		ObjetoGeometrico(nome, Tipo::RETA, cor) {
	this->v_inicial = inicial;
	this->v_final = final;
}

Reta::~Reta() {
}

Reta& Reta::operator=(const Reta& reta) {
	this->ObjetoGeometrico::operator =(reta);
	this->v_inicial = reta.v_inicial;
	this->v_final = reta.v_final;
	return *this;
}

ObjetoGeometrico* Reta::clonar() const {
	return new Reta(*this);
}

QList<Ponto> Reta::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, this->v_inicial);
	pontos.insert(1, this->v_final);
	return pontos;
}

QList<Ponto*> Reta::getPontosObjeto() {
	QList<Ponto*> pontos;
	pontos.insert(0, &this->v_inicial);
	pontos.insert(1, &this->v_final);
	return pontos;
}

const String Reta::toString() const {
	return "[" + this->v_inicial.toString() + ", " + this->v_final.toString()
			+ "]";
}

double Reta::coeficienteAngular() const {
	return (this->v_final.getY() - this->v_inicial.getY())
			/ (this->v_final.getX() - this->v_inicial.getX());
}

double Reta::coeficienteAngularZ() const {
	return (this->v_final.getY() - this->v_inicial.getY())
			/ (this->v_final.getZ() - this->v_inicial.getZ());
}


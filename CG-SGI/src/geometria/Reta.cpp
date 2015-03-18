#include "geometria/Reta.h"

Reta::Reta(const String& nome, const Ponto& inicial, const Ponto& final) :
			ObjetoGeometrico(nome, Tipo::RETA) {
	this->v_inicial = inicial;
	this->v_final = final;
}

Reta::~Reta() {}

QList<Ponto> Reta::getPontos() {
	QList<Ponto> pontos;
	pontos.insert(0, this->v_inicial);
	pontos.insert(1, this->v_final);
	return pontos;
}

const String Reta::toString() const {
	return "[" + this->v_inicial.toString() + ", " +
			this->v_final.toString() + "]";
}

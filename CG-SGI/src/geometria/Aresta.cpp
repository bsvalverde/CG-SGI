#include "geometria/Aresta.h"

Aresta::Aresta(const Ponto& inicial, const Ponto& final) {
	this->v_inicial = &inicial;
	this->v_final = &final;
}

Aresta::~Aresta() {
}

QList<Ponto> Aresta::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, *this->v_inicial);
	pontos.insert(1, *this->v_final);
	return pontos;
}

#include "geometria/Aresta.h"

Aresta::Aresta(Ponto& inicial, Ponto& final, const QColor& cor) {
	this->v_inicial = &inicial;
	this->v_final = &final;
	this->cor = cor;
}

Aresta::~Aresta() {
}

QList<Ponto> Aresta::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, *this->v_inicial);
	pontos.insert(1, *this->v_final);
	return pontos;
}

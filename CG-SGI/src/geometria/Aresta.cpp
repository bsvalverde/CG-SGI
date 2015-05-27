#include "geometria/Aresta.h"

Aresta::Aresta(Ponto* const inicial, Ponto* const final, const QColor& cor) {
	this->v_inicial = inicial;
	this->v_final = final;
	this->cor = cor;
}

Aresta::~Aresta() {
}

bool Aresta::operator==(const Aresta& rhs) const {
	return rhs.getPontos().at(0) == *this->v_inicial &&
			rhs.getPontos().at(1) == *this->v_final;
}

QList<Ponto> Aresta::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, *this->v_inicial);
	pontos.insert(1, *this->v_final);
	return pontos;
}

QList<Ponto*> Aresta::getPontosObjeto() {
	QList<Ponto*> pontos = {this->v_inicial, this->v_final};
	return pontos;
}

QColor Aresta::getCor() const {
	return this->cor;
}

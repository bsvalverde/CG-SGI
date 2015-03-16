#include "geometria/Poligono.h"

Poligono::Poligono(const String& nome, const QList<Ponto> pontos) : ObjetoGeometrico(nome) {
	this->pontos = pontos;
}

Poligono::~Poligono() {}


QList<Ponto> Poligono::getPontos() {
	return this->pontos;
}

const String Poligono::toString() const {
	String str = "[" + this->pontos.at(0).toString();

	for(int i = 1; i < this->pontos.size(); i++)
		str += ", " + this->pontos.at(i).toString();

	str += "]";

	return str;
}

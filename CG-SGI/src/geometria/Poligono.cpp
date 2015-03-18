#include "geometria/Poligono.h"

Poligono::Poligono() : ObjetoGeometrico() {}

Poligono::Poligono(const Poligono& poligono) : ObjetoGeometrico(poligono) {
	this->pontos = poligono.pontos;
}

Poligono::Poligono(const String& nome, const QList<Ponto>& pontos) :
					ObjetoGeometrico(nome, Tipo::POLIGONO) {
	this->pontos = pontos;
}

Poligono::~Poligono() {}

Poligono& Poligono::operator=(const Poligono& poligono) {
	this->ObjetoGeometrico::operator =(poligono);
	this->pontos = poligono.pontos;
	return *this;
}

QList<Ponto> Poligono::getPontos() const {
	return this->pontos;
}

const String Poligono::toString() const {
	String str = "[" + this->pontos.at(0).toString();

	for(int i = 1; i < this->pontos.size(); i++)
		str += ", " + this->pontos.at(i).toString();

	str += "]";

	return str;
}

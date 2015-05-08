#include "geometria/Poligono.h"

Poligono::Poligono() :
		ObjetoGeometrico() {
}

Poligono::Poligono(const Poligono& poligono) :
		ObjetoGeometrico(poligono) {
	for (int i = 0; i < poligono.pontos.size(); i++)
		this->pontos.insert(i, poligono.pontos.at(i));
}

Poligono::Poligono(const String& nome, const QList<Ponto>& pontos,
		const QColor& cor) :
		ObjetoGeometrico(nome, Tipo::POLIGONO, cor) {
	this->pontos = pontos;
}

Poligono::~Poligono() {
}

Poligono& Poligono::operator=(const Poligono& poligono) {
	this->ObjetoGeometrico::operator =(poligono);
	this->pontos.clear();
	for (int i = 0; i < poligono.pontos.size(); i++)
		this->pontos.insert(i, poligono.pontos.at(i));
	return *this;
}

ObjetoGeometrico* Poligono::clonar() const {
	return new Poligono(*this);
}

QList<Ponto> Poligono::getPontos() const {
	return this->pontos;
}

QList<Ponto*> Poligono::getPontosObjeto() {
	QList<Ponto*> lista;

	for (int i = 0; i < this->pontos.size(); i++)
		lista.insert(i, (Ponto*) &this->pontos.at(i));

	return lista;
}

const String Poligono::toString() const {
	String str = this->pontos.at(0).toString();

	for (int i = 1; i < this->pontos.size(); i++)
		str += ", " + this->pontos.at(i).toString();

	return "[" + str + "]";
}

#include "geometria/Objeto3D.h"

Objeto3D::Objeto3D() :
		ObjetoGeometrico() {
}

Objeto3D::Objeto3D(const Objeto3D& objeto3d) :
		ObjetoGeometrico(objeto3d) {
	for (int i = 0; i < objeto3d.pontos.size(); i++)
		this->pontos.insert(i, objeto3d.pontos.at(i));
	for (int i = 0; i < objeto3d.arestas.size(); i++)
		this->arestas.insert(i, objeto3d.arestas.at(i));
}

Objeto3D::Objeto3D(const String& nome, const QList<Ponto>& pontos,
		const QList<Aresta>& arestas, const QColor& cor) :
		ObjetoGeometrico(nome, Tipo::OBJETO3D, cor) {
	for (int i = 0; i < pontos.size(); i++)
		this->pontos.insert(i, pontos.at(i));
	for (int i = 0; i < arestas.size(); i++)
		this->arestas.insert(i, arestas.at(i));
}

Objeto3D::~Objeto3D() {
}

Objeto3D& Objeto3D::operator=(const Objeto3D& objeto3d) {
	this->ObjetoGeometrico::operator =(objeto3d);
	this->pontos.clear();
	for (int i = 0; i < objeto3d.pontos.size(); i++)
		this->pontos.insert(i, objeto3d.pontos.at(i));
	for (int i = 0; i < objeto3d.arestas.size(); i++)
		this->arestas.insert(i, objeto3d.arestas.at(i));
	return *this;
}

ObjetoGeometrico* Objeto3D::clonar() const {
	return new Objeto3D(*this);
}

QList<Ponto> Objeto3D::getPontos() const {
	return this->pontos;
}

QList<Ponto*> Objeto3D::getPontosObjeto() {
	QList<Ponto*> lista;

	for (int i = 0; i < this->pontos.size(); i++)
		lista.insert(i, (Ponto*) &this->pontos.at(i));

	return lista;
}

void Objeto3D::setPontos(const QList<Ponto>& pontos) {
	this->pontos = pontos;
}

QList<Aresta> Objeto3D::getArestas() const {
	return this->arestas;
}

void Objeto3D::setArestas(const QList<Aresta>& arestas) {
	this->arestas = arestas;
}

const String Objeto3D::toString() const {
	String str = this->pontos.at(0).toString();

	for (int i = 1; i < this->pontos.size(); i++)
		str += ", " + this->pontos.at(i).toString();

	return "[" + str + "]";
}

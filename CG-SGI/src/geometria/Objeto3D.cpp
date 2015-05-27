#include "geometria/Objeto3D.h"

Objeto3D::Objeto3D() :
		ObjetoGeometrico() {
}

Objeto3D::Objeto3D(const Objeto3D& objeto3d) :
		ObjetoGeometrico(objeto3d) {
	QMap<long, Ponto*> novosPontos;

	for (int i = 0; i < objeto3d.pontos.size(); i++) {
		Ponto* p = (Ponto*) objeto3d.pontos.at(i)->clonar();
		novosPontos.insert((long) objeto3d.pontos.at(i), p);
	}

	this->pontos = novosPontos.values();

	for (int i = 0; i < objeto3d.arestas.size(); i++) {
		Aresta a = objeto3d.arestas.at(i);
		Ponto* p1 = novosPontos.value((long) a.getPontosObjeto().at(0));
		Ponto* p2 = novosPontos.value((long) a.getPontosObjeto().at(1));
		this->arestas.append(Aresta(p1, p2, a.getCor()));
	}
}

Objeto3D::Objeto3D(const String& nome, const QList<Ponto*>& pontos,
		const QList<Aresta>& arestas) :
		ObjetoGeometrico(nome, Tipo::OBJETO3D) {
	this->pontos = pontos;
	this->arestas = arestas;
}

Objeto3D::~Objeto3D() {
}

Objeto3D& Objeto3D::operator=(const Objeto3D& objeto3d) {
	this->ObjetoGeometrico::operator =(objeto3d);
	this->pontos.clear();
	this->arestas.clear();
	QMap<long, Ponto*> novosPontos;

	for (int i = 0; i < objeto3d.pontos.size(); i++) {
		Ponto* p = (Ponto*) objeto3d.pontos.at(i)->clonar();
		novosPontos.insert((long) objeto3d.pontos.at(i), p);
	}

	this->pontos = novosPontos.values();

	for (int i = 0; i < objeto3d.arestas.size(); i++) {
		Aresta a = objeto3d.arestas.at(i);
		Ponto* p1 = novosPontos.value((long) a.getPontosObjeto().at(0));
		Ponto* p2 = novosPontos.value((long) a.getPontosObjeto().at(1));
		this->arestas.append(Aresta(p1, p2, a.getCor()));
	}
	return *this;
}

ObjetoGeometrico* Objeto3D::clonar() const {
	return new Objeto3D(*this);
}

QList<Ponto> Objeto3D::getPontos() const {
	QList<Ponto> lista;

	for (int i = 0; i < this->pontos.size(); i++)
		lista.insert(i, *this->pontos.at(i));

	return lista;
}

QList<Ponto*> Objeto3D::getPontosObjeto() {
	return this->pontos;
}

QList<Aresta> Objeto3D::getArestas() const {
	return this->arestas;
}

const String Objeto3D::toString() const {
	String str = this->pontos.at(0)->toString();

	for (int i = 1; i < this->pontos.size(); i++)
		str += ", " + this->pontos.at(i)->toString();

	return "[" + str + "]";
}

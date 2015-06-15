#include "geometria/Faceta.h"

Faceta::Faceta(const Faceta& faceta) :
		ObjetoGeometrico(faceta) {
	for (int i = 0; i < faceta.pontos.size(); i++)
		this->pontos.insert(i, faceta.pontos.at(i));
}

Faceta::Faceta(const QList<Ponto*>& pontos, const QColor& cor) :
		ObjetoGeometrico("", ObjetoGeometrico::FACETA, cor) {
	this->pontos = pontos;
}

Faceta::~Faceta() {
}

ObjetoGeometrico* Faceta::clonar() const {
	return new Faceta(*this);
}

QList<Ponto> Faceta::getPontos() const {
	QList<Ponto> lista;

	for (int i = 0; i < this->pontos.size(); i++)
		lista.insert(i, *this->pontos.at(i));

	return lista;
}

QList<Ponto*> Faceta::getPontosObjeto() {
	return this->pontos;
}

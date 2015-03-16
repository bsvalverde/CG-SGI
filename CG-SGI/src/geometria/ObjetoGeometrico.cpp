#include "geometria/ObjetoGeometrico.h"
#include "geometria/Ponto.h"

ObjetoGeometrico::ObjetoGeometrico(const ObjetoGeometrico& objeto) {
	this->nome = objeto.nome;
}

ObjetoGeometrico::ObjetoGeometrico() {
	this->nome = "";
}

ObjetoGeometrico::ObjetoGeometrico(const String& nome) {
	this->nome = nome;
}

ObjetoGeometrico::~ObjetoGeometrico() {}

void ObjetoGeometrico::operator=(const ObjetoGeometrico& objeto) {
	this->nome = objeto.nome;
}

const String& ObjetoGeometrico::getNome() const {
	return this->nome;
}

QList<Ponto> ObjetoGeometrico::getPontos() {
	return QList<Ponto>();
}

const String ObjetoGeometrico::toString() const {
	return this->nome;
}

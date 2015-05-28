#include "geometria/Superficie.h"

Superficie::Superficie() : ObjetoGeometrico() {
}

Superficie::Superficie(const Superficie& superficie) : ObjetoGeometrico(superficie) {
}

Superficie::Superficie(const String& nome, const Tipo tipo, const QColor& cor) : ObjetoGeometrico(nome, tipo, cor) {
}

Superficie::~Superficie() {
}

Superficie& Superficie::operator=(const Superficie& superficie) {
	this->ObjetoGeometrico::operator =(superficie);
	return *this;
}

void Superficie::aplicarTransformacao(const double matriz[4][4]) {
	this->ObjetoGeometrico::aplicarTransformacao(matriz);
	this->calcularPontosParametricos();
}

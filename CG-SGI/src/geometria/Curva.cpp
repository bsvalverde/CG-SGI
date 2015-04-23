#include "geometria/Curva.h"

Curva::Curva() : ObjetoGeometrico() {
}

Curva::Curva(const Curva& curva) : ObjetoGeometrico(curva) {
}

Curva::Curva(const String& nome, const Tipo tipo, const QColor& cor) : ObjetoGeometrico(nome, tipo, cor) {
}

Curva::~Curva() {
}

Curva& Curva::operator=(const Curva& curva) {
	this->ObjetoGeometrico::operator =(curva);
	return *this;
}

void Curva::aplicarTransformacao(const double matriz[4][4]) {
	this->ObjetoGeometrico::aplicarTransformacao(matriz);
	this->calcularPontosParametricos();
}

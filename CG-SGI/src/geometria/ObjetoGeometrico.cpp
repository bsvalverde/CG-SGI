#include "geometria/ObjetoGeometrico.h"
#include "geometria/Ponto.h"

ObjetoGeometrico::ObjetoGeometrico(const ObjetoGeometrico& objeto) {
	this->nome = objeto.nome;
	this->tipo = objeto.tipo;
}

ObjetoGeometrico::ObjetoGeometrico() {
	this->nome = "";
	this->tipo = Tipo::POLIGONO;
}

ObjetoGeometrico::ObjetoGeometrico(const String& nome, Tipo tipo) {
	this->nome = nome;
	this->tipo = tipo;
}

ObjetoGeometrico::~ObjetoGeometrico() {}

void ObjetoGeometrico::operator=(const ObjetoGeometrico& objeto) {
	this->nome = objeto.nome;
}

const String& ObjetoGeometrico::getNome() const {
	return this->nome;
}

/**
 * Obter o tipo.
 * @return tipo do objeto.
 */
ObjetoGeometrico::Tipo ObjetoGeometrico::getTipo() const {
	return this->tipo;
}

const String ObjetoGeometrico::getTipoString() const {
	switch(this->tipo) {
		case Tipo::PONTO:
			return "Ponto";
		case Tipo::RETA:
			return "Reta";
		case Tipo::WINDOW:
			return "Window";
		default:
			return "Polígono";
	}
}

Ponto ObjetoGeometrico::getCentroGeometrico() const {
	QList<Ponto> pontos = this->getPontos();
	int numPontos = pontos.size();
	double x = 0;
	double y = 0;
	double z = 0;

	for(Ponto p : pontos) {
		x += p.getX();
		y += p.getY();
		z += p.getZ();
	}

	x = x/numPontos;
	y = y/numPontos;
	z = z/numPontos;

	return Ponto("CentroG-" + this->getNome(), x, y, z);
}

QList<Ponto> ObjetoGeometrico::getPontos() const {
	return QList<Ponto>();
}

const String ObjetoGeometrico::toString() const {
	return this->nome;
}

QList<Ponto> ObjetoGeometrico::aplicarTransformacao(double matriz[3][3]) {
	QList<Ponto> pontos = this->getPontos();
	QList<Ponto> novosPontos;

	for(int i = 0; i < pontos.size(); i++) {
		Ponto p = pontos.at(i);
		double coordenadas[3] = {0, 0, 0};
		for (int j = 0; j < 3; i++) {
			coordenadas[j] = p.getX() * matriz[0][j] +
							 p.getY() * matriz[1][j] +
							 1 * matriz[2][j]; // Coord Homog
		}
		Ponto pNovo(p.getNome(), coordenadas[0], coordenadas[1], coordenadas[2]);
		novosPontos.insert(i, pNovo);
	}

	return novosPontos;
}

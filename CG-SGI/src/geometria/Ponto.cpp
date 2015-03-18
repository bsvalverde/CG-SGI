#include "geometria/Ponto.h"

Ponto::Ponto() {
	this->coord_x = 0;
	this->coord_y = 0;
	this->coord_z = 0;
}

Ponto::Ponto(const Ponto& ponto) : ObjetoGeometrico(ponto) {
	this->coord_x = ponto.coord_x;
	this->coord_y = ponto.coord_y;
	this->coord_z = ponto.coord_z;
}

Ponto::Ponto(const String& nome, const double x, const double y, const double z) :
				ObjetoGeometrico(nome, Tipo::PONTO) {
	this->coord_x = x;
	this->coord_y = y;
	this->coord_z = z;
}

Ponto::~Ponto() {}

void Ponto::operator=(const Ponto& ponto) {
	this->coord_x = ponto.coord_x;
	this->coord_y = ponto.coord_y;
	this->coord_z = ponto.coord_z;
}

QList<Ponto> Ponto::getPontos() {
	QList<Ponto> pontos;
	pontos.insert(0, *this);
	return pontos;
}

const double Ponto::getX() const {
	return this->coord_x;
}

const double Ponto::getY() const {
	return this->coord_y;
}

const double Ponto::getZ() const {
	return this->coord_z;
}

const String Ponto::toString() const {
	String ponto = "(" + std::to_string(this->getX()) + ", " + std::to_string(this->getY()) + ", " +
			std::to_string(this->getZ()) + ")";
	return ponto;
}

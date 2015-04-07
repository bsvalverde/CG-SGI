#include "geometria/Ponto.h"

Ponto::Ponto() {
	this->coord_x = 0;
	this->coord_y = 0;
	this->coord_z = 1;
}

Ponto::Ponto(const Ponto& ponto) : ObjetoGeometrico(ponto) {
	this->coord_x = ponto.coord_x;
	this->coord_y = ponto.coord_y;
	this->coord_z = ponto.coord_z;
}

Ponto::Ponto(const String& nome, const double x, const double y, const double z, const QColor& cor) :
				ObjetoGeometrico(nome, Tipo::PONTO, cor) {
	this->coord_x = x;
	this->coord_y = y;
	this->coord_z = z;
}

Ponto::~Ponto() {}

Ponto& Ponto::operator=(const Ponto& ponto) {
	this->ObjetoGeometrico::operator =(ponto);
	this->coord_x = ponto.coord_x;
	this->coord_y = ponto.coord_y;
	this->coord_z = ponto.coord_z;
	return *this;
}

ObjetoGeometrico* Ponto::clonar() const {
	return new Ponto(*this);
}

QList<Ponto> Ponto::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, *this);
	return pontos;
}

const String Ponto::toString() const {
	String ponto = "(" + std::to_string(this->getX()) + ", " + std::to_string(this->getY()) + ", " +
			std::to_string(this->getZ()) + ")";
	return ponto;
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

void Ponto::setX(const double x){
	this->coord_x = x;
}

void Ponto::setY(const double y){
	this->coord_y = y;
}

void Ponto::setZ(const double z){
	this->coord_z = z;
}

QList<Ponto*> Ponto::getPontosObjeto() {
	QList<Ponto*> pontos;
	pontos.insert(0, this);
	return pontos;
}

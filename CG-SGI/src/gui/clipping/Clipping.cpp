#include "gui/clipping/Clipping.h"

Clipping::Clipping(const double xvMin, const double xvMax, const double yvMin, const double yvMax) {
	this->xvMin = xvMin;
	this->xvMax = xvMax;
	this->yvMin = yvMin;
	this->yvMax = yvMax;
}

Clipping::~Clipping() {}

bool Clipping::clip(ObjetoGeometrico* const objeto) const {
	switch(objeto->getTipo()) {
		case ObjetoGeometrico::POLIGONO:
			return this->clipPoligono((Poligono* const) objeto);
		case ObjetoGeometrico::PONTO:
			return this->clipPonto((Ponto* const) objeto);
		case ObjetoGeometrico::RETA:
			return this->clipReta((Reta* const) objeto);
		default:
			return false;
	}
}

bool Clipping::clipPoligono(Poligono* const poligono) const {
	return true;
}

bool Clipping::clipPonto(Ponto* const ponto) const {
	return (ponto->getX() > xvMin && ponto->getX() < xvMax && ponto->getY() > yvMin && ponto->getY() < yvMax);
}

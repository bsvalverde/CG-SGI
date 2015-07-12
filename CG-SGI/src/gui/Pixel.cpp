#include "gui/Pixel.h"

#include <float.h>

Pixel::Pixel() {
	this->x = 0;
	this->y = 0;
	this->z = DBL_MAX;
	this->cor = QColor(255, 255, 255);
	this->normal = Ponto("", 0, 0, -1);
}

Pixel::Pixel(const unsigned int x, const unsigned int y, const double z,
		const QColor& cor, Ponto normal) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->cor = cor;
	this->normal = normal;
}

Pixel::~Pixel() {
}

unsigned int Pixel::getX() const {
	return this->x;
}

unsigned int Pixel::getY() const {
	return this->y;
}

double Pixel::getZ() const {
	return this->z;
}

QColor Pixel::getCor() const {
	return this->cor;
}

Ponto Pixel::getNormal() const{
	return this->normal;
}

void Pixel::setCor(QColor novaCor) {
	this->cor = novaCor;
}

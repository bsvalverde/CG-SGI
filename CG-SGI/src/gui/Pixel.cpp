#include "gui/Pixel.h"

Pixel::Pixel(const unsigned int x, const unsigned int y, const unsigned int z, const QColor& cor) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->cor = cor;
}

Pixel::~Pixel() {
}

unsigned int Pixel::getX() const {
	return this->x;
}

unsigned int Pixel::getY() const {
	return this->y;
}

unsigned int Pixel::getZ() const {
	return this->z;
}

QColor Pixel::getCor() const {
	return this->cor;
}

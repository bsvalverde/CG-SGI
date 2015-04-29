#include "geometria/projecao/Projetor.h"
#include "geometria/Window.h"

Projetor::Projetor(const TipoProjecao& tipo, Window* const window) {
	this->tipo = tipo;
	this->window = window;
}

Projetor::~Projetor() {}

Projetor::TipoProjecao Projetor::getTipo() const {
	return this->tipo;
}

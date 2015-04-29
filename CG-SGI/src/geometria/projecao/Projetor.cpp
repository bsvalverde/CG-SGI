#include "geometria/projecao/Projetor.h"

Projetor::Projetor(const TipoProjecao& tipo) {
	this->tipo = tipo;
}

Projetor::~Projetor() {}

Projetor::TipoProjecao Projetor::getTipo() const {
	return this->tipo;
}

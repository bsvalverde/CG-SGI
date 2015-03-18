#include "geometria/Mundo.h"

Mundo::Mundo() {
	this->window = Window(Ponto("", 0, 0, 0), Ponto("", 510, 475, 0));
}

Mundo::~Mundo() {}

void Mundo::adicionarObjeto(const ObjetoGeometrico objeto) {
	this->displayFile.adicionarObjeto(objeto);
}

Window Mundo::getWindow() const {
	return this->window;
}

QList<ObjetoGeometrico> Mundo::getObjetos() const {
	return this->displayFile.getObjetos();
}

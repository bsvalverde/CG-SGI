#include "geometria/Cena.h"

Cena::Cena(Window* const window, const QList<ObjetoGeometrico*>& objetos) {
	this->window = window;
	this->objetos = objetos;
}

Cena::~Cena() {
	if(this->window)
		delete this->window;

	for(ObjetoGeometrico* obj : objetos) {
		if(obj)
			delete obj;
	}
}

Window* Cena::getWindow() const {
	return this->window;
}

QList<ObjetoGeometrico*> Cena::getObjetos() const {
	return this->objetos;
}

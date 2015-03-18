#include "geometria/Mundo.h"

Mundo::Mundo() {
	this->window = Window(Ponto("", 0, 0, 0), Ponto("", 510, 475, 0));
}

Mundo::~Mundo() {}

void Mundo::inserirObjeto(const ObjetoGeometrico& objeto) {
	this->displayFile.inserirObjeto(objeto);
}

void Mundo::removerObjeto(const String& nome) {
	this->displayFile.removerObjeto(nome);
}

bool Mundo::contemObjeto(const String& nome) {
	return this->displayFile.contem(nome);
}

const Window& Mundo::getWindow() const {
	return this->window;
}

QList<ObjetoGeometrico> Mundo::getObjetos() const {
	return this->displayFile.getObjetos();
}

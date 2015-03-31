#include "geometria/Mundo.h"
#include <iostream>

Mundo::Mundo() {
	this->window = new Window();
}

Mundo::~Mundo() {
	if(this->window)
		delete this->window;
}

void Mundo::inserirObjeto(const ObjetoGeometrico& objeto) {
	this->displayFile.inserirObjeto(objeto);
	this->window->atualizarObjeto((ObjetoGeometrico*) &objeto);
}

void Mundo::removerObjeto(const String& nome) {
	this->displayFile.removerObjeto(nome);
	this->window->removerObjeto(nome);
}

bool Mundo::contemObjeto(const String& nome) const {
	return this->displayFile.contem(nome);
}

void Mundo::setWindow(const Window& window) {
	if(this->window)
		delete this->window;

	this->window = new Window(window);
	this->window->atualizarDisplayFile(this->displayFile);
}

Window* Mundo::getWindow() const {
	return this->window;
}

QList<ObjetoGeometrico*> Mundo::getObjetos() const {
	return this->window->getObjetos();
}

void Mundo::navegar(const Direcao direcao, const double fator) {
	switch(direcao) {
		case Direcao::CIMA:
			this->window->transladar(0, fator, 0);
			break;
		case Direcao::BAIXO:
			this->window->transladar(0, -1 * fator, 0);
			break;
		case Direcao::DIREITA:
			this->window->transladar(fator, 0, 0);
			break;
		case Direcao::ESQUERDA:
			this->window->transladar(-1 * fator, 0, 0);
			break;
	}
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::redimensionarWindow(const double fator) {
	this->window->escalonar(fator, fator, fator);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::rotacionarWindow(const double angulo) {
	this->window->rotacionarPeloCentro(angulo);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->escalonar(sX, sY, sZ);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::transladarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->transladar(sX, sY, sZ);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->rotacionarPorPonto(ponto, angulo);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::rotacionarObjetoPeloCentro(const String& nome, const double angulo) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->rotacionarPeloCentro(angulo);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::reiniciarWindow(){
	delete(this->window);
	this->window = new Window();
	this->window->atualizarDisplayFile(this->displayFile);
}

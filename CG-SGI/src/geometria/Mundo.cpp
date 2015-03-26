#include "geometria/Mundo.h"

Mundo::Mundo() {
	this->window = new Window(Ponto("", -255, -235.5, 0), Ponto("", 255, 235.5, 0));
}

Mundo::~Mundo() {
	if(this->window)
		delete this->window;
}

void Mundo::inserirObjeto(ObjetoGeometrico* const objeto) {
	this->displayFile.inserirObjeto(objeto);
	this->window->atualizarObjeto(objeto);
}

void Mundo::removerObjeto(const String& nome) {
	ObjetoGeometrico* obj = this->displayFile.removerObjeto(nome);

	if(obj)
		delete obj;

	// TODO remover da window
}

bool Mundo::contemObjeto(const String& nome) {
	return this->displayFile.contem(nome);
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

void Mundo::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->escalonar(sX, sY, sZ);
	this->window->atualizarObjeto(obj);
}

void Mundo::transladarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->transladar(sX, sY, sZ);
	this->window->atualizarObjeto(obj);
}

void Mundo::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->rotacionarPorPonto(ponto, angulo);
	this->window->atualizarObjeto(obj);
}

void Mundo::rotacionarObjetoPeloCentro(const String& nome, const double angulo) {
	ObjetoGeometrico* obj = this->displayFile.getObjeto(nome);
	obj->rotacionarPeloCentro(angulo);
	this->window->atualizarObjeto(obj);
}

#include "geometria/Window.h"

Window::Window() : ObjetoGeometrico("Window", Tipo::WINDOW) {
	this->pontoInferiorEsquerdo = Ponto("p1", 0, 0, 0);
	this->pontoSuperiorDireito = Ponto("p2", 0, 0, 0);
}

Window::Window(const Window& window) : ObjetoGeometrico(window) {}

Window::Window(const Ponto& pInfEsq, const Ponto& pSupDir) : ObjetoGeometrico("Window", Tipo::WINDOW) {
	this->pontoInferiorEsquerdo = pInfEsq;
	this->pontoSuperiorDireito = pSupDir;
}

Window::~Window() {}

Window& Window::operator=(const Window& window) {
	this->ObjetoGeometrico::operator =(window);
	this->pontoInferiorEsquerdo = window.pontoInferiorEsquerdo;
	this->pontoSuperiorDireito = window.pontoSuperiorDireito;
	return *this;
}

QList<Ponto> Window::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, this->pontoInferiorEsquerdo);
	pontos.insert(1, this->pontoSuperiorDireito);
	return pontos;
}

const String Window::toString() const {
	return this->nome + "[" + this->pontoInferiorEsquerdo.toString() +
				", " + this->pontoSuperiorDireito.toString() + "]";
}

QList<Ponto*> Window::getPontosObjeto() {
	QList<Ponto*> pontos;
	pontos.insert(0, &this->pontoInferiorEsquerdo);
	pontos.insert(1, &this->pontoSuperiorDireito);
	return pontos;
}

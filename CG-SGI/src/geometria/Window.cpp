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

void Window::escalonar(double f) {
	double matriz[3][3] = {{f, 0, 0},
						   {0, f, 0},
						   {0, 0, 1}};
	QList<Ponto> pontos = this->aplicarTransformacao(matriz);
	this->pontoInferiorEsquerdo = pontos.at(0);
	this->pontoSuperiorDireito = pontos.at(1);
}

void Window::transladar(double f) {
	double matriz[3][3] = {{1, 0, 0},
						   {0, 1, 0},
						   {f, f, 1}};
	QList<Ponto> pontos = this->aplicarTransformacao(matriz);
	this->pontoInferiorEsquerdo = pontos.at(0);
	this->pontoSuperiorDireito = pontos.at(1);
}

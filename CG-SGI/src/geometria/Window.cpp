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

void Window::escalonar(const double f) {
	Ponto p = this->getCentroGeometrico();
	double cX = p.getX();
	double cY = p.getY();
	double matriz[3][3] = {{f, 0, 0},
						   {0, f, 0},
						   {-cX*f+cX, -cY*f+cY, 1}};
	QList<Ponto> pontos = this->aplicarTransformacao(matriz);
	this->pontoInferiorEsquerdo = pontos.at(0);
	this->pontoSuperiorDireito = pontos.at(1);
}

void Window::transladar(const double x, const double y) {
	double matriz[3][3] = {{1, 0, 0},
						   {0, 1, 0},
						   {x, y, 1}};
	QList<Ponto> pontos = this->aplicarTransformacao(matriz);
	this->pontoInferiorEsquerdo = pontos.at(0);
	this->pontoSuperiorDireito = pontos.at(1);
}

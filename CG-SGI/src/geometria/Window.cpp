#include "geometria/Window.h"

Window::Window(Ponto pInfEsq, Ponto pSupDir) : ObjetoGeometrico("Window", Tipo::WINDOW) {
	this->pontoInferiorEsquerdo = pInfEsq;
	this->pontoSuperiorDireito = pSupDir;
}

Window::~Window() {}

QList<Ponto> Window::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, this->pontoInferiorEsquerdo);
	pontos.insert(1, this->pontoSuperiorDireito);
	return pontos;
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

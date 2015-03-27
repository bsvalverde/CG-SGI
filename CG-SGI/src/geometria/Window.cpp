#include "geometria/Window.h"
#include <iostream>

Window::Window() : ObjetoGeometrico("Window", Tipo::WINDOW) {
	this->centro = Ponto("centro", 0, 0, 0);
	this->viewUpVector = Ponto("viewUpVector", 0, 10, 0);
}

Window::Window(const Window& window) : ObjetoGeometrico(window) {
	this->centro = window.centro;
	this->viewUpVector = window.viewUpVector;
	this->displayFileNormalizado = window.displayFileNormalizado;
}

Window::Window(const Ponto& centro, const Ponto& viewUpVector) : ObjetoGeometrico("Window", Tipo::WINDOW) {
	this->centro = centro;
	this->viewUpVector = viewUpVector;
}

Window::~Window() {}

Window& Window::operator=(const Window& window) {
	this->ObjetoGeometrico::operator =(window);
	this->centro = window.centro;
	this->viewUpVector = window.viewUpVector;
	this->displayFileNormalizado = window.displayFileNormalizado;
	return *this;
}

QList<Ponto> Window::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, this->centro);
	pontos.insert(1, this->viewUpVector);
	return pontos;
}

const String Window::toString() const {
	return this->nome + "[" + this->centro.toString() +
				", " + this->viewUpVector.toString() + "]";
}

const Ponto Window::getCentroGeometrico() const{
	return this->centro;
}

double Window::getAltura() const {
	return this->tamViewUpVector() * 2;
}

double Window::getLargura() const {
	return this->tamViewUpVector() * 2;
}

void Window::atualizarDisplayFile(const DisplayFile& displayFile){
	this->displayFileNormalizado = displayFile;
	int tam = this->displayFileNormalizado.getTamanho();

	for(int i = 0; i < tam; i++)
		this->atualizarObjeto(this->displayFileNormalizado.getObjeto(i));
}

void Window::atualizarObjeto(ObjetoGeometrico* obj){
	double angulo = this->anguloComCoordenadasMundo();
	double tam = this->tamViewUpVector();
	double x = centro.getX();
	double y = centro.getY();
	double z = centro.getZ();
	double matriz[4][4] = {{cos(-angulo)/tam, -sin(-angulo)/tam, 0, 0},
						   {sin(-angulo)/tam, cos(-angulo)/tam, 0, 0},
						   {0, 0, 1/tam, 0},
						   {-x*cos(-angulo)-y*sin(-angulo), x*sin(-angulo)-y*cos(-angulo), -z, 1}};

	if(!this->displayFileNormalizado.contem(obj->getNome())){
		this->displayFileNormalizado.inserirObjeto(obj);
	}

	std::cout << "atualiz1 " << obj->getNome() << std::endl;
	std::cout << obj->getPontos().at(0) << std::endl;
	std::cout << obj->getPontos().at(1) << std::endl;

	ObjetoGeometrico* objeto = this->displayFileNormalizado.getObjeto(obj->getNome());
	objeto->aplicarTransformacao(matriz);

	std::cout << "atualiz2 " << objeto->getNome() << std::endl;
	std::cout << objeto->getPontos().at(0) << std::endl;
	std::cout << objeto->getPontos().at(1) << std::endl;
}

void Window::removerObjeto(const String& nome) {
	delete this->displayFileNormalizado.removerObjeto(nome);
}

double Window::anguloComCoordenadasMundo(){
	double x = this->viewUpVector.getX() - this->centro.getX();
	double y = this->viewUpVector.getY() - this->centro.getY();
	double tan = x / y;
	double angulo = atan(tan);
	std::cout << (angulo * 180/3.14) << std::endl;
	return angulo;
}

double Window::tamViewUpVector() const {
	double x = this->viewUpVector.getX() - this->centro.getX();
	double y = this->viewUpVector.getY() - this->centro.getY();
	return sqrt(pow(x, 2)+pow(y, 2));
}

QList<ObjetoGeometrico*> Window::getObjetos() const {
	return this->displayFileNormalizado.getObjetos();
}

QList<Ponto*> Window::getPontosObjeto() {
	QList<Ponto*> pontos;
	pontos.insert(0, &this->centro);
	pontos.insert(1, &this->viewUpVector);
	return pontos;
}

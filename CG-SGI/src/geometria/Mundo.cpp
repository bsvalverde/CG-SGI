#include "geometria/Mundo.h"

Mundo::Mundo() {
	this->window = new Window();
}

Mundo::~Mundo() {
	if (this->window)
		delete this->window;
}

void Mundo::setWindow(const Window& window) {
	if (this->window)
		delete this->window;

	this->window = new Window(window);
	this->window->atualizarDisplayFile(this->displayFile);
}

QList<ObjetoGeometrico*> Mundo::getObjetosReais() const {
	return this->displayFile.getObjetos();
}

QList<ObjetoGeometrico*> Mundo::getObjetosNormalizados() const {
	return this->window->getObjetos();
}

void Mundo::removerObjetos() {
	this->displayFile.removerObjetos();
	this->window->removerObjetos();
}

void Mundo::navegar(const Direcao direcao, const double fator) {
	switch (direcao) {
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

void Mundo::aplicarZoom(const double fator) {
	double fatorEscalonamento = (double) 1 / ((fator * 0.1) + 1);

	if (fator < 0)
		fatorEscalonamento = (double) (fator * -0.1) + 1;

	this->window->escalonar(fatorEscalonamento, fatorEscalonamento, 0);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::rotacionarVisualizacao(const double angulo) {
	this->rotacionarObjetoPeloCentro(this->window, angulo, Mundo::EIXO_X); // TODO
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::reiniciarVisualizacao() {
	delete this->window;
	this->window = new Window();
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::inserirObjeto(const ObjetoGeometrico& objeto) {
	this->displayFile.inserirObjeto(objeto);
	this->window->atualizarObjeto((ObjetoGeometrico*) &objeto);
}

void Mundo::removerObjeto(const String& nome) {
	this->displayFile.removerObjeto(nome);
	this->window->removerObjeto(nome);
}

ObjetoGeometrico* Mundo::getObjeto(const String& nome) {
	return this->displayFile.getObjeto(nome);
}

bool Mundo::contemObjeto(const String& nome) const {
	return this->displayFile.contem(nome);
}

void Mundo::escalonarObjeto(ObjetoGeometrico* const objeto, const double sX,
		const double sY, const double sZ) {
	objeto->escalonar(sX, sY, sZ);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::transladarObjeto(ObjetoGeometrico* const objeto, const double sX,
		const double sY, const double sZ) {
	objeto->transladar(sX, sY, sZ);
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::rotacionarObjetoPorPonto(ObjetoGeometrico* const objeto,
		const Ponto& ponto, const double angulo, Eixo eixo) {
	switch (eixo) {
	case EIXO_X:
		objeto->rotacionarPorX(ponto, angulo);
		break;
	case EIXO_Y:
		objeto->rotacionarPorY(ponto, angulo);
		break;
	case EIXO_Z:
		objeto->rotacionarPorZ(ponto, angulo);
		break;
	default:
		break;
	}
	this->window->atualizarDisplayFile(this->displayFile);
}

void Mundo::rotacionarObjetoPeloCentro(ObjetoGeometrico* const objeto,
		const double angulo, Eixo eixo) {
	Ponto ponto = objeto->getCentroGeometrico();
	this->rotacionarObjetoPorPonto(objeto, ponto, angulo, eixo);
}

void Mundo::rotacionarObjetoPeloEixo(ObjetoGeometrico* const objeto,
		const double angulo, Reta eixo) {
	objeto->rotacionarPorEixo(angulo, eixo);
	this->window->atualizarDisplayFile(this->displayFile);
}

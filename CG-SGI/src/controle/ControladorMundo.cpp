#include "controle/ControladorMundo.h"

ControladorMundo::ControladorMundo() {}

ControladorMundo::~ControladorMundo() {}

void ControladorMundo::navegarNoMundo(const Mundo::Direcao direcao, const double fator) {
	this->mundo.navegar(direcao, fator);
}

void ControladorMundo::aplicarZoomNoMundo(const double fator) {
	this->mundo.aplicarZoom(fator);
}

void ControladorMundo::rotacionarVisualizacao(const double angulo) {
	this->mundo.rotacionarVisualizacao(angulo);
}

void ControladorMundo::reiniciarVisualizacao(){
	this->mundo.reiniciarVisualizacao();
}

QList<ObjetoGeometrico*> ControladorMundo::getObjetosReais() const {
	return this->mundo.getObjetosReais();
}

QList<ObjetoGeometrico*> ControladorMundo::getObjetosNormalizados() const {
	return this->mundo.getObjetosNormalizados();
}

void ControladorMundo::atualizarObjetos(const QList<ObjetoGeometrico*>& objetos) {
	this->mundo.removerObjetos();

	for(ObjetoGeometrico* obj : objetos)
		this->mundo.inserirObjeto(*obj);
}

void ControladorMundo::inserirObjeto(const String& nome, const QList<Ponto>& pontos, const QColor& cor) {
	int numeroPontos = pontos.size();

	if(numeroPontos == 1) {
		Ponto p = pontos.at(0);
		this->mundo.inserirObjeto(Ponto(nome, p.getX(), p.getY(), p.getZ(), cor));
	} else if(numeroPontos == 2) {
		this->mundo.inserirObjeto(Reta(nome, pontos.at(0), pontos.at(1), cor));
	} else if(numeroPontos > 2) {
		this->mundo.inserirObjeto(Poligono(nome, pontos, cor));
	}
}

void ControladorMundo::removerObjeto(const String& nome) {
	this->mundo.removerObjeto(nome);
}

bool ControladorMundo::contemObjeto(const String& nome) {
	return this->mundo.contemObjeto(nome);
}

void ControladorMundo::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.escalonarObjeto(obj, sX, sY, sZ);
}

void ControladorMundo::transladarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.transladarObjeto(obj, sX, sY, sZ);
}

void ControladorMundo::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.rotacionarObjetoPorPonto(obj, ponto, angulo);
}

void ControladorMundo::rotacionarObjetoPeloCentro(const String& nome, const double angulo) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.rotacionarObjetoPeloCentro(obj, angulo);
}

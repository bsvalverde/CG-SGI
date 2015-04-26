#include "controle/ControladorPrincipal.h"
#include "controle/ControladorMundo.h"
#include "controle/ControladorPersistencia.h"
#include "controle/ControladorUI.h"

ControladorPrincipal::ControladorPrincipal() {
	this->controladorMundo = new ControladorMundo();
	this->controladorPersistencia = new ControladorPersistencia();
	this->controladorUI = new ControladorUI(this);
}

ControladorPrincipal::~ControladorPrincipal() {
	if(this->controladorMundo)
		delete this->controladorMundo;

	if(this->controladorPersistencia)
		delete this->controladorPersistencia;

	if(this->controladorUI)
		delete this->controladorUI;
}

void ControladorPrincipal::executar() {
	this->controladorUI->exibirFormPrincipal();
}

void ControladorPrincipal::navegarNoMundo(const Mundo::Direcao direcao, const double fator) {
	this->controladorMundo->navegarNoMundo(direcao, fator);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::aplicarZoomNoMundo(const double fator) {
	this->controladorMundo->aplicarZoomNoMundo(fator);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::rotacionarVisualizacao(const double angulo) {
	this->controladorMundo->rotacionarVisualizacao(angulo);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::reiniciarVisualizacao() {
	this->controladorMundo->reiniciarVisualizacao();
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::inserirObjeto(const String& nome, const QList<Ponto>& pontos,
		ObjetoGeometrico::Tipo tipo, const QColor& cor) {
	this->controladorMundo->inserirObjeto(nome, pontos, tipo, cor);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::removerObjeto(const String& nome) {
	this->controladorMundo->removerObjeto(nome);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::removerObjetosMundo() {
	this->controladorMundo->removerObjetosMundo();
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

bool ControladorPrincipal::contemObjeto(const String& nome) {
	return this->controladorMundo->contemObjeto(nome);
}

void ControladorPrincipal::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	this->controladorMundo->escalonarObjeto(nome, sX, sY, sZ);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::transladarObjeto(const String& nome, const double sX, const double sY,	const double sZ) {
	this->controladorMundo->transladarObjeto(nome, sX, sY, sZ);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo) {
	this->controladorMundo->rotacionarObjetoPorPonto(nome, ponto, angulo);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::rotacionarObjetoPeloCentro(const String& nome, const double angulo) {
	this->controladorMundo->rotacionarObjetoPeloCentro(nome, angulo);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());
}

void ControladorPrincipal::importarCena(const String& nomeArquivo) {
	QList<ObjetoGeometrico*> objetos = this->controladorPersistencia->importarCena(nomeArquivo);
	this->controladorMundo->atualizarObjetos(objetos);
	this->controladorUI->atualizarCena(this->controladorMundo->getObjetosNormalizados());

	for(ObjetoGeometrico* obj : objetos)
		delete obj;
}

void ControladorPrincipal::exportarCena(const String& nomeArquivo) {
	this->controladorPersistencia->exportarCena(nomeArquivo, this->controladorMundo->getObjetosReais());
}

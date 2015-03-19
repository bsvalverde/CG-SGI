#include "controle/ControladorUI.h"
#include "gui/forms/MainWindow.h"
#include "gui/forms/ObjectInsertionWindow.h"
#include "gui/forms/ObjectTransformationWindow.h"
#include "geometria/Reta.h"
#include "geometria/Poligono.h"

ControladorUI::ControladorUI() {
	this->mainWindow = new MainWindow(this);
	this->objectInsertionWindow = new ObjectInsertionWindow(this, this->mainWindow);
	this->objectTransformationWindow = new ObjectTransformationWindow(this, this->mainWindow);
}

ControladorUI::~ControladorUI() {}

void ControladorUI::executar() {
	this->mainWindow->show();
}

void ControladorUI::exibirObjectInsertionWindow() {
	this->objectInsertionWindow->clearFields();
	this->objectInsertionWindow->show();
}

void ControladorUI::exibirObjectTransformationWindow(const String& nomeObjeto) {
	this->objectTransformationWindow->clearFields();
	this->objectTransformationWindow->show(nomeObjeto);
}

void ControladorUI::navegarNoMundo(const Mundo::Direcao direcao, const double fator) {
	this->mundo.navegar(direcao, fator);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::redimensionarWindow(const double fator) {
	this->mundo.redimensionarWindow(fator);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::inserirObjeto(const String& nome, const QList<Ponto> pontos) {
	int numeroPontos = pontos.size();

	if(numeroPontos == 1) {
		Ponto p = pontos.at(0);
		this->mundo.inserirObjeto(new Ponto(nome, p.getX(), p.getY(), p.getZ()));
	} else if(numeroPontos == 2) {
		this->mundo.inserirObjeto(new Reta(nome, pontos.at(0), pontos.at(1)));
	} else if(numeroPontos > 2) {
		this->mundo.inserirObjeto(new Poligono(nome, pontos));
	}

	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::removerObjeto(const String& nome) {
	this->mundo.removerObjeto(nome);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

bool ControladorUI::contemObjeto(const String& nome) {
	return this->mundo.contemObjeto(nome);
}

QList<Ponto> ControladorUI::getPontosWindow() const {
	return this->mundo.getWindow().getPontos();
}

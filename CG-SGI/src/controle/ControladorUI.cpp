#include "controle/ControladorUI.h"
#include "gui/forms/MainWindow.h"
#include "gui/forms/ObjectInsertionWindow.h"
#include "geometria/Reta.h"
#include "geometria/Poligono.h"

ControladorUI::ControladorUI() {
	this->mainWindow = new MainWindow(this);
	this->objectInsertionWindow = new ObjectInsertionWindow(this, this->mainWindow);
}

ControladorUI::~ControladorUI() {}

void ControladorUI::executar() {
	this->mainWindow->show();
}

void ControladorUI::exibirObjectInsertionWindow() {
	this->objectInsertionWindow->clearFields();
	this->objectInsertionWindow->show();
}

void ControladorUI::inserirObjeto(String& nome, QList<Ponto> pontos) {
	int numeroPontos = pontos.size();

	if(numeroPontos == 1) {
		this->mundo.adicionarObjeto(pontos.at(0));
	} else if(numeroPontos == 2) {
		this->mundo.adicionarObjeto(Reta(nome, pontos.at(0), pontos.at(1)));
	} else if(numeroPontos > 2) {
		this->mundo.adicionarObjeto(Poligono(nome, pontos));
	}

	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

Mundo ControladorUI::getMundo() const {
	return this->mundo;
}

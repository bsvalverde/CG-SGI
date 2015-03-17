#include "controle/ControladorUI.h"
#include "gui/forms/MainWindow.h"
#include "gui/forms/ObjectInsertionWindow.h"

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

void ControladorUI::inserirObjeto(String nome, QList<Ponto> pontos) {
	int numeroPontos = pontos.size();

	if(numeroPontos == 1) {
		std::cout << "inserir ponto" << std::endl;
	} else if(numeroPontos == 2) {
		std::cout << "inserir reta" << std::endl;
	} else if(numeroPontos > 2) {
		std::cout << "inserir poligono" << std::endl;
	}
}

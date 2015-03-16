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

void ControladorUI::showObjectInsertionWindow() {
	this->objectInsertionWindow->clearFields();
	this->objectInsertionWindow->show();
}

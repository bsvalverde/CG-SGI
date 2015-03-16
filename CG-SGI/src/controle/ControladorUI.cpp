#include "controle/ControladorUI.h"

ControladorUI::ControladorUI() {
	this->mainWindow = new MainWindow();
}

ControladorUI::~ControladorUI() {}

void ControladorUI::executar() {
	this->mainWindow->show();
}

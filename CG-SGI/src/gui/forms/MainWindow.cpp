#include "gui/forms/MainWindow.h"

MainWindow::MainWindow(QDialog *parent) : Window(parent) {
	this->setupUi(this);
	this->moveToCenter();
}


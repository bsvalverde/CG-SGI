#include "gui/forms/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : Window(parent) {
	this->setupUi(this);
	this->moveToCenter();
}


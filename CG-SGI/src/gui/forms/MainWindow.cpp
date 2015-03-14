#include "gui/forms/MainWindow.h"

MainWindow::MainWindow(QDialog *parent, Qt::WindowFlags flags) : Window(parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
}

void MainWindow::connectSignalsAndSlots() {
	QObject::connect(btnZoomIn, SIGNAL(pressed()), this, SLOT(btnZoomInPressed()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this, SLOT(btnZoomOutPressed()));
	QObject::connect(zoomControl, SIGNAL(valueChanged(int)), this, SLOT(zoomControlValueChanged(int)));
}

void MainWindow::btnZoomInPressed() {
	int position = this->zoomControl->value();
	this->zoomControl->setValue(position + 5);
}

void MainWindow::btnZoomOutPressed() {
	int position = this->zoomControl->value();
	this->zoomControl->setValue(position - 5);
}

void MainWindow::zoomControlValueChanged(int currentValue) {
	std::cout << "Value changed: " << currentValue << std::endl;
}

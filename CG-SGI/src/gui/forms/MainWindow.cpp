#include "gui/forms/MainWindow.h"

MainWindow::MainWindow(ControladorUI* controladorUI, QDialog* parent,
						Qt::WindowFlags flags) : Window(controladorUI, parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
}

void MainWindow::updateObjects(std::map<String, ObjetoGeometrico>& objects) {
	for(unsigned int i = 0; i < objects.size(); i++) {
		// something
	}
}

void MainWindow::connectSignalsAndSlots() {
	QObject::connect(btnZoomIn, SIGNAL(pressed()), this, SLOT(btnZoomInPressed()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this, SLOT(btnZoomOutPressed()));
	QObject::connect(zoomControl, SIGNAL(valueChanged(int)), this, SLOT(zoomControlValueChanged(int)));
	QObject::connect(btnInsertObject, SIGNAL(clicked()), this, SLOT(btnInsertObjectClicked()));
	QObject::connect(btnRemoveObject, SIGNAL(clicked()), this, SLOT(btnRemoveObjectClicked()));
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

void MainWindow::btnInsertObjectClicked() {
	this->controladorUI->exibirObjectInsertionWindow();
}

void MainWindow::btnRemoveObjectClicked() {

}

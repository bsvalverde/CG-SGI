#include "gui/forms/MainWindow.h"

MainWindow::MainWindow(QDialog *parent, Qt::WindowFlags flags) : Window(parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
	this->zoomControl->setRange(0, 100);
}

void MainWindow::connectSignalsAndSlots() {
	QObject::connect(btnZoomIn, SIGNAL(pressed()), this, SLOT(on_btnZoomIn_pressed()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this, SLOT(on_btnZoomOut_pressed()));
}

void MainWindow::on_btnZoomIn_pressed() {
	this->zoomControl->setValue(this->zoomControl->value() + 5);
}

void MainWindow::on_btnZoomOut_pressed() {
	this->zoomControl->setValue(this->zoomControl->value() - 5);
}

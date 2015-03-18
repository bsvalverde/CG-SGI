#include "gui/forms/DefaultWindow.h"

DefaultWindow::DefaultWindow(ControladorUI* controladorUI, QDialog* parent,
				Qt::WindowFlags flags) : QDialog(parent, flags) {
	this->controladorUI = controladorUI;
}

DefaultWindow::~DefaultWindow() {}

void DefaultWindow::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}

ControladorUI* DefaultWindow::getControladorUI() {
	return this->controladorUI;
}

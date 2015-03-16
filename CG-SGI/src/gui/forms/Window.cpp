#include "gui/forms/Window.h"

Window::Window(ControladorUI* controladorUI, QDialog* parent,
				Qt::WindowFlags flags) : QDialog(parent, flags) {
	this->controladorUI = controladorUI;
}

Window::~Window() {}

void Window::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}


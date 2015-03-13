#include "gui/forms/Window.h"

Window::Window(QDialog *parent) : QDialog(parent) { }

void Window::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}


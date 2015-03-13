#include "gui/forms/Window.h"

Window::Window(QDialog *parent, Qt::WindowFlags flags) : QDialog(parent, flags) { }

void Window::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}


#include "gui/forms/Window.h"

Window::Window(QWidget *parent) : QWidget(parent) { }

void Window::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}


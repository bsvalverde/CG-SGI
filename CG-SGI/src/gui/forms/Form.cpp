#include "gui/forms/Form.h"

Form::Form(ControladorUI* controladorUI, QWidget* pai,
				Qt::WindowFlags flags) : QDialog(pai, flags) {
	this->controladorUI = controladorUI;
}

Form::~Form() {}

void Form::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}

ControladorUI* Form::getControladorUI() {
	return this->controladorUI;
}

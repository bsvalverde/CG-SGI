#include "gui/forms/ObjectInsertionWindow.h"

ObjectInsertionWindow::ObjectInsertionWindow(ControladorUI* controladorUI, QDialog* parent,
							Qt::WindowFlags flags) : Window(controladorUI, parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
}

void ObjectInsertionWindow::connectSignalsAndSlots() {
	QObject::connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(btnInsert, SIGNAL(clicked()), this, SLOT(insertObject()));
	QObject::connect(btnRemovePoint, SIGNAL(clicked()), this, SLOT(removePoligonPoint()));
	QObject::connect(btnInsertPoint, SIGNAL(clicked()), this, SLOT(insertPoligonPoint()));
}

void ObjectInsertionWindow::clearFields(){
	this->fieldName->clear();
	this->fieldPointX->clear();
	this->fieldPointY->clear();
	this->fieldPointZ->clear();
	this->fieldLineX1->clear();
	this->fieldLineX2->clear();
	this->fieldLineY1->clear();
	this->fieldLineY2->clear();
	this->fieldLineZ1->clear();
	this->fieldLineZ2->clear();

	while(this->tablePoligonPoints->rowCount() > 0)
		this->tablePoligonPoints->removeRow(0);
}

void ObjectInsertionWindow::insertObject() {

}

void ObjectInsertionWindow::insertPoligonPoint() {
	this->tablePoligonPoints->insertRow(this->tablePoligonPoints->rowCount());
}

void ObjectInsertionWindow::removePoligonPoint() {
	QItemSelectionModel *selectionModel = this->tablePoligonPoints->selectionModel();
	for(QModelIndex index : selectionModel->selectedRows())
	    tablePoligonPoints->removeRow(index.row());
}

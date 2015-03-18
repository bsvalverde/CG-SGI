#include "gui/forms/ObjectInsertionWindow.h"

ObjectInsertionWindow::ObjectInsertionWindow(ControladorUI* controladorUI, QDialog* parent,
							Qt::WindowFlags flags) : DefaultWindow(controladorUI, parent, flags) {
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

	this->tabObjects->setCurrentIndex(0);
}

bool ObjectInsertionWindow::validateFields() {
	if(this->fieldName->text().isEmpty())
		return false;

	bool ok, ok1, ok2, ok3;

	switch(this->tabObjects->currentIndex()) {
		case 0:
			this->fieldPointX->text().toDouble(&ok1);
			this->fieldPointY->text().toDouble(&ok2);
			this->fieldPointZ->text().toDouble(&ok3);

			return ok1 && ok2 && ok3;
		case 1:
			this->fieldLineX1->text().toDouble(&ok1);
			this->fieldLineY1->text().toDouble(&ok2);
			this->fieldLineZ1->text().toDouble(&ok3);
			ok = ok1 && ok2 && ok3;

			this->fieldLineX2->text().toDouble(&ok1);
			this->fieldLineY2->text().toDouble(&ok2);
			this->fieldLineZ2->text().toDouble(&ok3);

			return ok && ok1 && ok2 && ok3;
		default:
			if(this->tablePoligonPoints->rowCount() == 0)
				return false;

			for(int i = 0; i < this->tablePoligonPoints->rowCount(); i++) {
				QTableWidgetItem *i1, *i2, *i3;
				i1 = this->tablePoligonPoints->item(i, 1);
				i2 = this->tablePoligonPoints->item(i, 2);
				i3 = this->tablePoligonPoints->item(i, 3);

				if(!i1 || !i2 || !i3)
					return false;

				i1->text().toDouble(&ok1);
				i2->text().toDouble(&ok2);
				i3->text().toDouble(&ok3);

				if(!(ok1 && ok2 && ok3))
					return false;
			}
	}

	return true;
}

void ObjectInsertionWindow::insertObject() {
	if(!this->validateFields()) {
		QMessageBox messageBox;
		messageBox.critical(this, "Erro", "Algum campo encontra-se vazio ou contém informação inválida!");
		return;
	}

	QList<Ponto> pontos;
	Ponto p;
	double x, y, z;
	String nome = this->fieldName->text().toStdString();

	switch(this->tabObjects->currentIndex()) {
		case 0:
			x = this->fieldPointX->text().toDouble();
			y = this->fieldPointY->text().toDouble();
			z = this->fieldPointZ->text().toDouble();
			p = Ponto(nome, x, y, z);
			pontos.insert(0, p);
			break;
		case 1:
			x = this->fieldLineX1->text().toDouble();
			y = this->fieldLineY1->text().toDouble();
			z = this->fieldLineZ1->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(0, p);

			x = this->fieldLineX2->text().toDouble();
			y = this->fieldLineY2->text().toDouble();
			z = this->fieldLineZ2->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(1, p);
			break;
		default:
			for(int i = 0; i < this->tablePoligonPoints->rowCount(); i++) {
				String nomePonto = this->fieldName->text().toStdString();

				x = this->tablePoligonPoints->item(i, 1)->text().toDouble();
				y = this->tablePoligonPoints->item(i, 2)->text().toDouble();
				z = this->tablePoligonPoints->item(i, 3)->text().toDouble();

				p = Ponto(nomePonto, x, y, z);
				pontos.insert(i, p);
			}
	}

	this->controladorUI->inserirObjeto(nome, pontos);
	this->accept();
}

void ObjectInsertionWindow::insertPoligonPoint() {
	this->tablePoligonPoints->insertRow(this->tablePoligonPoints->rowCount());
}

void ObjectInsertionWindow::removePoligonPoint() {
	QItemSelectionModel *selectionModel = this->tablePoligonPoints->selectionModel();
	for(QModelIndex index : selectionModel->selectedRows())
	    tablePoligonPoints->removeRow(index.row());
}

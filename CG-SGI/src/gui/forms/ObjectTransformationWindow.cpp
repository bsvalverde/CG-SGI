#include "gui/forms/ObjectTransformationWindow.h"

ObjectTransformationWindow::ObjectTransformationWindow(ControladorUI* controladorUI, QDialog* parent,
							Qt::WindowFlags flags) : DefaultWindow(controladorUI, parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
}

void ObjectTransformationWindow::show(const String& nomeObjeto) {
	this->nomeObjeto = nomeObjeto;
	QWidget::show();
}

void ObjectTransformationWindow::connectSignalsAndSlots() {
	QObject::connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(btnTransform, SIGNAL(clicked()), this, SLOT(transformObject()));
	QObject::connect(radBtnSpecificPoint, SIGNAL(toggled(bool)), this, SLOT(specificPointSelected(bool)));
}

void ObjectTransformationWindow::clearFields(){
	this->fieldScaleFactorX->clear();
	this->fieldScaleFactorY->clear();
	this->fieldScaleFactorZ->clear();
	this->fieldRotatePointX->clear();
	this->fieldRotatePointY->clear();
	this->fieldRotatePointZ->clear();
	this->fieldTranslateFactorX->clear();
	this->fieldTranslateFactorY->clear();
	this->fieldTranslateFactorZ->clear();

	this->tabTransformations->setCurrentIndex(0);
}

bool ObjectTransformationWindow::validateFields() {
	bool ok, ok1, ok2, ok3;

	switch(this->tabTransformations->currentIndex()) {
		case 0:
			this->fieldScaleFactorX->text().toDouble(&ok1);
			this->fieldScaleFactorY->text().toDouble(&ok2);
			ok3 = true;//this->fieldScaleFactorZ->text().toDouble(&ok3);

			return ok1 && ok2 && ok3;
		case 1:
			this->fieldRotateDegree->text().toDouble(&ok);
			ok1 = true, ok2 = true, ok3 = true;

			if(this->radBtnSpecificPoint->isChecked()) {
				this->fieldRotatePointX->text().toDouble(&ok1);
				this->fieldRotatePointY->text().toDouble(&ok2);
				ok3 = true;//this->fieldRotatePointZ->text().toDouble(&ok3);
			}

			return ok && ok1 && ok2 && ok3;
		default:
			this->fieldTranslateFactorX->text().toDouble(&ok1);
			this->fieldTranslateFactorY->text().toDouble(&ok2);
			ok3 = true;//this->fieldTranslateFactorZ->text().toDouble(&ok3);

			return ok1 && ok2 && ok3;
	}
}

void ObjectTransformationWindow::transformObject() {
	if(!this->validateFields()) {
		QMessageBox messageBox;
		messageBox.critical(this, "Erro", "Algum campo encontra-se vazio ou contém informação inválida!");
		return;
	}
/*
	QList<Ponto> pontos;
	Ponto p;
	double x, y, z;
	String nome = this->fieldName->text().toStdString();

	if(this->controladorUI->contemObjeto(nome)) {
		QMessageBox messageBox;
		messageBox.critical(this, "Erro", "Um objeto com este nome já existe!");
		return;
	}

	switch(this->tabObjects->currentIndex()) {
		case 0:
			x = this->fieldPointX->text().toDouble();
			y = this->fieldPointY->text().toDouble();
			z = 1;//this->fieldPointZ->text().toDouble();
			p = Ponto(nome, x, y, z);
			pontos.insert(0, p);
			break;
		case 1:
			x = this->fieldLineX1->text().toDouble();
			y = this->fieldLineY1->text().toDouble();
			z = 1;//this->fieldLineZ1->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(0, p);

			x = this->fieldLineX2->text().toDouble();
			y = this->fieldLineY2->text().toDouble();
			z = 1;//this->fieldLineZ2->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(1, p);
			break;
		default:
			for(int i = 0; i < this->tablePoligonPoints->rowCount(); i++) {
				String nomePonto = this->fieldName->text().toStdString();

				x = this->tablePoligonPoints->item(i, 0)->text().toDouble();
				y = this->tablePoligonPoints->item(i, 1)->text().toDouble();
				z = 1;//this->tablePoligonPoints->item(i, 2)->text().toDouble();

				p = Ponto(nomePonto, x, y, z);
				pontos.insert(i, p);
			}
			break;
	}

	this->controladorUI->inserirObjeto(nome, pontos);*/
	this->accept();
}

void ObjectTransformationWindow::specificPointSelected(bool selected) {
	this->fieldRotatePointX->setEnabled(selected);
	this->fieldRotatePointY->setEnabled(selected);
	//this->fieldRotatePointZ->setEnabled(selected);
	this->labelRotatePointX->setEnabled(selected);
	this->labelRotatePointY->setEnabled(selected);
	//this->labelRotatePointZ->setEnabled(selected);
}

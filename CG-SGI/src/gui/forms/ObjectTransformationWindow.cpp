#include "gui/forms/ObjectTransformationWindow.h"

ObjectTransformationWindow::ObjectTransformationWindow(ControladorUI* controladorUI, QWidget* parent,
							Qt::WindowFlags flags) : Form(controladorUI, parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->conectarSinaisSlots();
}

void ObjectTransformationWindow::show(const String& nomeObjeto) {
	this->nomeObjeto = nomeObjeto;
	QWidget::show();
}

void ObjectTransformationWindow::conectarSinaisSlots() {
	QObject::connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(btnTransform, SIGNAL(clicked()), this, SLOT(transformObject()));
	QObject::connect(radBtnSpecificPoint, SIGNAL(toggled(bool)), this, SLOT(specificPointSelected(bool)));
}

void ObjectTransformationWindow::clearFields(){
	this->fieldScaleFactorX->clear();
	this->fieldScaleFactorY->clear();
	this->fieldScaleFactorZ->clear();
	this->fieldRotateDegree->clear();
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
		this->controladorUI->exibirMensagemErro("Algum campo encontra-se vazio ou contém informação inválida!");
		return;
	}

	double degree, x, y, z;

	if(!this->controladorUI->contemObjeto(this->nomeObjeto)) {
		this->controladorUI->exibirMensagemErro("Nenhum objeto com este nome encontrado!");
		return;
	}

	switch(this->tabTransformations->currentIndex()) {
		case 0: // Escalonamento
			x = this->fieldScaleFactorX->text().toDouble();
			y = this->fieldScaleFactorY->text().toDouble();
			z = 1;//this->fieldScaleFactorZ->text().toDouble();
			this->controladorUI->escalonarObjeto(this->nomeObjeto, x, y, z);
			break;
		case 1: // Rotação
			degree = this->fieldRotateDegree->text().toDouble();

			if(this->radBtnSpecificPoint->isChecked()) {
				x = this->fieldRotatePointX->text().toDouble();
				y = this->fieldRotatePointY->text().toDouble();
				z = 1;//this->fieldRotatePointZ->text().toDouble();
				this->controladorUI->rotacionarObjetoPorPonto(this->nomeObjeto, Ponto("", x, y, z), degree);
			} else {
				this->controladorUI->rotacionarObjetoPeloCentro(this->nomeObjeto, degree);
			}
			break;
		default: // Translação
			x = this->fieldTranslateFactorX->text().toDouble();
			y = this->fieldTranslateFactorY->text().toDouble();
			z = 1;//this->fieldTranslateFactorZ->text().toDouble();
			this->controladorUI->transladarObjeto(this->nomeObjeto, x, y, z);
			break;
	}

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

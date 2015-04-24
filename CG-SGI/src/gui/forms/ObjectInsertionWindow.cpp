#include "gui/forms/ObjectInsertionWindow.h"

ObjectInsertionWindow::ObjectInsertionWindow(ControladorUI* controladorUI, QWidget* parent,
							Qt::WindowFlags flags) : Form(controladorUI, parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->conectarSinaisSlots();
}

void ObjectInsertionWindow::conectarSinaisSlots() {
	QObject::connect(btnColor, SIGNAL(clicked()), this, SLOT(btnSelectColorClicked()));
	QObject::connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(btnInsert, SIGNAL(clicked()), this, SLOT(insertObject()));
	QObject::connect(btnRemovePoint, SIGNAL(clicked()), this, SLOT(removePoligonPoint()));
	QObject::connect(btnInsertPoint, SIGNAL(clicked()), this, SLOT(insertPoligonPoint()));
	QObject::connect(btnRemovePointBSpline, SIGNAL(clicked()), this, SLOT(removeBSplinePoint()));
	QObject::connect(btnInsertPointBSpline, SIGNAL(clicked()), this, SLOT(insertBSplinePoint()));
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
	this->fieldBezierX1->clear();
	this->fieldBezierX2->clear();
	this->fieldBezierX3->clear();
	this->fieldBezierX4->clear();
	this->fieldBezierY1->clear();
	this->fieldBezierY2->clear();
	this->fieldBezierY3->clear();
	this->fieldBezierY4->clear();
	this->fieldBezierZ1->clear();
	this->fieldBezierZ2->clear();
	this->fieldBezierZ3->clear();
	this->fieldBezierZ4->clear();

	while(this->tablePoligonPoints->rowCount() > 0)
		this->tablePoligonPoints->removeRow(0);
	this->insertPoligonPoint();
	this->insertPoligonPoint();
	this->insertPoligonPoint();

	while(this->tableBSplinePoints->rowCount() > 0)
		this->tableBSplinePoints->removeRow(0);
	this->insertBSplinePoint();
	this->insertBSplinePoint();
	this->insertBSplinePoint();
	this->insertBSplinePoint();

	this->tabObjects->setCurrentIndex(0);

	QString style = QString("QPushButton  {"
					"    border-radius: 5px;"
					"    background-color: black }");
	this->btnColor->setStyleSheet(style);
}

bool ObjectInsertionWindow::validateFields() {
	if(this->fieldName->text().isEmpty() || this->fieldName->text().contains(' '))
		return false;

	bool ok, ok1, ok2, ok3;

	switch(this->tabObjects->currentIndex()) {
		case 0:
			this->fieldPointX->text().toDouble(&ok1);
			this->fieldPointY->text().toDouble(&ok2);
			ok3 = true;//this->fieldPointZ->text().toDouble(&ok3);

			return ok1 && ok2 && ok3;
		case 1:
			this->fieldLineX1->text().toDouble(&ok1);
			this->fieldLineY1->text().toDouble(&ok2);
			ok3 = true;//this->fieldLineZ1->text().toDouble(&ok3);
			ok = ok1 && ok2 && ok3;

			this->fieldLineX2->text().toDouble(&ok1);
			this->fieldLineY2->text().toDouble(&ok2);
			ok3 = true;//this->fieldLineZ2->text().toDouble(&ok3);

			return ok && ok1 && ok2 && ok3;
		case 2:
			if(this->tablePoligonPoints->rowCount() < 3)
				return false;

			for(int i = 0; i < this->tablePoligonPoints->rowCount(); i++) {
				QTableWidgetItem *i1, *i2;//, *i3;
				i1 = this->tablePoligonPoints->item(i, 0);
				i2 = this->tablePoligonPoints->item(i, 1);
				//i3 = this->tablePoligonPoints->item(i, 2);

				if(!i1 || !i2)
					return false;

				i1->text().toDouble(&ok1);
				i2->text().toDouble(&ok2);
				//i3->text().toDouble(&ok3);

				if(!(ok1 && ok2))
					return false;
			}
			return true;
		case 3:
			this->fieldBezierX1->text().toDouble(&ok1);
			this->fieldBezierY1->text().toDouble(&ok2);
			ok3 = true;//this->fieldBezierZ1->text().toDouble(&ok3);
			ok = ok1 && ok2 && ok3;

			this->fieldBezierX2->text().toDouble(&ok1);
			this->fieldBezierY2->text().toDouble(&ok2);
			ok3 = true;//this->fieldBezierZ2->text().toDouble(&ok3);
			ok = ok && ok1 && ok2 && ok3;

			this->fieldBezierX3->text().toDouble(&ok1);
			this->fieldBezierY3->text().toDouble(&ok2);
			ok3 = true;//this->fieldBezierZ3->text().toDouble(&ok3);
			ok = ok && ok1 && ok2 && ok3;

			this->fieldBezierX4->text().toDouble(&ok1);
			this->fieldBezierY4->text().toDouble(&ok2);
			ok3 = true;//this->fieldBezierZ4->text().toDouble(&ok3);
			ok = ok && ok1 && ok2 && ok3;
			return ok;
		default:
			if(this->tableBSplinePoints->rowCount() < 3)
				return false;

			for(int i = 0; i < this->tableBSplinePoints->rowCount(); i++) {
				QTableWidgetItem *i1, *i2;//, *i3;
				i1 = this->tableBSplinePoints->item(i, 0);
				i2 = this->tableBSplinePoints->item(i, 1);
				//i3 = this->tableBSplinePoints->item(i, 2);

				if(!i1 || !i2)
					return false;

				i1->text().toDouble(&ok1);
				i2->text().toDouble(&ok2);
				//i3->text().toDouble(&ok3);

				if(!(ok1 && ok2))
					return false;
			}
			return true;
	}
}

void ObjectInsertionWindow::insertObject() {
	if(!this->validateFields()) {
		this->controladorUI->exibirMensagemErro("Algum campo encontra-se vazio ou contém informação inválida!");
		return;
	}

	QList<Ponto> points;
	Ponto p;
	double x, y, z;
	String name = this->fieldName->text().toStdString();
	ObjetoGeometrico::Tipo tipo;

	if(this->controladorUI->contemObjeto(name)) {
		this->controladorUI->exibirMensagemErro("Um objeto com este nome já existe!");
		return;
	}

	switch(this->tabObjects->currentIndex()) {
		case 0:
			x = this->fieldPointX->text().toDouble();
			y = this->fieldPointY->text().toDouble();
			z = 1;//this->fieldPointZ->text().toDouble();
			p = Ponto(name, x, y, z);
			points.insert(0, p);
			tipo = ObjetoGeometrico::PONTO;
			break;
		case 1:
			x = this->fieldLineX1->text().toDouble();
			y = this->fieldLineY1->text().toDouble();
			z = 1;//this->fieldLineZ1->text().toDouble();
			p = Ponto("", x, y, z);
			points.insert(0, p);

			x = this->fieldLineX2->text().toDouble();
			y = this->fieldLineY2->text().toDouble();
			z = 1;//this->fieldLineZ2->text().toDouble();
			p = Ponto("", x, y, z);
			points.insert(1, p);
			tipo = ObjetoGeometrico::RETA;
			break;
		case 2:
			for(int i = 0; i < this->tablePoligonPoints->rowCount(); i++) {
				String nomePonto = this->fieldName->text().toStdString();

				x = this->tablePoligonPoints->item(i, 0)->text().toDouble();
				y = this->tablePoligonPoints->item(i, 1)->text().toDouble();
				z = 1;//this->tablePoligonPoints->item(i, 2)->text().toDouble();

				p = Ponto(nomePonto, x, y, z);
				points.insert(i, p);
			}
			tipo = ObjetoGeometrico::POLIGONO;
			break;
		case 3:
			x = this->fieldBezierX1->text().toDouble();
			y = this->fieldBezierY1->text().toDouble();
			z = 1;//this->fieldBezierZ1->text().toDouble();
			p = Ponto("", x, y, z);
			points.insert(0, p);

			x = this->fieldBezierX2->text().toDouble();
			y = this->fieldBezierY2->text().toDouble();
			z = 1;//this->fieldBezierZ2->text().toDouble();
			p = Ponto("", x, y, z);
			points.insert(1, p);

			x = this->fieldBezierX3->text().toDouble();
			y = this->fieldBezierY3->text().toDouble();
			z = 1;//this->fieldBezierZ3->text().toDouble();
			p = Ponto("", x, y, z);
			points.insert(2, p);

			x = this->fieldBezierX4->text().toDouble();
			y = this->fieldBezierY4->text().toDouble();
			z = 1;//this->fieldBezierZ4->text().toDouble();
			p = Ponto("", x, y, z);
			points.insert(3, p);
			tipo = ObjetoGeometrico::CURVA_BEZIER;
			break;
		default:
			for(int i = 0; i < this->tableBSplinePoints->rowCount(); i++) {
				String nomePonto = this->fieldName->text().toStdString();

				x = this->tableBSplinePoints->item(i, 0)->text().toDouble();
				y = this->tableBSplinePoints->item(i, 1)->text().toDouble();
				z = 1;//this->tableBSplinePoints->item(i, 2)->text().toDouble();

				p = Ponto(nomePonto, x, y, z);
				points.insert(i, p);
			}
			tipo = ObjetoGeometrico::CURVA_BSPLINE;
			break;
	}

	QColor color = this->btnColor->palette().color(this->btnColor->backgroundRole());

	this->controladorUI->inserirObjeto(name, points, tipo, color);
	this->accept();
}

void ObjectInsertionWindow::insertPoligonPoint() {
	this->tablePoligonPoints->insertRow(this->tablePoligonPoints->rowCount());
}

void ObjectInsertionWindow::removePoligonPoint() {
	if(this->tablePoligonPoints->rowCount() > 3) {
		QItemSelectionModel *selectionModel = this->tablePoligonPoints->selectionModel();
		for(QModelIndex index : selectionModel->selectedRows())
			tablePoligonPoints->removeRow(index.row());
	}
}

void ObjectInsertionWindow::insertBSplinePoint() {
	this->tableBSplinePoints->insertRow(this->tableBSplinePoints->rowCount());
}

void ObjectInsertionWindow::removeBSplinePoint() {
	if(this->tableBSplinePoints->rowCount() > 4) {
		QItemSelectionModel *selectionModel = this->tableBSplinePoints->selectionModel();
		for(QModelIndex index : selectionModel->selectedRows())
			tableBSplinePoints->removeRow(index.row());
	}
}

void ObjectInsertionWindow::btnSelectColorClicked() {
	QColor color = QColorDialog::getColor(this->btnColor->palette().color(this->btnColor->backgroundRole()), this);

	QString style = QString("QPushButton  {"
					"    border-radius: 5px;"
					"    background-color: " + color.name() + " }");
	this->btnColor->setStyleSheet(style);
}

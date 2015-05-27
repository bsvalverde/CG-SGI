#include "gui/forms/FormInsercaoObjeto.h"

FormInsercaoObjeto::FormInsercaoObjeto(ControladorUI* controladorUI, QWidget* pai,
							Qt::WindowFlags flags) : Form(controladorUI, pai, flags) {
	this->setupUi(this);
	this->centralizar();
	this->conectarSinaisSlots();
}

void FormInsercaoObjeto::conectarSinaisSlots() {
	QObject::connect(btnCor, SIGNAL(clicked()), this, SLOT(selecionarCorObjeto()));
	QObject::connect(btnCancelar, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(btnInserir, SIGNAL(clicked()), this, SLOT(inserirObjeto()));
	QObject::connect(btnRemoverPontoPoligono, SIGNAL(clicked()), this, SLOT(removerPontoPoligono()));
	QObject::connect(btnInserirPontoPoligono, SIGNAL(clicked()), this, SLOT(inserirPontoPoligono()));
	QObject::connect(btnRemoverPontoBSpline, SIGNAL(clicked()), this, SLOT(removerPontoBSpline()));
	QObject::connect(btnInserirPontoBSpline, SIGNAL(clicked()), this, SLOT(inserirPontoBSpline()));
}

void FormInsercaoObjeto::limparCampos(){
	this->fdNome->clear();
	this->fdPontoX->clear();
	this->fdPontoY->clear();
	this->fdPontoZ->clear();
	this->fdRetaX1->clear();
	this->fdRetaX2->clear();
	this->fdRetaY1->clear();
	this->fdRetaY2->clear();
	this->fdRetaZ1->clear();
	this->fdRetaZ2->clear();
	this->fdBezierX1->clear();
	this->fdBezierX2->clear();
	this->fdBezierX3->clear();
	this->fdBezierX4->clear();
	this->fdBezierY1->clear();
	this->fdBezierY2->clear();
	this->fdBezierY3->clear();
	this->fdBezierY4->clear();
	this->fdBezierZ1->clear();
	this->fdBezierZ2->clear();
	this->fdBezierZ3->clear();
	this->fdBezierZ4->clear();

	while(this->tablePontosPoligono->rowCount() > 0)
		this->tablePontosPoligono->removeRow(0);
	this->inserirPontoPoligono();
	this->inserirPontoPoligono();
	this->inserirPontoPoligono();

	while(this->tablePontosBSpline->rowCount() > 0)
		this->tablePontosBSpline->removeRow(0);
	this->inserirPontoBSpline();
	this->inserirPontoBSpline();
	this->inserirPontoBSpline();
	this->inserirPontoBSpline();

	while(this->tablePontosSuperficieBezier->rowCount() > 0)
		this->tablePontosSuperficieBezier->removeRow(0);

	for(int i = 0; i < 16; i++)
		this->tablePontosSuperficieBezier->insertRow(this->tablePontosSuperficieBezier->rowCount());

	this->tabObjects->setCurrentIndex(0);

	QString style = QString("QPushButton  {"
					"    border-radius: 5px;"
					"    background-color: black }");
	this->btnCor->setStyleSheet(style);
}

bool FormInsercaoObjeto::validarCampos() {
	if(this->fdNome->text().isEmpty() || this->fdNome->text().contains(' '))
		return false;

	bool ok, ok1, ok2, ok3;

	switch(this->tabObjects->currentIndex()) {
		case 0:
			this->fdPontoX->text().toDouble(&ok1);
			this->fdPontoY->text().toDouble(&ok2);
			this->fdPontoZ->text().toDouble(&ok3);

			return ok1 && ok2 && ok3;
		case 1:
			this->fdRetaX1->text().toDouble(&ok1);
			this->fdRetaY1->text().toDouble(&ok2);
			this->fdRetaZ1->text().toDouble(&ok3);
			ok = ok1 && ok2 && ok3;

			this->fdRetaX2->text().toDouble(&ok1);
			this->fdRetaY2->text().toDouble(&ok2);
			this->fdRetaZ2->text().toDouble(&ok3);

			return ok && ok1 && ok2 && ok3;
		case 2:
			if(this->tablePontosPoligono->rowCount() < 3)
				return false;

			for(int i = 0; i < this->tablePontosPoligono->rowCount(); i++) {
				QTableWidgetItem *i1, *i2, *i3;
				i1 = this->tablePontosPoligono->item(i, 0);
				i2 = this->tablePontosPoligono->item(i, 1);
				i3 = this->tablePontosPoligono->item(i, 2);

				if(!i1 || !i2 || !i3)
					return false;

				i1->text().toDouble(&ok1);
				i2->text().toDouble(&ok2);
				i3->text().toDouble(&ok3);

				if(!(ok1 && ok2 && ok3))
					return false;
			}
			return true;
		case 3:
			this->fdBezierX1->text().toDouble(&ok1);
			this->fdBezierY1->text().toDouble(&ok2);
			this->fdBezierZ1->text().toDouble(&ok3);
			ok = ok1 && ok2 && ok3;

			this->fdBezierX2->text().toDouble(&ok1);
			this->fdBezierY2->text().toDouble(&ok2);
			this->fdBezierZ2->text().toDouble(&ok3);
			ok = ok && ok1 && ok2 && ok3;

			this->fdBezierX3->text().toDouble(&ok1);
			this->fdBezierY3->text().toDouble(&ok2);
			this->fdBezierZ3->text().toDouble(&ok3);
			ok = ok && ok1 && ok2 && ok3;

			this->fdBezierX4->text().toDouble(&ok1);
			this->fdBezierY4->text().toDouble(&ok2);
			this->fdBezierZ4->text().toDouble(&ok3);
			ok = ok && ok1 && ok2 && ok3;
			return ok;
		case 4:
			if(this->tablePontosBSpline->rowCount() < 3)
				return false;

			for(int i = 0; i < this->tablePontosBSpline->rowCount(); i++) {
				QTableWidgetItem *i1, *i2, *i3;
				i1 = this->tablePontosBSpline->item(i, 0);
				i2 = this->tablePontosBSpline->item(i, 1);
				i3 = this->tablePontosBSpline->item(i, 2);

				if(!i1 || !i2 || !i3)
					return false;

				i1->text().toDouble(&ok1);
				i2->text().toDouble(&ok2);
				i3->text().toDouble(&ok3);

				if(!(ok1 && ok2 && ok3))
					return false;
			}
			return true;
		default:
			for(int i = 0; i < this->tablePontosSuperficieBezier->rowCount(); i++) {
				QTableWidgetItem *i1, *i2, *i3;
				i1 = this->tablePontosSuperficieBezier->item(i, 0);
				i2 = this->tablePontosSuperficieBezier->item(i, 1);
				i3 = this->tablePontosSuperficieBezier->item(i, 2);

				if(!i1 || !i2 || !i3)
					return false;

				i1->text().toDouble(&ok1);
				i2->text().toDouble(&ok2);
				i3->text().toDouble(&ok3);

				if(!(ok1 && ok2 && ok3))
					return false;
			}
			return true;
	}
}

void FormInsercaoObjeto::inserirObjeto() {
	if(!this->validarCampos()) {
		this->controladorUI->exibirMensagemErro("Algum campo encontra-se vazio ou contém informação inválida!");
		return;
	}

	QList<Ponto> pontos;
	Ponto p;
	double x, y, z;
	String name = this->fdNome->text().toStdString();
	ObjetoGeometrico::Tipo tipo;

	if(this->controladorUI->contemObjeto(name)) {
		this->controladorUI->exibirMensagemErro("Um objeto com este nome já existe!");
		return;
	}

	switch(this->tabObjects->currentIndex()) {
		case 0:
			x = this->fdPontoX->text().toDouble();
			y = this->fdPontoY->text().toDouble();
			z = this->fdPontoZ->text().toDouble();
			p = Ponto(name, x, y, z);
			pontos.insert(0, p);
			tipo = ObjetoGeometrico::PONTO;
			break;
		case 1:
			x = this->fdRetaX1->text().toDouble();
			y = this->fdRetaY1->text().toDouble();
			z = this->fdRetaZ1->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(0, p);

			x = this->fdRetaX2->text().toDouble();
			y = this->fdRetaY2->text().toDouble();
			z = this->fdRetaZ2->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(1, p);
			tipo = ObjetoGeometrico::RETA;
			break;
		case 2:
			for(int i = 0; i < this->tablePontosPoligono->rowCount(); i++) {
				String nomePonto = this->fdNome->text().toStdString();

				x = this->tablePontosPoligono->item(i, 0)->text().toDouble();
				y = this->tablePontosPoligono->item(i, 1)->text().toDouble();
				z = this->tablePontosPoligono->item(i, 2)->text().toDouble();

				p = Ponto(nomePonto, x, y, z);
				pontos.insert(i, p);
			}
			tipo = ObjetoGeometrico::POLIGONO;
			break;
		case 3:
			x = this->fdBezierX1->text().toDouble();
			y = this->fdBezierY1->text().toDouble();
			z = this->fdBezierZ1->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(0, p);

			x = this->fdBezierX2->text().toDouble();
			y = this->fdBezierY2->text().toDouble();
			z = this->fdBezierZ2->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(1, p);

			x = this->fdBezierX3->text().toDouble();
			y = this->fdBezierY3->text().toDouble();
			z = this->fdBezierZ3->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(2, p);

			x = this->fdBezierX4->text().toDouble();
			y = this->fdBezierY4->text().toDouble();
			z = this->fdBezierZ4->text().toDouble();
			p = Ponto("", x, y, z);
			pontos.insert(3, p);
			tipo = ObjetoGeometrico::CURVA_BEZIER;
			break;
		case 4:
			for(int i = 0; i < this->tablePontosBSpline->rowCount(); i++) {
				String nomePonto = this->fdNome->text().toStdString();

				x = this->tablePontosBSpline->item(i, 0)->text().toDouble();
				y = this->tablePontosBSpline->item(i, 1)->text().toDouble();
				z = this->tablePontosBSpline->item(i, 2)->text().toDouble();

				p = Ponto(nomePonto, x, y, z);
				pontos.insert(i, p);
			}
			tipo = ObjetoGeometrico::CURVA_BSPLINE;
			break;
		default:
			for(int i = 0; i < this->tablePontosSuperficieBezier->rowCount(); i++) {
				String nomePonto = this->fdNome->text().toStdString();

				x = this->tablePontosSuperficieBezier->item(i, 0)->text().toDouble();
				y = this->tablePontosSuperficieBezier->item(i, 1)->text().toDouble();
				z = this->tablePontosSuperficieBezier->item(i, 2)->text().toDouble();

				p = Ponto(nomePonto, x, y, z);
				pontos.insert(i, p);
			}
			tipo = ObjetoGeometrico::SUPERFICIE_BEZIER;
			break;
	}

	QColor cor = this->btnCor->palette().color(this->btnCor->backgroundRole());

	this->controladorUI->inserirObjeto(name, pontos, tipo, cor);
	this->accept();
}

void FormInsercaoObjeto::inserirPontoPoligono() {
	this->tablePontosPoligono->insertRow(this->tablePontosPoligono->rowCount());
}

void FormInsercaoObjeto::removerPontoPoligono() {
	if(this->tablePontosPoligono->rowCount() > 3) {
		QItemSelectionModel *modeloSelecao = this->tablePontosPoligono->selectionModel();
		for(QModelIndex indice : modeloSelecao->selectedRows())
			tablePontosPoligono->removeRow(indice.row());
	}
}

void FormInsercaoObjeto::inserirPontoBSpline() {
	this->tablePontosBSpline->insertRow(this->tablePontosBSpline->rowCount());
}

void FormInsercaoObjeto::removerPontoBSpline() {
	if(this->tablePontosBSpline->rowCount() > 4) {
		QItemSelectionModel *modeloSelecao = this->tablePontosBSpline->selectionModel();
		for(QModelIndex indice : modeloSelecao->selectedRows())
			tablePontosBSpline->removeRow(indice.row());
	}
}

void FormInsercaoObjeto::selecionarCorObjeto() {
	QColor cor = QColorDialog::getColor(this->btnCor->palette().color(this->btnCor->backgroundRole()), this);

	QString estilo = QString("QPushButton  {"
					"    border-radius: 5px;"
					"    background-color: " + cor.name() + " }");
	this->btnCor->setStyleSheet(estilo);
}

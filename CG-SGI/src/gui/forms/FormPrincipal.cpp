#include "gui/forms/FormPrincipal.h"

FormPrincipal::FormPrincipal(ControladorUI* controladorUI, QDialog* parent,
		Qt::WindowFlags flags) :
		QMainWindow(parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
	this->initializeMenuBar();
	this->zoomValue = this->sliderControleZoom->value();
	this->rotationValue = this->dialBtnRotacao->value();
	this->controladorUI = controladorUI;
	this->viewport = new Viewport(this->graphicsView, 475, 555);
}

FormPrincipal::~FormPrincipal() {
	if (this->viewport)
		delete this->viewport;
}

void FormPrincipal::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}

void FormPrincipal::initializeMenuBar() {
	QMenu* menuArquivo = menuBar()->addMenu("&Arquivo");
	QAction* itemImportar = menuArquivo->addAction("&Importar cena...");
	QAction* itemExportar = menuArquivo->addAction("&Exportar cena...");
	QAction* itemLimparCena = menuArquivo->addAction("&Limpar cena");
	menuArquivo->addSeparator();
	QAction* itemSair = menuArquivo->addAction("&Sair");

	QAction* itemAtalhos = menuBar()->addAction("A&talhos");
	QAction* itemSobre = menuBar()->addAction("&Sobre");

	QObject::connect(itemImportar, SIGNAL(triggered()), this, SLOT(btnImportScene()));
	QObject::connect(itemExportar, SIGNAL(triggered()), this, SLOT(btnExportScene()));
	QObject::connect(itemLimparCena, SIGNAL(triggered()), this,	SLOT(btnCleanScene()));
	QObject::connect(itemSair, SIGNAL(triggered()), this, SLOT(encerrar()));
	QObject::connect(itemAtalhos, SIGNAL(triggered()), this, SLOT(btnAtalhos()));
	QObject::connect(itemSobre, SIGNAL(triggered()), this, SLOT(btnSobre()));
	this->close();

	menuBar()->setVisible(true);
}

void FormPrincipal::encerrar() {
	if (this->controladorUI->requisitarConfirmacaoUsuario(
			"Você tem certeza que deseja encerrar o sistema?"))
		QWidget::close();
}

ControladorUI* FormPrincipal::getControladorUI() {
	return this->controladorUI;
}

void FormPrincipal::updateObjects(const QList<ObjetoGeometrico*>& objects) {
	// Remover todos os objetos da tabela
	while (this->displayFile->rowCount() > 0)
		this->displayFile->removeRow(0);

	// Inserir todos os objetos atualizados na tabela
	for (ObjetoGeometrico* obj : objects) {
		this->displayFile->insertRow(this->displayFile->rowCount());
		QTableWidgetItem* type = new QTableWidgetItem(
				QString::fromStdString(obj->getTipoString()));
		QTableWidgetItem* name = new QTableWidgetItem(
				QString::fromStdString(obj->getNome()));
		this->displayFile->setItem(this->displayFile->rowCount() - 1, 0,
				type);
		this->displayFile->setItem(this->displayFile->rowCount() - 1, 1,
				name);
	}

	this->viewport->atualizarObjetos(objects);
}

void FormPrincipal::connectSignalsAndSlots() {
	QObject::connect(btnZoomIn, SIGNAL(pressed()), this,
			SLOT(btnZoomInPressed()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this,
			SLOT(btnZoomOutPressed()));
	QObject::connect(sliderControleZoom, SIGNAL(valueChanged(int)), this,
			SLOT(zoomControlValueChanged(int)));
	QObject::connect(btnNavUp, SIGNAL(clicked()), this,
			SLOT(btnNavigationUpPressed()));
	QObject::connect(btnNavLeft, SIGNAL(clicked()), this,
			SLOT(btnNavigationLeftPressed()));
	QObject::connect(btnNavCenter, SIGNAL(clicked()), this,
			SLOT(btnNavigationCenterPressed()));
	QObject::connect(btnNavRight, SIGNAL(clicked()), this,
			SLOT(btnNavigationRightPressed()));
	QObject::connect(btnNavDown, SIGNAL(clicked()), this,
			SLOT(btnNavigationDownPressed()));
	QObject::connect(btnInserirObjeto, SIGNAL(clicked()), this,
			SLOT(btnInsertObjectClicked()));
	QObject::connect(btnRemoverObjeto, SIGNAL(clicked()), this,
			SLOT(btnRemoveObjectClicked()));
	QObject::connect(btnTransformarObjeto, SIGNAL(clicked()), this,
			SLOT(btnTransformObjectClicked()));
	QObject::connect(dialBtnRotacao, SIGNAL(valueChanged(int)), this,
			SLOT(btnRotation(int)));
	QObject::connect(radBtnClippingCS, SIGNAL(toggled(bool)), this,
			SLOT(btnClippingCSToggled(bool)));
}

void FormPrincipal::btnZoomInPressed() {
	int position = this->sliderControleZoom->value();
	this->sliderControleZoom->setValue(position + 2);
}

void FormPrincipal::btnZoomOutPressed() {
	int position = this->sliderControleZoom->value();
	this->sliderControleZoom->setValue(position - 2);
}

void FormPrincipal::zoomControlValueChanged(int currentValue) {
	int factor = currentValue - this->zoomValue;

	this->zoomValue = currentValue;
	this->controladorUI->redimensionarWindow(factor);
}

void FormPrincipal::btnNavigationUpPressed() {
	this->controladorUI->navegarNoMundo(Mundo::CIMA, 0.1);
}

void FormPrincipal::btnNavigationLeftPressed() {
	this->controladorUI->navegarNoMundo(Mundo::ESQUERDA, 0.1);
}

void FormPrincipal::btnNavigationCenterPressed() {
	this->sliderControleZoom->setValue(50);
	this->zoomValue = 50;
	this->dialBtnRotacao->setValue(0);
	this->rotationValue = 0;
	this->controladorUI->reiniciarWindow();
}

void FormPrincipal::btnNavigationRightPressed() {
	this->controladorUI->navegarNoMundo(Mundo::DIREITA, 0.1);
}

void FormPrincipal::btnNavigationDownPressed() {
	this->controladorUI->navegarNoMundo(Mundo::BAIXO, 0.1);
}

void FormPrincipal::btnRotation(int currentValue) {
	int angulo = currentValue - this->rotationValue;
	this->rotationValue = currentValue;

	this->controladorUI->rotacionarWindow(angulo);
}

void FormPrincipal::btnInsertObjectClicked() {
	this->controladorUI->exibirObjectInsertionWindow();
}

void FormPrincipal::btnRemoveObjectClicked() {
	QItemSelectionModel *selectionModel = this->displayFile->selectionModel();
	String objectName = "";

	if (selectionModel->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro(
				"É necessário selecionar um objeto para ser removido!");
		return;
	}

	for (QModelIndex index : selectionModel->selectedRows()) {
		QTableWidgetItem *item = this->displayFile->item(index.row(), 1);

		if (item)
			objectName = item->text().toStdString();

		this->displayFile->removeRow(index.row());
	}

	this->controladorUI->removerObjeto(objectName);
	this->displayFile->setCurrentCell(0, 0);
}

void FormPrincipal::btnTransformObjectClicked() {
	QItemSelectionModel *selectionModel = this->displayFile->selectionModel();
	String objectName = "";

	if (selectionModel->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro(
				"É necessário selecionar um objeto para aplicar uma transformação!");
		return;
	}

	for (QModelIndex index : selectionModel->selectedRows()) {
		QTableWidgetItem *item = this->displayFile->item(index.row(), 1);

		if (item)
			objectName = item->text().toStdString();
	}

	this->controladorUI->exibirObjectTransformationWindow(objectName);
}

void FormPrincipal::btnImportScene() {
	String arquivo = QFileDialog::getOpenFileName(0,
			"Selecionar arquivo Wavefront (OBJ)", "", "*.obj").toStdString();

	if (arquivo.compare("") == 0) // Usuário cancelou
		return;

	this->controladorUI->importarCena(arquivo);
}

void FormPrincipal::btnExportScene() {
	String arquivo = QFileDialog::getSaveFileName(0,
			"Salvar arquivo Wavefront (OBJ)", "", "*.obj").toStdString();

	if (arquivo.compare("") == 0) // Usuário cancelou
		return;

	if(arquivo.find_last_of(".obj") == arquivo.length() - 1) {
		arquivo = arquivo.substr(0, arquivo.length() - 4);
	}

	arquivo += ".obj";

	this->controladorUI->exportarCena(arquivo);
}

void FormPrincipal::btnCleanScene() {
	if(this->controladorUI->requisitarConfirmacaoUsuario("Você tem certeza que deseja limpar a cena?")) {
		this->controladorUI->removerObjetosMundo();
		this->btnNavigationCenterPressed();
	}
}

void FormPrincipal::btnAtalhos() {
	this->controladorUI->exibirJanelaAtalhos();
}

void FormPrincipal::btnSobre() {
	QMessageBox msg;
	msg.information(this, "Sobre", "Sistema Gráfico Interativo desenvolvido na discplina "
			"de Computação Gráfica do curso de Ciência da Computação da "
			"Universidade Federal de Santa Catarina pelos alunos "
			"Bernardo de Sousa Valverde e Lucas May Petry.");
}

void FormPrincipal::btnClippingCSToggled(bool cohenSutherland) {
	if(cohenSutherland) {
		this->viewport->setAlgoritmoClippingLinhas(Clipping::COHEN_SUTHERLAND);
	} else {
		this->viewport->setAlgoritmoClippingLinhas(Clipping::LIANG_BARSKY);
	}
}

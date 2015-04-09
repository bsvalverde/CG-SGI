#include "gui/forms/MainWindow.h"

MainWindow::MainWindow(ControladorUI* controladorUI, QDialog* parent,
		Qt::WindowFlags flags) :
		QMainWindow(parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
	this->initializeMenuBar();
	this->zoomValue = this->zoomControl->value();
	this->rotationValue = this->dialRotation->value();
	this->controladorUI = controladorUI;
	this->viewport = new Viewport(this->graphicsView, 510, 475);
}

MainWindow::~MainWindow() {
	if (this->viewport)
		delete this->viewport;
}

void MainWindow::moveToCenter() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}

void MainWindow::initializeMenuBar() {
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

void MainWindow::encerrar() {
	if (this->controladorUI->requisitarConfirmacaoUsuario(
			"Você tem certeza que deseja encerrar o sistema?"))
		QWidget::close();
}

ControladorUI* MainWindow::getControladorUI() {
	return this->controladorUI;
}

void MainWindow::updateObjects(const QList<ObjetoGeometrico*>& objects) {
	// Remover todos os objetos da tabela
	while (this->tableObjects->rowCount() > 0)
		this->tableObjects->removeRow(0);

	// Inserir todos os objetos atualizados na tabela
	for (ObjetoGeometrico* obj : objects) {
		this->tableObjects->insertRow(this->tableObjects->rowCount());
		QTableWidgetItem* type = new QTableWidgetItem(
				QString::fromStdString(obj->getTipoString()));
		QTableWidgetItem* name = new QTableWidgetItem(
				QString::fromStdString(obj->getNome()));
		this->tableObjects->setItem(this->tableObjects->rowCount() - 1, 0,
				type);
		this->tableObjects->setItem(this->tableObjects->rowCount() - 1, 1,
				name);
	}

	this->viewport->atualizarObjetos(objects);
}

void MainWindow::connectSignalsAndSlots() {
	QObject::connect(btnZoomIn, SIGNAL(pressed()), this,
			SLOT(btnZoomInPressed()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this,
			SLOT(btnZoomOutPressed()));
	QObject::connect(zoomControl, SIGNAL(valueChanged(int)), this,
			SLOT(zoomControlValueChanged(int)));
	QObject::connect(btnUp, SIGNAL(clicked()), this,
			SLOT(btnNavigationUpPressed()));
	QObject::connect(btnLeft, SIGNAL(clicked()), this,
			SLOT(btnNavigationLeftPressed()));
	QObject::connect(btnCenter, SIGNAL(clicked()), this,
			SLOT(btnNavigationCenterPressed()));
	QObject::connect(btnRight, SIGNAL(clicked()), this,
			SLOT(btnNavigationRightPressed()));
	QObject::connect(btnDown, SIGNAL(clicked()), this,
			SLOT(btnNavigationDownPressed()));
	QObject::connect(btnInsertObject, SIGNAL(clicked()), this,
			SLOT(btnInsertObjectClicked()));
	QObject::connect(btnRemoveObject, SIGNAL(clicked()), this,
			SLOT(btnRemoveObjectClicked()));
	QObject::connect(btnTransformObject, SIGNAL(clicked()), this,
			SLOT(btnTransformObjectClicked()));
	QObject::connect(dialRotation, SIGNAL(valueChanged(int)), this,
			SLOT(btnRotation(int)));
	QObject::connect(radBtnClippingCS, SIGNAL(toggled(bool)), this,
			SLOT(btnClippingCSToggled(bool)));
}

void MainWindow::btnZoomInPressed() {
	int position = this->zoomControl->value();
	this->zoomControl->setValue(position + 2);
}

void MainWindow::btnZoomOutPressed() {
	int position = this->zoomControl->value();
	this->zoomControl->setValue(position - 2);
}

void MainWindow::zoomControlValueChanged(int currentValue) {
	int factor = currentValue - this->zoomValue;

	this->zoomValue = currentValue;
	this->controladorUI->redimensionarWindow(factor);
}

void MainWindow::btnNavigationUpPressed() {
	this->controladorUI->navegarNoMundo(Mundo::CIMA, 0.1);
}

void MainWindow::btnNavigationLeftPressed() {
	this->controladorUI->navegarNoMundo(Mundo::ESQUERDA, 0.1);
}

void MainWindow::btnNavigationCenterPressed() {
	this->zoomControl->setValue(50);
	this->zoomValue = 50;
	this->dialRotation->setValue(0);
	this->rotationValue = 0;
	this->controladorUI->reiniciarWindow();
}

void MainWindow::btnNavigationRightPressed() {
	this->controladorUI->navegarNoMundo(Mundo::DIREITA, 0.1);
}

void MainWindow::btnNavigationDownPressed() {
	this->controladorUI->navegarNoMundo(Mundo::BAIXO, 0.1);
}

void MainWindow::btnRotation(int currentValue) {
	int angulo = currentValue - this->rotationValue;
	this->rotationValue = currentValue;

	this->controladorUI->rotacionarWindow(angulo);
}

void MainWindow::btnInsertObjectClicked() {
	this->controladorUI->exibirObjectInsertionWindow();
}

void MainWindow::btnRemoveObjectClicked() {
	QItemSelectionModel *selectionModel = this->tableObjects->selectionModel();
	String objectName = "";

	if (selectionModel->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro(
				"É necessário selecionar um objeto para ser removido!");
		return;
	}

	for (QModelIndex index : selectionModel->selectedRows()) {
		QTableWidgetItem *item = this->tableObjects->item(index.row(), 1);

		if (item)
			objectName = item->text().toStdString();

		this->tableObjects->removeRow(index.row());
	}

	this->controladorUI->removerObjeto(objectName);
}

void MainWindow::btnTransformObjectClicked() {
	QItemSelectionModel *selectionModel = this->tableObjects->selectionModel();
	String objectName = "";

	if (selectionModel->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro(
				"É necessário selecionar um objeto para aplicar uma transformação!");
		return;
	}

	for (QModelIndex index : selectionModel->selectedRows()) {
		QTableWidgetItem *item = this->tableObjects->item(index.row(), 1);

		if (item)
			objectName = item->text().toStdString();
	}

	this->controladorUI->exibirObjectTransformationWindow(objectName);
}

void MainWindow::btnImportScene() {
	String arquivo = QFileDialog::getOpenFileName(0,
			"Selecionar arquivo Wavefront (OBJ)", "", "*.obj").toStdString();

	if (arquivo.compare("") == 0) // Usuário cancelou
		return;

	this->controladorUI->importarCena(arquivo);
}

void MainWindow::btnExportScene() {
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

void MainWindow::btnCleanScene() {
	if(this->controladorUI->requisitarConfirmacaoUsuario("Você tem certeza que deseja limpar a cena?"))
		this->updateObjects(QList<ObjetoGeometrico*>());
}

void MainWindow::btnAtalhos() {
	this->controladorUI->exibirJanelaAtalhos();
}

void MainWindow::btnSobre() {
	QMessageBox msg;
	msg.information(this, "Sobre", "Sistema Gráfico Interativo desenvolvido na discplina "
			"de Computação Gráfica do curso de Ciência da Computação da "
			"Universidade Federal de Santa Catarina.\n\n"
			":: Algoritmos Implementados ::\n\n"
			"Cohen-Sutherland (clipping de retas)\n"
			"Liang-Barsky (clipping de retas)\n"
			"Sutherland-Hodgeman (clipping de polígonos)");
}

void MainWindow::btnClippingCSToggled(bool cohenSutherland) {
	if(cohenSutherland) {
		this->viewport->setAlgoritmoClippingLinhas(Clipping::COHEN_SUTHERLAND);
	} else {
		this->viewport->setAlgoritmoClippingLinhas(Clipping::LIANG_BARSKY);
	}
}

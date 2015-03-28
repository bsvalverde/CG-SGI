#include "gui/forms/MainWindow.h"

MainWindow::MainWindow(ControladorUI* controladorUI, QDialog* parent,
						Qt::WindowFlags flags) : QMainWindow(parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
	this->initializeMenuBar();
    this->zoomValue = this->zoomControl->value();
    this->controladorUI = controladorUI;
    this->viewport = new Viewport(this->graphicsView, 510, 475);
}

MainWindow::~MainWindow() {
	if(this->viewport)
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
	menuArquivo->addSeparator();
	QAction* itemSair = menuArquivo->addAction("&Sair");

	QObject::connect(itemImportar, SIGNAL(triggered()), this, SLOT(btnImportScene()));
	QObject::connect(itemExportar, SIGNAL(triggered()), this, SLOT(btnExportScene()));
	QObject::connect(itemSair, SIGNAL(triggered()), this, SLOT(encerrar()));
	this->close();

	menuBar()->setVisible(true);
}

void MainWindow::encerrar() {
	if(this->controladorUI->requisitarConfirmacaoUsuario("Você tem certeza que deseja encerrar o sistema?"))
		QWidget::close();
}

ControladorUI* MainWindow::getControladorUI() {
	return this->controladorUI;
}

void MainWindow::updateObjects(const QList<ObjetoGeometrico*>& objects) {
	// Remover todos os objetos da tabela
	while(this->tableObjects->rowCount() > 0)
		this->tableObjects->removeRow(0);

	// Inserir todos os objetos atualizados na tabela
	for(ObjetoGeometrico* obj : objects) {
		this->tableObjects->insertRow(this->tableObjects->rowCount());
		QTableWidgetItem* type = new QTableWidgetItem(QString::fromStdString(obj->getTipoString()));
		QTableWidgetItem* name = new QTableWidgetItem(QString::fromStdString(obj->getNome()));
		this->tableObjects->setItem(this->tableObjects->rowCount() - 1, 0, type);
		this->tableObjects->setItem(this->tableObjects->rowCount() - 1, 1, name);
	}

	this->viewport->atualizarObjetos(objects);
}

void MainWindow::connectSignalsAndSlots() {
	QObject::connect(btnZoomIn, SIGNAL(pressed()), this, SLOT(btnZoomInPressed()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this, SLOT(btnZoomOutPressed()));
	QObject::connect(zoomControl, SIGNAL(valueChanged(int)), this, SLOT(zoomControlValueChanged(int)));
	QObject::connect(btnUp, SIGNAL(clicked()), this, SLOT(btnNavigationUpPressed()));
	QObject::connect(btnLeft, SIGNAL(clicked()), this, SLOT(btnNavigationLeftPressed()));
	QObject::connect(btnCenter, SIGNAL(clicked()), this, SLOT(btnNavigationCenterPressed()));
	QObject::connect(btnRight, SIGNAL(clicked()), this, SLOT(btnNavigationRightPressed()));
	QObject::connect(btnDown, SIGNAL(clicked()), this, SLOT(btnNavigationDownPressed()));
	QObject::connect(btnRotateLeft, SIGNAL(clicked()), this, SLOT(btnRotateLeftPressed()));
	QObject::connect(btnRotateRight, SIGNAL(clicked()), this, SLOT(btnRotateRightPressed()));
	QObject::connect(btnInsertObject, SIGNAL(clicked()), this, SLOT(btnInsertObjectClicked()));
	QObject::connect(btnRemoveObject, SIGNAL(clicked()), this, SLOT(btnRemoveObjectClicked()));
	QObject::connect(btnTransformObject, SIGNAL(clicked()), this, SLOT(btnTransformObjectClicked()));
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
	double zoomFactor = (double) 1 / ((factor * 0.1) + 1);

	if(factor < 0)
		zoomFactor = (double) (factor * -0.1) + 1;

	this->zoomValue = currentValue;
	this->controladorUI->redimensionarWindow(zoomFactor);
}

void MainWindow::btnNavigationUpPressed() {
	this->controladorUI->navegarNoMundo(Mundo::CIMA, 0.1);
}

void MainWindow::btnNavigationLeftPressed() {
	this->controladorUI->navegarNoMundo(Mundo::ESQUERDA, 0.1);
}

void MainWindow::btnNavigationCenterPressed() {
	// Nothing
}

void MainWindow::btnNavigationRightPressed() {
	this->controladorUI->navegarNoMundo(Mundo::DIREITA, 0.1);
}

void MainWindow::btnNavigationDownPressed() {
	this->controladorUI->navegarNoMundo(Mundo::BAIXO, 0.1);
}

void MainWindow::btnRotateLeftPressed() {
	this->controladorUI->rotacionarWindow(-30);
}

void MainWindow::btnRotateRightPressed() {
	this->controladorUI->rotacionarWindow(30);
}

void MainWindow::btnInsertObjectClicked() {
	this->controladorUI->exibirObjectInsertionWindow();
}

void MainWindow::btnRemoveObjectClicked() {
	QItemSelectionModel *selectionModel = this->tableObjects->selectionModel();
	String objectName = "";

	if(selectionModel->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro("É necessário selecionar um objeto para ser removido!");
		return;
	}

	for(QModelIndex index : selectionModel->selectedRows()) {
		QTableWidgetItem *item = this->tableObjects->item(index.row(), 1);

		if(item)
			objectName = item->text().toStdString();

	    this->tableObjects->removeRow(index.row());
	}

	this->controladorUI->removerObjeto(objectName);
}

void MainWindow::btnTransformObjectClicked() {
	QItemSelectionModel *selectionModel = this->tableObjects->selectionModel();
	String objectName = "";

	if(selectionModel->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro("É necessário selecionar um objeto para aplicar uma transformação!");
		return;
	}

	for(QModelIndex index : selectionModel->selectedRows()) {
		QTableWidgetItem *item = this->tableObjects->item(index.row(), 1);

		if(item)
			objectName = item->text().toStdString();
	}

	this->controladorUI->exibirObjectTransformationWindow(objectName);
}

void MainWindow::btnImportScene() {

}

void MainWindow::btnExportScene() {

}

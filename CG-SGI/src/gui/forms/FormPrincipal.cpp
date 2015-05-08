#include "gui/forms/FormPrincipal.h"
#include "persistencia/ArquivoOBJ.h"

FormPrincipal::FormPrincipal(ControladorUI* controladorUI, QDialog* pai,
		Qt::WindowFlags flags) :
		QMainWindow(pai, flags) {
	this->setupUi(this);
	this->centralizar();
	this->conectarSinaisSlots();
	this->inicializarMenu();
	this->valorZoom = this->sliderControleZoom->value();
	this->valorRotacaoX = this->dialBtnRotacao->value();
	this->valorRotacaoY = this->dialBtnRotacao->value();
	this->valorRotacaoZ = this->dialBtnRotacao->value();
	this->controladorUI = controladorUI;
	this->viewport = new Viewport(this->graphicsView, 475, 555);
}

FormPrincipal::~FormPrincipal() {
	if (this->viewport)
		delete this->viewport;
}

void FormPrincipal::centralizar() {
	QRect position = frameGeometry();
	position.moveCenter(QDesktopWidget().availableGeometry().center());
	move(position.topLeft());
}

ControladorUI* FormPrincipal::getControladorUI() {
	return this->controladorUI;
}

void FormPrincipal::atualizarCena(const QList<ObjetoGeometrico*>& objetos) {
	// Remover todos os objetos da tabela
	while (this->displayFile->rowCount() > 0)
		this->displayFile->removeRow(0);

	// Inserir todos os objetos atualizados na tabela
	for (ObjetoGeometrico* obj : objetos) {
		this->displayFile->insertRow(this->displayFile->rowCount());
		QTableWidgetItem* tipo = new QTableWidgetItem(
				QString::fromStdString(obj->getTipoString()));
		QTableWidgetItem* nome = new QTableWidgetItem(
				QString::fromStdString(obj->getNome()));
		this->displayFile->setItem(this->displayFile->rowCount() - 1, 0,
				tipo);
		this->displayFile->setItem(this->displayFile->rowCount() - 1, 1,
				nome);
	}

	this->viewport->atualizarCena(objetos);
}

void FormPrincipal::conectarSinaisSlots() {
	QObject::connect(btnZoomIn, SIGNAL(pressed()), this,
			SLOT(zoomIn()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this,
			SLOT(zoomOut()));
	QObject::connect(sliderControleZoom, SIGNAL(valueChanged(int)), this,
			SLOT(atualizarZoom(int)));
	QObject::connect(btnNavUp, SIGNAL(clicked()), this,
			SLOT(navegarCima()));
	QObject::connect(btnNavLeft, SIGNAL(clicked()), this,
			SLOT(navegarEsquerda()));
	QObject::connect(btnNavCenter, SIGNAL(clicked()), this,
			SLOT(reiniciarVisualizacao()));
	QObject::connect(btnNavRight, SIGNAL(clicked()), this,
			SLOT(navegarDireita()));
	QObject::connect(btnNavDown, SIGNAL(clicked()), this,
			SLOT(navegarBaixo()));
	QObject::connect(btnInserirObjeto, SIGNAL(clicked()), this,
			SLOT(inserirObjeto()));
	QObject::connect(btnRemoverObjeto, SIGNAL(clicked()), this,
			SLOT(removerObjeto()));
	QObject::connect(btnTransformarObjeto, SIGNAL(clicked()), this,
			SLOT(transformarObjeto()));
	QObject::connect(dialBtnRotacao, SIGNAL(valueChanged(int)), this,
			SLOT(rotacionarVisualizacao(int)));
	QObject::connect(radBtnClippingCS, SIGNAL(toggled(bool)), this,
			SLOT(atualizarAlgoritmoClipping(bool)));
	QObject::connect(radBtnProjecaoParalela, SIGNAL(toggled(bool)), this,
			SLOT(atualizarTipoProjecao(bool)));
	QObject::connect(radBtnRotacaoEixoX, SIGNAL(toggled(bool)), this,
			SLOT(atualizarEixoRotacao(bool)));
	QObject::connect(radBtnRotacaoEixoY, SIGNAL(toggled(bool)), this,
			SLOT(atualizarEixoRotacao(bool)));
	QObject::connect(radBtnRotacaoEixoZ, SIGNAL(toggled(bool)), this,
			SLOT(atualizarEixoRotacao(bool)));
}

void FormPrincipal::inicializarMenu() {
	QMenu* menuArquivo = menuBar()->addMenu("&Arquivo");

	QAction* itemImportar = menuArquivo->addAction("&Importar cena...");
	itemImportar->setShortcut(QKeySequence("CTRL+SHIFT+I", QKeySequence::NativeText));
	QMenu* itemImportarPre = menuArquivo->addMenu("Importar cena &pré-definida");
	QAction* itemCenaBasicMan = itemImportarPre->addAction("Basic Man");
	itemCenaBasicMan->setData(QString::fromStdString(ArquivoOBJ::BASIC_MAN));
	QAction* itemCenaCristo = itemImportarPre->addAction("Cristo Redentor");
	itemCenaCristo->setData(QString::fromStdString(ArquivoOBJ::CRISTO_REDENTOR));
	QAction* itemCenaDinoMech= itemImportarPre->addAction("Dino-Mech");
	itemCenaDinoMech->setData(QString::fromStdString(ArquivoOBJ::DINO_MECH));
	QAction* itemCenaSubZero = itemImportarPre->addAction("Sub-Zero");
	itemCenaSubZero->setData(QString::fromStdString(ArquivoOBJ::SUB_ZERO));

	QAction* itemExportar = menuArquivo->addAction("&Exportar cena...");
	itemExportar->setShortcut(QKeySequence("CTRL+SHIFT+E", QKeySequence::NativeText));
	QAction* itemLimparCena = menuArquivo->addAction("&Limpar cena");
	itemLimparCena->setShortcut(QKeySequence("CTRL+SHIFT+L", QKeySequence::NativeText));
	menuArquivo->addSeparator();
	QAction* itemSair = menuArquivo->addAction("&Sair");
	itemSair->setShortcut(QKeySequence("CTRL+SHIFT+S", QKeySequence::NativeText));

	QAction* itemAtalhos = menuBar()->addAction("Ata&lhos");
	QAction* itemSobre = menuBar()->addAction("&Sobre");

	QObject::connect(itemImportar, SIGNAL(triggered()), this, SLOT(importarCena()));
	QObject::connect(itemExportar, SIGNAL(triggered()), this, SLOT(exportarCena()));
	QObject::connect(itemLimparCena, SIGNAL(triggered()), this,	SLOT(limparCena()));
	QObject::connect(itemSair, SIGNAL(triggered()), this, SLOT(encerrarSistema()));
	QObject::connect(itemAtalhos, SIGNAL(triggered()), this, SLOT(atalhosSistema()));
	QObject::connect(itemSobre, SIGNAL(triggered()), this, SLOT(sobreSistema()));
	QObject::connect(itemCenaBasicMan, SIGNAL(triggered()), this, SLOT(importarCenaPreDefinida()));
	QObject::connect(itemCenaCristo, SIGNAL(triggered()), this, SLOT(importarCenaPreDefinida()));
	QObject::connect(itemCenaDinoMech, SIGNAL(triggered()), this, SLOT(importarCenaPreDefinida()));
	QObject::connect(itemCenaSubZero, SIGNAL(triggered()), this, SLOT(importarCenaPreDefinida()));

	menuBar()->setVisible(true);
}

void FormPrincipal::zoomIn() {
	int posicao = this->sliderControleZoom->value();
	this->sliderControleZoom->setValue(posicao + 2);
}

void FormPrincipal::zoomOut() {
	int posicao = this->sliderControleZoom->value();
	this->sliderControleZoom->setValue(posicao - 2);
}

void FormPrincipal::atualizarZoom(int valorAtual) {
	int fator = valorAtual - this->valorZoom;

	this->valorZoom = valorAtual;
	this->controladorUI->redimensionarWindow(fator);
}

void FormPrincipal::navegarCima() {
	this->controladorUI->navegarNoMundo(Mundo::CIMA, 3 / (this->valorZoom * 0.02));
}

void FormPrincipal::navegarEsquerda() {
	this->controladorUI->navegarNoMundo(Mundo::ESQUERDA, 3 / (this->valorZoom * 0.02));
}

void FormPrincipal::navegarDireita() {
	this->controladorUI->navegarNoMundo(Mundo::DIREITA, 3 / (this->valorZoom * 0.02));
}

void FormPrincipal::navegarBaixo() {
	this->controladorUI->navegarNoMundo(Mundo::BAIXO, 3 / (this->valorZoom * 0.02));
}

void FormPrincipal::rotacionarVisualizacao(int valorAtual) {
	int angulo = 0;
	Mundo::Eixo eixo = Mundo::EIXO_Z;

	if(radBtnRotacaoEixoX->isChecked()) { // Eixo X
		angulo = valorAtual - this->valorRotacaoX;
		this->valorRotacaoX = valorAtual;
		eixo = Mundo::EIXO_X;
	} else if(radBtnRotacaoEixoY->isChecked()) { // Eixo Y
		angulo = valorAtual - this->valorRotacaoY;
		this->valorRotacaoY = valorAtual;
		eixo = Mundo::EIXO_Y;
	} else { // Eixo Z
		angulo = valorAtual - this->valorRotacaoZ;
		this->valorRotacaoZ = valorAtual;
	}

	this->controladorUI->rotacionarWindow(angulo, eixo);
}

void FormPrincipal::reiniciarVisualizacao() {
	QObject::disconnect(sliderControleZoom, SIGNAL(valueChanged(int)), this,
			SLOT(atualizarZoom(int)));
	QObject::disconnect(dialBtnRotacao, SIGNAL(valueChanged(int)), this,
			SLOT(rotacionarVisualizacao(int)));

	this->valorZoom = 50;
	this->valorRotacaoX = 0;
	this->valorRotacaoY = 0;
	this->valorRotacaoZ = 0;
	this->sliderControleZoom->setValue(50);
	this->dialBtnRotacao->setValue(0);
	this->radBtnRotacaoEixoX->setChecked(true);

	QObject::connect(sliderControleZoom, SIGNAL(valueChanged(int)), this,
			SLOT(atualizarZoom(int)));
	QObject::connect(dialBtnRotacao, SIGNAL(valueChanged(int)), this,
			SLOT(rotacionarVisualizacao(int)));

	this->controladorUI->reiniciarWindow();
	this->atualizarTipoProjecao(this->radBtnProjecaoParalela->isChecked());
}

void FormPrincipal::inserirObjeto() {
	this->controladorUI->exibirFormInsercaoObjeto();
}

void FormPrincipal::removerObjeto() {
	QItemSelectionModel *modeloSelecao = this->displayFile->selectionModel();
	String nomeObjeto = "";

	if (modeloSelecao->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro(
				"É necessário selecionar um objeto para ser removido!");
		return;
	}

	for (QModelIndex indice : modeloSelecao->selectedRows()) {
		QTableWidgetItem *item = this->displayFile->item(indice.row(), 1);

		if (item)
			nomeObjeto = item->text().toStdString();

		this->displayFile->removeRow(indice.row());
	}

	this->controladorUI->removerObjeto(nomeObjeto);
	this->displayFile->setCurrentCell(0, 0);
}

void FormPrincipal::transformarObjeto() {
	QItemSelectionModel *modeloSelecao = this->displayFile->selectionModel();
	String nomeObjeto = "";

	if (modeloSelecao->selectedRows().size() == 0) {
		this->controladorUI->exibirMensagemErro(
				"É necessário selecionar um objeto para aplicar uma transformação!");
		return;
	}

	for (QModelIndex indice : modeloSelecao->selectedRows()) {
		QTableWidgetItem *item = this->displayFile->item(indice.row(), 1);

		if (item)
			nomeObjeto = item->text().toStdString();
	}

	this->controladorUI->exibirFormTransformacaoObjeto(nomeObjeto);
}

void FormPrincipal::importarCena() {
	String arquivo = QFileDialog::getOpenFileName(0,
			"Selecionar arquivo Wavefront (OBJ)", "", "*.obj").toStdString();

	if (arquivo.compare("") == 0) // Usuário cancelou
		return;
	try {
		this->controladorUI->importarCena(arquivo);
	} catch(Excecao& ex) {
		this->controladorUI->exibirMensagemErro("Não foi possível importar a cena!\n\nDetalhes: " + ex.getMensagem(), this);
	}
}

void FormPrincipal::importarCenaPreDefinida() {
	QAction* btn = (QAction*) QObject::sender();
	String cena = btn->data().toString().toStdString();

	try {
		this->controladorUI->importarCena(cena);
	} catch(Excecao& ex) {
		this->controladorUI->exibirMensagemErro("Não foi possível importar a cena!\n\nDetalhes: " + ex.getMensagem(), this);
	}
}

void FormPrincipal::exportarCena() {
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

void FormPrincipal::limparCena() {
	if(this->controladorUI->requisitarConfirmacaoUsuario("Você tem certeza que deseja limpar a cena?", this)) {
		this->controladorUI->removerObjetosMundo();
		this->reiniciarVisualizacao();
	}
}

void FormPrincipal::atalhosSistema() {
	this->controladorUI->exibirAtalhos();
}

void FormPrincipal::sobreSistema() {
	QMessageBox msg;
	msg.information(this, "Sobre", "Sistema Gráfico Interativo desenvolvido na discplina "
			"de Computação Gráfica do curso de Ciência da Computação da "
			"Universidade Federal de Santa Catarina pelos alunos "
			"Bernardo de Sousa Valverde e Lucas May Petry.");
}

void FormPrincipal::encerrarSistema() {
	if (this->controladorUI->requisitarConfirmacaoUsuario(
			"Você tem certeza que deseja encerrar o sistema?", this))
		QWidget::close();
}

void FormPrincipal::atualizarEixoRotacao(bool selecionado) {
	QObject::disconnect(dialBtnRotacao, SIGNAL(valueChanged(int)), this,
			SLOT(rotacionarVisualizacao(int)));

	if(selecionado) {
		if(radBtnRotacaoEixoX->isChecked()) { // Eixo X
			this->dialBtnRotacao->setValue(this->valorRotacaoX);
		} else if(radBtnRotacaoEixoY->isChecked()) { // Eixo Y
			this->dialBtnRotacao->setValue(this->valorRotacaoY);
		} else { // Eixo Z
			this->dialBtnRotacao->setValue(this->valorRotacaoZ);
		}
	}

	QObject::connect(dialBtnRotacao, SIGNAL(valueChanged(int)), this,
			SLOT(rotacionarVisualizacao(int)));
}

void FormPrincipal::atualizarAlgoritmoClipping(bool cohenSutherland) {
	if(cohenSutherland) {
		this->viewport->setAlgoritmoClippingLinhas(Clipping::COHEN_SUTHERLAND);
	} else {
		this->viewport->setAlgoritmoClippingLinhas(Clipping::LIANG_BARSKY);
	}
}

void FormPrincipal::atualizarTipoProjecao(bool projecaoParalela) {
	if(projecaoParalela) {
		this->controladorUI->setProjetorVisualizacao(Projetor::PARALELA_ORTOGONAL);
	} else {
		this->controladorUI->setProjetorVisualizacao(Projetor::PERSPECTIVA);
	}
}

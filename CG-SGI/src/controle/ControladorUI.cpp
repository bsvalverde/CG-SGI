#include "controle/ControladorUI.h"
#include "controle/ControladorPrincipal.h"
#include "gui/forms/MainWindow.h"
#include "gui/forms/ObjectInsertionWindow.h"
#include "gui/forms/ObjectTransformationWindow.h"

ControladorUI::ControladorUI(ControladorPrincipal* const controladorPrincipal) {
	this->controladorPrincipal = controladorPrincipal;
	this->mainWindow = new MainWindow(this);
	this->objectInsertionWindow = new ObjectInsertionWindow(this, this->mainWindow);
	this->objectTransformationWindow = new ObjectTransformationWindow(this, this->mainWindow);
}

ControladorUI::~ControladorUI() {}

void ControladorUI::exibirJanelaPrincipal() {
	this->mainWindow->show();
}

void ControladorUI::exibirJanelaAtalhos() {
	String atalhos = ":: Navegação ::\n\n"
			"CTRL + UP\t\tCima\n"
			"CTRL + DOWN\tBaixo\n"
			"CTRL + LEFT\tEsquerda\n"
			"CTRL + RIGHT\tDireita\n\n"
			":: Zoom ::\n\n"
			"CTRL + I\t\tZoom In\n"
			"CTRL + O\t\tZoom Out";

	QMessageBox messageBox;
	messageBox.information(0, "Atalhos do Sistema", QString::fromStdString(atalhos));
}

void ControladorUI::exibirObjectInsertionWindow() {
	this->objectInsertionWindow->clearFields();
	this->objectInsertionWindow->show();
}

void ControladorUI::exibirObjectTransformationWindow(const String& nomeObjeto) {
	this->objectTransformationWindow->clearFields();
	this->objectTransformationWindow->show(nomeObjeto);
}

void ControladorUI::navegarNoMundo(const Mundo::Direcao direcao, const double fator) {
	this->controladorPrincipal->navegarNoMundo(direcao, fator);
}

void ControladorUI::redimensionarWindow(const double fator) {
	this->controladorPrincipal->aplicarZoomNoMundo(fator);
}

void ControladorUI::rotacionarWindow(const double angulo) {
	this->controladorPrincipal->rotacionarVisualizacao(angulo);
}

void ControladorUI::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	this->controladorPrincipal->escalonarObjeto(nome, sX, sY, sZ);
}

void ControladorUI::transladarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	this->controladorPrincipal->transladarObjeto(nome, sX, sY, sZ);
}

void ControladorUI::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo) {
	this->controladorPrincipal->rotacionarObjetoPorPonto(nome, ponto, angulo);
}

void ControladorUI::rotacionarObjetoPeloCentro(const String& nome, const double angulo) {
	this->controladorPrincipal->rotacionarObjetoPeloCentro(nome, angulo);
}

void ControladorUI::inserirObjeto(const String& nome, const QList<Ponto> pontos,
		ObjetoGeometrico::Tipo tipo, const QColor& cor) {
	this->controladorPrincipal->inserirObjeto(nome, pontos, tipo, cor);
}

void ControladorUI::removerObjeto(const String& nome) {
	this->controladorPrincipal->removerObjeto(nome);
}

bool ControladorUI::contemObjeto(const String& nome) {
	return this->controladorPrincipal->contemObjeto(nome);
}

void ControladorUI::exibirMensagemErro(const String& mensagem, QWidget* parent) const {
	QMessageBox messageBox;
	messageBox.critical(parent, "Erro", QString::fromStdString(mensagem));
}

bool ControladorUI::requisitarConfirmacaoUsuario(const String& mensagem) const {
	QMessageBox messageBox;
	if(messageBox.question(0, "Confirmação", QString::fromStdString(mensagem)) == QMessageBox::Yes)
		return true;

	return false;
}

void ControladorUI::importarCena(const String& arquivo) {
	this->controladorPrincipal->importarCena(arquivo);
}

void ControladorUI::exportarCena(const String& arquivo) {
	this->controladorPrincipal->exportarCena(arquivo);
}

void ControladorUI::reiniciarWindow(){
	this->controladorPrincipal->reiniciarVisualizacao();
}

void ControladorUI::atualizarCena(const QList<ObjetoGeometrico*>& objetos) {
	this->mainWindow->updateObjects(objetos);
}

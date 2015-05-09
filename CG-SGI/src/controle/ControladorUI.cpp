#include "controle/ControladorUI.h"
#include "controle/ControladorPrincipal.h"
#include "gui/forms/FormPrincipal.h"
#include "gui/forms/FormInsercaoObjeto.h"
#include "gui/forms/ObjectTransformationWindow.h"

ControladorUI::ControladorUI(ControladorPrincipal* const controladorPrincipal) {
	this->controladorPrincipal = controladorPrincipal;
	this->formPrincipal = new FormPrincipal(this);
	this->objectInsertionWindow = new FormInsercaoObjeto(this, this->formPrincipal);
	this->objectTransformationWindow = new ObjectTransformationWindow(this, this->formPrincipal);
}

ControladorUI::~ControladorUI() {}

void ControladorUI::exibirFormPrincipal() {
	this->formPrincipal->show();
}

void ControladorUI::exibirFormInsercaoObjeto() {
	this->objectInsertionWindow->limparCampos();
	this->objectInsertionWindow->show();
}

void ControladorUI::exibirFormTransformacaoObjeto(const String& nomeObjeto) {
	this->objectTransformationWindow->clearFields();
	this->objectTransformationWindow->show(nomeObjeto);
}

void ControladorUI::exibirMensagemErro(const String& mensagem, QWidget* pai) const {
	QMessageBox messageBox;
	messageBox.critical(pai, "Erro", QString::fromStdString(mensagem));
}

void ControladorUI::exibirMensagemInformacao(const String& mensagem, QWidget* pai) const {
	QMessageBox messageBox;
	messageBox.information(pai, "Informação", QString::fromStdString(mensagem));
}

bool ControladorUI::requisitarConfirmacaoUsuario(const String& mensagem, QWidget* pai) const {
	QMessageBox messageBox(pai);
	messageBox.setText(QString::fromStdString(mensagem));
	QAbstractButton *btnSim = messageBox.addButton("&Sim", QMessageBox::YesRole);
	messageBox.addButton("&Não", QMessageBox::NoRole);
	messageBox.setIcon(QMessageBox::Question);
	messageBox.exec();

	if(messageBox.clickedButton() == btnSim)
		return true;

	return false;
}

void ControladorUI::navegarNoMundo(const Mundo::Direcao direcao, const double fator) {
	this->controladorPrincipal->navegarNoMundo(direcao, fator);
}

void ControladorUI::setProjetorVisualizacao(const Projetor::TipoProjecao& tipoProjecao) {
	this->controladorPrincipal->setProjetorVisualizacao(tipoProjecao);
}

void ControladorUI::redimensionarWindow(const double fator) {
	this->controladorPrincipal->aplicarZoomNoMundo(fator);
}

void ControladorUI::rotacionarWindow(const double angulo, const Mundo::Eixo& eixo) {
	this->controladorPrincipal->rotacionarVisualizacao(angulo, eixo);
}

void ControladorUI::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	this->controladorPrincipal->escalonarObjeto(nome, sX, sY, sZ);
}

void ControladorUI::transladarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	this->controladorPrincipal->transladarObjeto(nome, sX, sY, sZ);
}

void ControladorUI::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo, const Mundo::Eixo& eixo) {
	this->controladorPrincipal->rotacionarObjetoPorPonto(nome, ponto, angulo, eixo);
}

void ControladorUI::rotacionarObjetoPeloCentro(const String& nome, const double angulo, const Mundo::Eixo& eixo) {
	this->controladorPrincipal->rotacionarObjetoPeloCentro(nome, angulo, eixo);
}

void ControladorUI::inserirObjeto(const String& nome, const QList<Ponto> pontos,
		ObjetoGeometrico::Tipo tipo, const QColor& cor) {
	this->controladorPrincipal->inserirObjeto(nome, pontos, tipo, cor);
}

void ControladorUI::removerObjeto(const String& nome) {
	this->controladorPrincipal->removerObjeto(nome);
}

void ControladorUI::removerObjetosMundo() {
	this->controladorPrincipal->removerObjetosMundo();
}

bool ControladorUI::contemObjeto(const String& nome) {
	return this->controladorPrincipal->contemObjeto(nome);
}

void ControladorUI::importarCena(const String& arquivo) throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo) {
	this->controladorPrincipal->importarCena(arquivo);
}

void ControladorUI::exportarCena(const String& arquivo) {
	this->controladorPrincipal->exportarCena(arquivo);
}

void ControladorUI::reiniciarWindow(){
	this->controladorPrincipal->reiniciarVisualizacao();
}

void ControladorUI::atualizarCena(const QList<ObjetoGeometrico*>& objetos) {
	this->formPrincipal->atualizarCena(objetos);
}

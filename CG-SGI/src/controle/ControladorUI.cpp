#include "controle/ControladorUI.h"
#include "gui/forms/MainWindow.h"
#include "gui/forms/ObjectInsertionWindow.h"
#include "gui/forms/ObjectTransformationWindow.h"
#include "geometria/Reta.h"
#include "geometria/Poligono.h"

ControladorUI::ControladorUI() {
	this->mainWindow = new MainWindow(this);
	this->objectInsertionWindow = new ObjectInsertionWindow(this, this->mainWindow);
	this->objectTransformationWindow = new ObjectTransformationWindow(this, this->mainWindow);
}

ControladorUI::~ControladorUI() {}

void ControladorUI::executar() {
	this->mainWindow->show();
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
	this->mundo.navegar(direcao, fator);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::redimensionarWindow(const double fator) {
	this->mundo.redimensionarWindow(fator);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::rotacionarWindow(const double angulo) {
	this->mundo.rotacionarWindow(angulo);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	this->mundo.escalonarObjeto(nome, sX, sY, sZ);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::transladarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	this->mundo.transladarObjeto(nome, sX, sY, sZ);
	this->mainWindow->updateObjects(this->mundo.getObjetos());

}

void ControladorUI::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo) {
	this->mundo.rotacionarObjetoPorPonto(nome, ponto, angulo);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::rotacionarObjetoPeloCentro(const String& nome, const double angulo) {
	this->mundo.rotacionarObjetoPeloCentro(nome, angulo);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::inserirObjeto(const String& nome, const QList<Ponto> pontos, const QColor& cor) {
	int numeroPontos = pontos.size();

	if(numeroPontos == 1) {
		Ponto p = pontos.at(0);
		this->mundo.inserirObjeto(new Ponto(nome, p.getX(), p.getY(), p.getZ(), cor));
	} else if(numeroPontos == 2) {
		this->mundo.inserirObjeto(new Reta(nome, pontos.at(0), pontos.at(1), cor));
	} else if(numeroPontos > 2) {
		this->mundo.inserirObjeto(new Poligono(nome, pontos, cor));
	}

	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

void ControladorUI::removerObjeto(const String& nome) {
	this->mundo.removerObjeto(nome);
	this->mainWindow->updateObjects(this->mundo.getObjetos());
}

bool ControladorUI::contemObjeto(const String& nome) {
	return this->mundo.contemObjeto(nome);
}

void ControladorUI::exibirMensagemErro(const String& mensagem) const {
	QMessageBox messageBox;
	messageBox.critical(0, "Erro", QString::fromStdString(mensagem));
}

bool ControladorUI::requisitarConfirmacaoUsuario(const String& mensagem) const {
	QMessageBox messageBox;
	if(messageBox.question(0, "Confirmação", QString::fromStdString(mensagem)) == QMessageBox::Yes)
		return true;

	return false;
}

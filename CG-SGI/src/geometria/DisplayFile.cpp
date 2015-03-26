#include "geometria/DisplayFile.h"

DisplayFile::DisplayFile() {}

DisplayFile::~DisplayFile() {}

DisplayFile& DisplayFile::operator=(const DisplayFile& displayFile) {
	this->objetos = displayFile.objetos;
	return *this;
}

void DisplayFile::inserirObjeto(ObjetoGeometrico* const objeto) {
	this->objetos.insert(objeto->getNome(), objeto);
}

ObjetoGeometrico* DisplayFile::removerObjeto(const String& nome) {
	ObjetoGeometrico* obj = this->objetos[nome];
	this->objetos.remove(nome);
	return obj;
}

ObjetoGeometrico* DisplayFile::getObjeto(const String& nome) {
	return this->objetos[nome];
}

ObjetoGeometrico* DisplayFile::getObjeto(const unsigned int posicao) {
	return 0;
}

unsigned int DisplayFile::getTamanho() {
	return 0;
}

bool DisplayFile::contem(const String& nome) {
	return this->objetos.contains(nome);
}

QList<ObjetoGeometrico*> DisplayFile::getObjetos() const {
	return this->objetos.values();
}

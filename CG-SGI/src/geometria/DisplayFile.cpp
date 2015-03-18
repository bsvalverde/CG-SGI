#include "geometria/DisplayFile.h"

DisplayFile::DisplayFile() {}

DisplayFile::~DisplayFile() {}

DisplayFile& DisplayFile::operator=(const DisplayFile& displayFile) {
	this->objetos = displayFile.objetos;
	return *this;
}

void DisplayFile::adicionarObjeto(const ObjetoGeometrico& objeto) {
	this->objetos.insert(objeto.getNome(), objeto);
}

ObjetoGeometrico DisplayFile::removerObjeto(const String& nome) {
	ObjetoGeometrico obj = this->objetos[nome];
	this->objetos.remove(nome);
	return obj;
}

ObjetoGeometrico DisplayFile::getObjeto(const String& nome) {
	return this->objetos[nome];
}

bool DisplayFile::contem(const String& nome) {
	return this->objetos.contains(nome);
}

QList<ObjetoGeometrico> DisplayFile::getObjetos() const {
	return this->objetos.values();
}

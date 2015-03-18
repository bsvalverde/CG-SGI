#include "geometria/DisplayFile.h"

DisplayFile::DisplayFile() {}

DisplayFile::~DisplayFile() {}

void DisplayFile::adicionarObjeto(const ObjetoGeometrico& objeto) {
	this->objetos.insert(objeto.getNome(), objeto);
}

ObjetoGeometrico DisplayFile::removerObjeto(const String& nome) {
	ObjetoGeometrico obj = this->objetos[nome];
	this->objetos.remove(nome);
	return obj;
}

bool DisplayFile::contem(const String& nome) {
	return this->objetos.contains(nome);
}

QList<ObjetoGeometrico> DisplayFile::getObjetos() {
	return this->objetos.values();
}

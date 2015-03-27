#include "geometria/DisplayFile.h"

DisplayFile::DisplayFile() {}

DisplayFile::~DisplayFile() {}

DisplayFile& DisplayFile::operator=(const DisplayFile& displayFile) {
	for(unsigned int i = 0; i < displayFile.getTamanho(); i++) {
		ObjetoGeometrico* obj = displayFile.objetos.values().at(i);
		switch(obj->getTipo()) {
			case ObjetoGeometrico::POLIGONO:
				obj = new Poligono((const Poligono&) *obj);
				break;
			case ObjetoGeometrico::PONTO:
				obj = new Ponto((const Ponto&) *obj);
				break;
			case ObjetoGeometrico::RETA:
				obj = new Reta((const Reta&) *obj);
				break;
			default:
				break;
		}
		this->objetos.insert(obj->getNome(), obj);
	}
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
	return this->getObjetos().at(posicao);
}

unsigned int DisplayFile::getTamanho() const {
	return this->objetos.size();
}

bool DisplayFile::contem(const String& nome) {
	return this->objetos.contains(nome);
}

QList<ObjetoGeometrico*> DisplayFile::getObjetos() const {
	return this->objetos.values();
}

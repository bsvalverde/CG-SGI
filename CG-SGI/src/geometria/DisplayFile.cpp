#include "geometria/DisplayFile.h"

DisplayFile::DisplayFile() {}

DisplayFile::~DisplayFile() {}

DisplayFile& DisplayFile::operator=(const DisplayFile& displayFile) {
	for(unsigned int i = 0; i < displayFile.getTamanho(); i++) {
		ObjetoGeometrico* obj = displayFile.objetos.values().at(i);
		this->inserirObjeto(*obj);
	}
	return *this;
}

void DisplayFile::inserirObjeto(const ObjetoGeometrico& objeto) {
	ObjetoGeometrico* obj = 0;
	switch(objeto.getTipo()) {
		case ObjetoGeometrico::CURVA_BEZIER:
			obj = new CurvaBezier((const CurvaBezier&) objeto);
			break;
		case ObjetoGeometrico::CURVA_BSPLINE:
			obj = new CurvaBSpline((const CurvaBSpline&) objeto);
			break;
		case ObjetoGeometrico::SUPERFICIE_BEZIER:
			obj = new SuperficieBezier((const SuperficieBezier&) objeto);
			break;
		case ObjetoGeometrico::SUPERFICIE_BSPLINE:
			// TODO
			break;
		case ObjetoGeometrico::POLIGONO:
			obj = new Poligono((const Poligono&) objeto);
			break;
		case ObjetoGeometrico::PONTO:
			obj = new Ponto((const Ponto&) objeto);
			break;
		case ObjetoGeometrico::RETA:
			obj = new Reta((const Reta&) objeto);
			break;
		case ObjetoGeometrico::OBJETO3D:
			obj = new Objeto3D((const Objeto3D&) objeto);
			break;
		default:
			return;
	}
	this->objetos.insert(obj->getNome(), obj);
}

void DisplayFile::removerObjeto(const String& nome) {
	ObjetoGeometrico* obj = this->objetos[nome];
	this->objetos.remove(nome);

	if(obj)
		delete obj;
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

bool DisplayFile::contem(const String& nome) const {
	return this->objetos.contains(nome);
}

QList<ObjetoGeometrico*> DisplayFile::getObjetos() const {
	return this->objetos.values();
}

void DisplayFile::removerObjetos() {
	for(String chave : this->objetos.keys()) {
		delete this->objetos.value(chave);
	}
	this->objetos.clear();
}

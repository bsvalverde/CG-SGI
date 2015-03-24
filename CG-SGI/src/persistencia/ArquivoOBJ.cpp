#include "persistencia/ArquivoOBJ.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>

ArquivoOBJ::ArquivoOBJ(const String& nome) {
	this->nomeArquivo = nome;
}

ArquivoOBJ::~ArquivoOBJ() {}

void ArquivoOBJ::escreverObjetos(const QList<ObjetoGeometrico*> objetos) const {
	this->remover();
	std::fstream arquivo(this->nomeArquivo.c_str(), std::fstream::out | std::fstream::app);

	if(!arquivo)
		throw ExcecaoArquivoInvalido(this->nomeArquivo);

	// TODO Escrever objetos no arquivo.
}

QList<ObjetoGeometrico*> ArquivoOBJ::carregarObjetos() const
		throw (ExcecaoArquivoInvalido) {
	std::fstream arquivo(this->nomeArquivo.c_str(), std::fstream::in);
	std::stringstream buffer;

	if(!arquivo)
		throw ExcecaoArquivoInvalido(this->nomeArquivo);

	buffer << arquivo.rdbuf();
	arquivo.close();

	// TODO Ler objetos do arquivo.
	while(buffer) {
		String t;
		buffer >> t;
		std::cout << "Line: " << t << std::endl;
	}

	return QList<ObjetoGeometrico*>();
}

bool ArquivoOBJ::existe() const {
	std::fstream arquivo(this->nomeArquivo.c_str(), std::fstream::in);

	if(arquivo)
		return true;

	return false;
}

bool ArquivoOBJ::remover() const {
	if(remove(this->nomeArquivo.c_str()) != 0)
		return false;

	return true;
}

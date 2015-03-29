#include "persistencia/Arquivo.h"

Arquivo::Arquivo(const String& nome) {
	this->nomeArquivo = nome;
}

Arquivo::~Arquivo() {}

const String& Arquivo::getNome() const {
	return this->nomeArquivo;
}

const String Arquivo::getDiretorio() const {
	// Encontrar a última barra antes do nome do arquivo
	unsigned barraDir = this->nomeArquivo.find_last_of( "/\\" );

	// Caso não encontre barra, o diretório é o diretório atual
	if(barraDir == std::string::npos) {
		return "";
	}

	return this->nomeArquivo.substr(0, barraDir+1);
}

bool Arquivo::existe() const {
	std::fstream arquivo(this->nomeArquivo.c_str(), std::fstream::in);

	if(arquivo)
		return true;

	return false;
}

bool Arquivo::remover() const {
	if(remove(this->nomeArquivo.c_str()) != 0)
		return false;

	return true;
}

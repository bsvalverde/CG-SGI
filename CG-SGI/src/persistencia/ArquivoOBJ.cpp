#include "persistencia/ArquivoOBJ.h"

#include <fstream>
#include <sstream>
#include <iostream>

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
	std::ifstream arquivo(this->nomeArquivo.c_str());
	String linha;
	QMap<int, Ponto*> pontos;
	QList<ObjetoGeometrico*> objetos;
	int linhaAtual = 1;

	if(!arquivo)
		throw ExcecaoArquivoInvalido(this->nomeArquivo);

	// Obter todos os vértices
	while(std::getline(arquivo, linha)) {
		std::stringstream buffer(linha);
		String tipo;
		buffer >> tipo;

		if(tipo.compare("v") == 0) {
			String nome = std::to_string(linhaAtual);
			Ponto* p = this->stringToPonto(nome, linha);

			if(!p)
				throw; // TODO

			pontos.insert(linhaAtual, p);
		}

		if(tipo.at(0) != '#')
			linhaAtual++;
	}

	// Reposicionar o leitor no começo do arquivo
	arquivo.clear();
	arquivo.seekg(0, arquivo.beg);
	linhaAtual = 1;

	int indice, indice2;
	QColor corAtual = QColor(0, 0, 0);
	String nomeObjeto = "";

	// Criar os objetos
	while(std::getline(arquivo, linha)) {
		std::stringstream buffer(linha);
		String tipo;
		buffer >> tipo;

		if(tipo.compare("mtllib") == 0) {
			// ArquivoMaterial arquivo
		} else if(tipo.compare("usemtl") == 0) {
			// Material nome
		} else if(tipo.compare("o") == 0) {
			if(!(buffer >> nomeObjeto)) {
				throw; // TODO
			}
		} else if(tipo.compare("p") == 0) {
			if(nomeObjeto.compare("") != 0 && buffer >> indice) {
				Ponto* p = pontos.value(indice);
				objetos.insert(objetos.size() - 1, new Ponto(nomeObjeto, p->getX(), p->getY(), p->getZ(), corAtual));
			} else {
				throw; // TODO
			}

			nomeObjeto = "";
		} else if(tipo.compare("l") == 0) {
			if(nomeObjeto.compare("") != 0) {
				QList<Ponto> pontosObj;

				while(buffer >> indice) {
					pontosObj.insert(pontosObj.size() - 1, *pontos.value(indice));
				}

				if(pontosObj.size() == 2) {
					objetos.insert(objetos.size() - 1, new Reta(nomeObjeto, pontosObj.at(0), pontosObj.at(1), corAtual));
				} else if(pontosObj.size() > 3) {
					pontosObj.removeAt(pontosObj.size() - 1); // Remoção do primeiro ponto repetido
					objetos.insert(objetos.size() - 1, new Poligono(nomeObjeto, pontosObj, corAtual));
				} else {
					throw; // TODO
				}
			} else {
				throw; // TODO
			}

			nomeObjeto = "";
		} else if(tipo.compare("w") == 0) {
			if(nomeObjeto.compare("") != 0 && buffer >> indice && buffer >> indice2) {
				Ponto* centroWindow = pontos.value(indice);
				double largura = pontos.value(indice2)->getX();
				double altura = pontos.value(indice2)->getY();

				objetos.insert(objetos.size() - 1, new Window(*centroWindow, *centroWindow));
			} else {
				throw; // TODO
			}

			nomeObjeto = "";
		}

		if(tipo.at(0) != '#')
			linhaAtual++;
	}

	for(ObjetoGeometrico *obj : objetos)
		std::cout << *obj << std::endl;

	arquivo.close();

	// Deletar todos os pontos criados
	QList<Ponto*> listaPontos = pontos.values();
	while(listaPontos.size() > 0) {
		delete listaPontos.at(0);
		listaPontos.removeAt(0);
	}

	return objetos;
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

Ponto* ArquivoOBJ::stringToPonto(const String& nome, const String& str) const {
	std::stringstream buffer(str);
	String tipo;
	double x, y, z;

	buffer >> tipo;

	if(buffer >> x) {
		if(buffer >> y) {
			if(buffer >> z) {
				return new Ponto(nome, x, y, z);
			}
		}
	}

	return 0;
}

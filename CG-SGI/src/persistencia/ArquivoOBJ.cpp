#include "persistencia/ArquivoOBJ.h"

ArquivoOBJ::ArquivoOBJ(const String& nome) : Arquivo(nome) {}

ArquivoOBJ::~ArquivoOBJ() {
	this->removerObjetos();
}

void ArquivoOBJ::carregar() throw(ExcecaoArquivoInvalido) {
	this->removerObjetos();

	std::ifstream arquivo(this->getNome().c_str());
	String linha;
	QMap<int, Ponto*> pontos;
	QMap<String, QColor> materiais;
	int linhaAtual = 1;

	if(!arquivo)
		throw ExcecaoArquivoInvalido(this->getNome());

	// Obter todos os vértices
	while(std::getline(arquivo, linha)) {
		std::stringstream buffer(linha);
		String tipo;
		buffer >> tipo;

		if(tipo.compare("v") == 0) {
			String nome = std::to_string(linhaAtual);
			Ponto* p = this->stringToPonto(nome, linha);

			if(!p) {
				this->limpar(pontos.values());
				throw; // TODO
			}

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
			String nomeMTL;
			if(!(buffer >> nomeMTL)) {
				this->limpar(pontos.values());
				throw; // TODO
			}

			ArquivoMTL arqMTL(this->getDiretorio() + nomeMTL);

			if(!arqMTL.existe())
				throw ExcecaoArquivoInvalido(nomeMTL); // TODO

			arqMTL.carregar();
			materiais = arqMTL.getMateriais();
		} else if(tipo.compare("usemtl") == 0) {
			String nomeMaterial = "";

			if(!(buffer >> nomeMaterial) || !materiais.contains(nomeMaterial)) {
				this->limpar(pontos.values());
				throw; // TODO
			}

			corAtual = materiais.value(nomeMaterial);
		} else if(tipo.compare("o") == 0) {
			if(!(buffer >> nomeObjeto)) {
				this->limpar(pontos.values());
				throw; // TODO
			}
		} else if(tipo.compare("p") == 0) {
			if(nomeObjeto.compare("") != 0 && buffer >> indice) {
				Ponto* p = pontos.value(indice);
				this->objetos.insert(this->objetos.size() - 1, new Ponto(nomeObjeto, p->getX(), p->getY(), p->getZ(), corAtual));
			} else {
				this->limpar(pontos.values());
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
					this->objetos.insert(this->objetos.size() - 1, new Reta(nomeObjeto, pontosObj.at(0), pontosObj.at(1), corAtual));
				} else if(pontosObj.size() > 3) {
					pontosObj.removeAt(pontosObj.size() - 1); // Remoção do primeiro ponto repetido
					this->objetos.insert(this->objetos.size() - 1, new Poligono(nomeObjeto, pontosObj, corAtual));
				} else {
					this->limpar(pontos.values());
					throw; // TODO
				}
			} else {
				this->limpar(pontos.values());
				throw; // TODO
			}

			nomeObjeto = "";
		} else if(tipo.compare("w") == 0) {
			if(nomeObjeto.compare("") != 0 && buffer >> indice && buffer >> indice2) {
				Ponto* centroWindow = pontos.value(indice);
				double largura = pontos.value(indice2)->getX();
				double altura = pontos.value(indice2)->getY();

				largura += altura; // ocultar warnings TEMP TODO

				this->objetos.insert(this->objetos.size() - 1, new Window(*centroWindow, *centroWindow));
			} else {
				this->limpar(pontos.values());
				throw; // TODO
			}

			nomeObjeto = "";
		}

		if(tipo.at(0) != '#')
			linhaAtual++;
	}

	arquivo.close();
	this->limpar(pontos.values());
}

void ArquivoOBJ::gravar() const throw() {
	this->remover();
	std::fstream arquivo(this->getNome().c_str(), std::fstream::out | std::fstream::app);

	if(!arquivo)
		throw ExcecaoArquivoInvalido(this->getNome());

	// TODO Escrever objetos no arquivo.
}

void ArquivoOBJ::setObjetos(const QList<ObjetoGeometrico*>& objetos) {
	this->removerObjetos();

	for(int i = 0; i < objetos.size(); i++) {
		ObjetoGeometrico* obj = objetos.at(i);
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
				return;
		}
		this->objetos.insert(i, obj);
	}
}

const QList<ObjetoGeometrico*>& ArquivoOBJ::getObjetos() const {
	return this->objetos;
}

void ArquivoOBJ::removerObjetos() {
	while(this->objetos.size() > 0) {
		delete this->objetos[0];
		this->objetos.removeAt(0);
	}
}

Ponto* ArquivoOBJ::stringToPonto(const String& nome, const String& str) const {
	std::stringstream buffer(str);
	String tipo;
	double x, y, z;

	buffer >> tipo;

	if(buffer >> x && buffer >> y && buffer >> z) {
		return new Ponto(nome, x, y, z);
	}

	return 0;
}

void ArquivoOBJ::limpar(QList<Ponto*> pontos) const {
	// Deletar todos os pontos
	while(pontos.size() > 0) {
		delete pontos.at(0);
		pontos.removeAt(0);
	}
}

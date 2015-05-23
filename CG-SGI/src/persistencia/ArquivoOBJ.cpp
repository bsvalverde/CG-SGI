#include "persistencia/ArquivoOBJ.h"
#include <iostream>

const String ArquivoOBJ::BASIC_MAN = "samples/basicman.sample";
const String ArquivoOBJ::CRISTO_REDENTOR = "samples/cristo.sample";
const String ArquivoOBJ::DINO_MECH = "samples/dinomech.sample";
const String ArquivoOBJ::SUB_ZERO = "samples/subzero.sample";

ArquivoOBJ::ArquivoOBJ(const String& nome) : Arquivo(nome) {
	this->window = 0;
}

ArquivoOBJ::~ArquivoOBJ() {}

void ArquivoOBJ::carregar() throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo) {
	this->removerObjetos();

	std::ifstream arquivo(this->getNome().c_str());
	String linha;
	QMap<int, Ponto*> pontos;
	QMap<String, QColor> materiais;
	int linhaAtual = 1;

	if(!arquivo)
		throw ExcecaoLeituraArquivo(this->getNome());

	// Obter todos os vértices
	while(std::getline(arquivo, linha)) {
		std::stringstream buffer(linha);
		String tipo;

		if(linha.compare("") == 0)
			continue;

		if(!(buffer >> tipo))
			throw ExcecaoArquivoInvalido(this->getNome());

		if(tipo.compare("v") == 0) {
			String nome = std::to_string(linhaAtual);
			Ponto* p = this->stringToPonto(nome, linha);

			if(!p) {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
			}

			pontos.insert(linhaAtual, p);
		}

		if(tipo.compare("v") == 0)
			linhaAtual++;
	}

	// Reposicionar o leitor no começo do arquivo
	arquivo.clear();
	arquivo.seekg(0, arquivo.beg);

	int indice, indice2;
	bool anteriorEraFace = false;
	QColor corAtual = QColor(0, 0, 0);
	String nomeObjeto = "";
	QList<Aresta> arestas;
	QList<Ponto> pontosObjeto3dCopia;
	QList<Ponto*> pontosObjeto3d;

	// Criar os objetos
	while(std::getline(arquivo, linha)) {
		std::stringstream buffer(linha);
		String tipo;
		buffer >> tipo;

		if(tipo.compare("f") != 0 && tipo.compare("usemtl") != 0 && anteriorEraFace) {
			this->objetos.append(new Objeto3D(nomeObjeto, pontosObjeto3d, arestas));
			pontosObjeto3d.clear();
			pontosObjeto3dCopia.clear();
			arestas.clear();
			anteriorEraFace = false;
		}

		if(tipo.compare("mtllib") == 0) {
			String nomeMTL;
			if(!(buffer >> nomeMTL)) {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
			}

			ArquivoMTL arqMTL(this->getDiretorio() + nomeMTL);

			if(!arqMTL.existe())
				throw ExcecaoLeituraArquivo(nomeMTL);

			arqMTL.carregar();
			materiais = arqMTL.getMateriais();
		} else if(tipo.compare("usemtl") == 0) {
			String nomeMaterial = "";

			if(!(buffer >> nomeMaterial) || !materiais.contains(nomeMaterial)) {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
			}

			corAtual = materiais.value(nomeMaterial);
		} else if(tipo.compare("o") == 0) {
			if(!(buffer >> nomeObjeto)) {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
			}
		} else if(tipo.compare("p") == 0) {
			if(nomeObjeto.compare("") != 0 && buffer >> indice) {
				Ponto* p = pontos.value(indice);
				this->objetos.insert(this->objetos.size() - 1, new Ponto(nomeObjeto, p->getX(), p->getY(), p->getZ(), corAtual));
			} else {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
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
					throw ExcecaoArquivoInvalido(this->getNome());
				}
			} else {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
			}

			nomeObjeto = "";
		} else if(tipo.compare("f") == 0) {
			if(nomeObjeto.compare("") != 0) {
				QList<Ponto> pontosObj;
				anteriorEraFace = true;

				QList<int> indices;
				String indiceString;

				while(std::getline(buffer, indiceString, ' ')) {
					std::stringstream bufferVertices(indiceString);
					int num = -1;

					if(indiceString.find('/') >= 0) {
						while(std::getline(bufferVertices, indiceString, '/')) {
							if(num == -1) {
								std::stringstream bufferNum(indiceString);
								bufferNum >> num;
								indices.append(num);
							}
						}
					} else {
						bufferVertices >> num;
						indices.append(num);
					}
				}

				if(indices.size() == 0) {
					this->limpar(pontos.values());
					throw ExcecaoArquivoInvalido(this->getNome());
				}

				Ponto* p1 = new Ponto(*pontos.value(indices.at(0)));
				Ponto* pInicial = p1;
				Ponto* p2;

				for(int i = 1; i < indices.size(); i++) {
					p2 = new Ponto(*pontos.value(indices.at(i)));
					arestas.append(Aresta(p1, p2, corAtual));

					if(!pontosObjeto3dCopia.contains(*p1)) {
						pontosObjeto3d.append(p1);
						pontosObjeto3dCopia.append(*p1);
					}
					p1 = p2;
				}
				arestas.append(Aresta(pInicial, p1, corAtual));

				if(!pontosObjeto3dCopia.contains(*p1)) {
					pontosObjeto3d.append(p1);
					pontosObjeto3dCopia.append(*p1);
				}
			} else {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
			}
		} else if(tipo.compare("w") == 0) {
			if(nomeObjeto.compare("") != 0 && buffer >> indice && buffer >> indice2) {
				Ponto* centroWindow = pontos.value(indice);
				double largura = pontos.value(indice2)->getX();
				double altura = pontos.value(indice2)->getY();

				this->window = new Window(*centroWindow, largura, altura);
			} else {
				this->limpar(pontos.values());
				throw ExcecaoArquivoInvalido(this->getNome());
			}

			nomeObjeto = "";
		}

	}

	if(arestas.size() > 0) {
		this->objetos.append(new Objeto3D(nomeObjeto, pontosObjeto3d, arestas));
		pontosObjeto3d.clear();
		pontosObjeto3dCopia.clear();
		arestas.clear();
		anteriorEraFace = false;
	}

	arquivo.close();
	this->limpar(pontos.values());
}

void ArquivoOBJ::gravar() const throw(ExcecaoEscritaArquivo) {
	this->remover();
	std::fstream arquivo(this->getNome().c_str(), std::fstream::out | std::fstream::app);

	if(!arquivo)
		throw ExcecaoEscritaArquivo(this->getNome());

	arquivo << "# Arquivo OBJ (Wavefront) - Sistema Gráfico Interativo\n";

	int verticeAtual = 1; // Vértice atual.
	QMap<String, QColor> materiais;

	arquivo << "mtllib " << this->getNomeCurto() + ".mtl" << "\n";

	for(int i = 0; i < this->objetos.size(); i++) {
		ObjetoGeometrico* objeto = this->objetos.at(i);
		QList<Ponto> pontosObjeto = objeto->getPontos();
		int primeiroPonto = verticeAtual;

		String nomeMaterial = "m_" + objeto->getNome();
		materiais.insert(nomeMaterial, objeto->getCor());

		String pontos = std::to_string(verticeAtual);
		arquivo << "v " << pontosObjeto.at(0).getX() << " " << pontosObjeto.at(0).getY() <<
					" " << pontosObjeto.at(0).getZ() << "\n";
		verticeAtual++;

		if(objeto->getTipo() != ObjetoGeometrico::WINDOW) {
			for(int j = 1; j < pontosObjeto.size(); j++) {
				Ponto p = pontosObjeto.at(j);
				arquivo << "v " << p.getX() << " " << p.getY() << " " << p.getZ() << "\n";
				pontos += " " + std::to_string(verticeAtual);
				verticeAtual++;
			}
		} else {
			Window* w = (Window*) objeto;
			arquivo << "v " << w->getLargura() << " " << w->getAltura() << " 0\n";
			pontos += " " + std::to_string(verticeAtual);
			verticeAtual++;
		}

		switch(objeto->getTipo()) {
			case ObjetoGeometrico::WINDOW:
				arquivo << "o " << objeto->getNome() << "\n";
				arquivo << "w " << pontos.c_str() << "\n";
				pontos = "";
				break;
			case ObjetoGeometrico::PONTO:
				arquivo << "o " << objeto->getNome() << "\n";
				arquivo << "usemtl " << nomeMaterial << "\n";
				arquivo << "p " << pontos.c_str() << "\n";
				pontos = "";
				break;
			case ObjetoGeometrico::POLIGONO:
			case ObjetoGeometrico::RETA:
				if(objeto->getTipo() == ObjetoGeometrico::POLIGONO) {
					pontos += " " + std::to_string(primeiroPonto);
				}
				arquivo << "o " << objeto->getNome() << "\n";
				arquivo << "usemtl " << nomeMaterial << "\n";
				arquivo << "l " << pontos.c_str() << "\n";
				pontos = "";
				break;
			case ObjetoGeometrico::OBJETO3D: // TODO
			case ObjetoGeometrico::CURVA_BEZIER:
			case ObjetoGeometrico::CURVA_BSPLINE:
				break;
		}
	}
	arquivo.close();

	ArquivoMTL arquivoMtl(this->getNome() + ".mtl");
	arquivoMtl.setMateriais(materiais);
	arquivoMtl.gravar();
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
			case ObjetoGeometrico::WINDOW:
				this->window = new Window((const Window&) *obj);
				break;
			case ObjetoGeometrico::OBJETO3D:
				obj = new Objeto3D((const Objeto3D&) *obj);
				break;
			case ObjetoGeometrico::CURVA_BEZIER:
			case ObjetoGeometrico::CURVA_BSPLINE:
				break;
		}
		this->objetos.insert(i, obj);
	}
}

Cena* ArquivoOBJ::getCena() const {
	return new Cena(this->window, this->objetos);
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

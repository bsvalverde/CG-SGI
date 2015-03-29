#include "persistencia/ArquivoMTL.h"

ArquivoMTL::ArquivoMTL(const String& nome) : Arquivo(nome) {}

ArquivoMTL::~ArquivoMTL() {}

void ArquivoMTL::carregar() throw(ExcecaoArquivoInvalido) {
	this->removerMateriais();

	std::ifstream arquivo(this->getNome().c_str());
	String linha;
	String nomeMaterial = "";

	while(std::getline(arquivo, linha)) {
		std::stringstream buffer(linha);
		String tipo;
		buffer >> tipo;

		if(tipo.compare("newmtl") == 0) { // Definir nome do material
			if(!(buffer >> nomeMaterial))
				throw; // TODO

			if(this->materiais.contains(nomeMaterial))
				throw; // TODO
		} else if(tipo.compare("Kd") == 0) { // Definir cor do material
			if(nomeMaterial.compare("") == 0)
				throw; // TODO

			double kd1, kd2, kd3;

			if(buffer >> kd1 && buffer >> kd2 && buffer >> kd3) {
				this->materiais.insert(nomeMaterial, QColor(kd1 * 255, kd2 * 255, kd3 * 255));
				nomeMaterial = "";
			} else {
				throw; // TODO
			}
		}
	}
}

void ArquivoMTL::gravar() const throw() {
	this->remover();
	std::fstream arquivo(this->getNome().c_str(), std::fstream::out | std::fstream::app);

	if(!arquivo)
		throw ExcecaoArquivoInvalido(this->getNome());

	// TODO Escrever materiais no arquivo.
}

void ArquivoMTL::setMateriais(const QMap<String, QColor>& materiais) {
	this->materiais = materiais;
}

const QMap<String, QColor>& ArquivoMTL::getMateriais() const {
	return this->materiais;
}

void ArquivoMTL::removerMateriais() {
	this->materiais.clear();
}

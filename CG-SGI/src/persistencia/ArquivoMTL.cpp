#include "persistencia/ArquivoMTL.h"

ArquivoMTL::ArquivoMTL(const String& nome) : Arquivo(nome) {}

ArquivoMTL::~ArquivoMTL() {}

void ArquivoMTL::carregar() throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo) {
	this->removerMateriais();

	std::ifstream arquivo(this->getNome().c_str());
	String linha;
	String nomeMaterial = "";

	if(!arquivo)
		throw ExcecaoLeituraArquivo(this->getNome());

	while(std::getline(arquivo, linha)) {
		std::stringstream buffer(linha);
		String tipo;
		buffer >> tipo;

		if(tipo.compare("newmtl") == 0) { // Definir nome do material
			if(!(buffer >> nomeMaterial))
				throw ExcecaoArquivoInvalido(this->getNome());

			if(this->materiais.contains(nomeMaterial))
				throw ExcecaoArquivoInvalido(this->getNome());
		} else if(tipo.compare("Kd") == 0) { // Definir cor do material
			if(nomeMaterial.compare("") == 0)
				throw ExcecaoArquivoInvalido(this->getNome());

			double kd1, kd2, kd3;

			if(buffer >> kd1 && buffer >> kd2 && buffer >> kd3) {
				this->materiais.insert(nomeMaterial, QColor(kd1 * 255, kd2 * 255, kd3 * 255));
				nomeMaterial = "";
			} else {
				throw ExcecaoArquivoInvalido(this->getNome());
			}
		}
	}
}

void ArquivoMTL::gravar() const throw(ExcecaoEscritaArquivo) {
	this->remover();
	std::fstream arquivo(this->getNome().c_str(), std::fstream::out | std::fstream::app);

	if(!arquivo)
		throw ExcecaoEscritaArquivo(this->getNome());

	arquivo << "# Arquivo MTL - Sistema Gráfico Interativo\n";

	QList<String> nomes = this->materiais.keys();

	for(int i = 0; i < nomes.size(); i++) {
		float kd1 = (float) this->materiais.value(nomes.at(i)).red() / 255;
		float kd2 = (float) this->materiais.value(nomes.at(i)).green() / 255;
		float kd3 = (float) this->materiais.value(nomes.at(i)).blue() / 255;

		arquivo << "newmtl " << nomes.at(i) << "\n";
		arquivo << "Kd " << kd1 << " " << kd2 << " " << kd3 << "\n";
	}
	arquivo.close();
}

void ArquivoMTL::setMateriais(const QMap<String, QColor>& materiais) {
	this->materiais = materiais;
}

QMap<String, QColor> ArquivoMTL::getMateriais() const {
	return this->materiais;
}

void ArquivoMTL::removerMateriais() {
	this->materiais.clear();
}

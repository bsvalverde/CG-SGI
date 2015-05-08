#ifndef EXCECAOLEITURAARQUIVO_H_
#define EXCECAOLEITURAARQUIVO_H_

#include "excecao/Excecao.h"

/**
 * Exceção de Leitura do Arquivo.
 */
class ExcecaoLeituraArquivo : public Excecao {

public:
	/**
	 * Construtor.
	 */
	ExcecaoLeituraArquivo(const String& arquivo) {
		this->arquivo = arquivo;
	}

	/**
	 * Destrutor.
	 */
	virtual ~ExcecaoLeituraArquivo() throw() {}

	/**
	 * Obter a mensagem da exceção como string de C++.
	 * @return A mensagem correspondente.
	 */
	virtual String getMensagem() const {
		return "Não foi possível ler o arquivo " + this->arquivo + ". Verifique "
				"se o arquivo existe e/ou possui permissão de leitura!";
	}

protected:
	String arquivo;

};

#endif /* EXCECAOLEITURAARQUIVO_H_ */

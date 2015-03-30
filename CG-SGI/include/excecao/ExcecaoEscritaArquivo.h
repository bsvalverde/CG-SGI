#ifndef EXCECAOESCRITAARQUIVO_H_
#define EXCECAOESCRITAARQUIVO_H_

#include "excecao/Excecao.h"

/**
 * Exceção de Escrita no Arquivo.
 */
class ExcecaoEscritaArquivo : public Excecao {

public:
	/**
	 * Construtor.
	 */
	ExcecaoEscritaArquivo(const String& arquivo) {
		this->arquivo = arquivo;
	}

	/**
	 * Destrutor.
	 */
	virtual ~ExcecaoEscritaArquivo() throw() {}

	/**
	 * Obter a mensagem da exceção como string de C++.
	 * @return A mensagem correspondente.
	 */
	virtual String getMensagem() const {
		return "Não foi possível escrever no arquivo " + this->arquivo + ".";
	}

protected:
	String arquivo;

};

#endif /* EXCECAOLEITURAARQUIVO_H_ */

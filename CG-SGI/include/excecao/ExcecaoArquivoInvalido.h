#ifndef EXCECAOARQUIVOINVALIDO_H_
#define EXCECAOARQUIVOINVALIDO_H_

#include "excecao/Excecao.h"

/**
 * Exceção de Arquivo Inválido.
 */
class ExcecaoArquivoInvalido : public Excecao {

public:
	/**
	 * Construtor.
	 */
	ExcecaoArquivoInvalido(const String& arquivo) {
		this->arquivo = arquivo;
	}

	/**
	 * Destrutor.
	 */
	virtual ~ExcecaoArquivoInvalido() throw() {}

	/**
	 * Obter a mensagem da exceção como string de C++.
	 * @return A mensagem correspondente.
	 */
	virtual String getMensagem() const {
		return this->arquivo + " não é um arquivo válido.";
	}

protected:
	String arquivo;

};

#endif /* EXCECAOARQUIVOINVALIDO_H_ */

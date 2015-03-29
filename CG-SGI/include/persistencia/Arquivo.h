#ifndef ARQUIVO_H_
#define ARQUIVO_H_

#include <string.h>
#include <fstream>

#include "excecao/ExcecaoArquivoInvalido.h"

typedef std::string String;

/**
 * Interface de Arquivo.
 */
class Arquivo {

public:
	/**
	 * Construtor.
	 * @param nome nome completo do arquivo.
	 */
	Arquivo(const String& nome);

	/**
	 * Destrutor.
	 */
	virtual ~Arquivo();

	/**
	 * Obter o nome.
	 * @return nome do arquivo.
	 */
	const String& getNome() const;

	/**
	 * Obter o diretório relativo onde o arquivo está.
	 * @return diretório do arquivo.
	 */
	const String getDiretorio() const;

	/**
	 * Verificar se o arquivo existe.
	 * @return true caso o arquivo exista.
	 */
	bool existe() const;

	/**
	 * Carregar o arquivo.
	 */
	virtual void carregar() throw(ExcecaoArquivoInvalido) = 0;

	/**
	 * Gravar o arquivo.
	 */
	virtual void gravar() const throw() = 0;

protected:
	/**
	 * Remover o arquivo.
	 * @return true se o arquivo foi removido.
	 */
	bool remover() const;

private:
	String nomeArquivo;

};

#endif /* ARQUIVO_H_ */

#ifndef ARQUIVO_H_
#define ARQUIVO_H_

#include <string.h>
#include <fstream>

#include "excecao/ExcecaoArquivoInvalido.h"
#include "excecao/ExcecaoEscritaArquivo.h"
#include "excecao/ExcecaoLeituraArquivo.h"

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
	 * Obter o nome completo.
	 * @return nome completo do arquivo.
	 */
	const String& getNome() const;

	/**
	 * Obter o nome sem o diretório.
	 * @return nome do arquivo (sem o diretório).
	 */
	const String getNomeCurto() const;

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
	 * @throws ExcecaoArquivoInvalido caso o arquivo seja inválido.
	 * @throws ExcecaoLeituraArquivo caso não seja possível ler o arquivo.
	 */
	virtual void carregar() throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo) = 0;

	/**
	 * Gravar o arquivo.
	 * @throws ExcecaoEscritaArquivo caso não seja possível escrever no arquivo.
	 */
	virtual void gravar() const throw(ExcecaoEscritaArquivo) = 0;

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

#ifndef ARQUIVOMTL_H_
#define ARQUIVOMTL_H_

#include <sstream>

#include <QtCore/qmap.h>
#include <QtGui/qcolor.h>

#include "excecao/ExcecaoArquivoInvalido.h"
#include "persistencia/Arquivo.h"

/**
 * Arquivo MTL (Material Template Library).
 */
class ArquivoMTL : public Arquivo {

public:
	/**
	 * Construtor.
	 * @param nome nome completo do arquivo.
	 */
	ArquivoMTL(const String& nome);

	/**
	 * Destrutor.
	 */
	virtual ~ArquivoMTL();

	/**
	 * Carregar o arquivo.
	 * @throws ExcecaoArquivoInvalido caso o arquivo seja inválido.
	 * @throws ExcecaoLeituraArquivo caso não seja possível ler o arquivo.
	 */
	void carregar() throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo);

	/**
	 * Gravar o arquivo.
	 * @throws ExcecaoEscritaArquivo caso não seja possível escrever no arquivo.
	 */
	void gravar() const throw(ExcecaoEscritaArquivo);

	/**
	 * Definir os materiais do arquivo.
	 * @param materiais materiais do arquivo.
	 */
	void setMateriais(const QMap<String, QColor>& materiais);

	/**
	 * Obter materiais do arquivo.
	 * @return mapa de materiais do arquivo.
	 */
	const QMap<String, QColor>& getMateriais() const;

protected:
	/**
	 * Remover todos os materiais do buffer do arquivo.
	 */
	void removerMateriais();

	QMap<String, QColor> materiais;

};

#endif /* ARQUIVOMTL_H_ */

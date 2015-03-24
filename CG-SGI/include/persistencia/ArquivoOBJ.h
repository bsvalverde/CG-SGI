#ifndef ARQUIVOOBJ_H_
#define ARQUIVOOBJ_H_

#include <QtCore/qlist.h>

#include "excecao/ExcecaoArquivoInvalido.h"
#include "geometria/ObjetoGeometrico.h"

/**
 * Arquivo Wavefront OBJ.
 */
class ArquivoOBJ {

public:
	/**
	 * Construtor.
	 * @param nome nome completo do arquivo.
	 */
	ArquivoOBJ(const String& nome);

	/**
	 * Destrutor.
	 */
	virtual ~ArquivoOBJ();

	/**
	 * Escrever objetos no arquivo OBJ especificado.
	 * @param objetos objetos a serem escritos no arquivo.
	 */
	void escreverObjetos(const QList<ObjetoGeometrico*> objetos) const;

	/**
	 * Carregar os objetos do arquivo OBJ.
	 * @return lista contendo os objetos carregados.
	 * @throws ExcecaoArquivoInvalido se o arquivo especificado não foi encontrado ou não possui um formato válido.
	 */
	QList<ObjetoGeometrico*> carregarObjetos() const
			throw (ExcecaoArquivoInvalido);

	/**
	 * Verificar se o arquivo existe.
	 * @return true se o arquivo existe.
	 */
	bool existe() const;

protected:
	/**
	 * Remover o arquivo.
	 * @return true se o arquivo foi removido.
	 */
	bool remover() const;

	String nomeArquivo;

};

#endif /* ARQUIVOOBJ_H_ */

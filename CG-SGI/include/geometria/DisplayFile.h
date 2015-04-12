#ifndef DISPLAYFILE_H_
#define DISPLAYFILE_H_

#include <QtCore/qmap.h>
#include <string>

#include "geometria/ObjetoGeometrico.h"
#include "geometria/CurvaBezier.h"
#include "geometria/Poligono.h"
#include "geometria/Reta.h"

typedef std::string String;

/**
 * Lista de objetos geométricos.
 */
class DisplayFile {

public:
	/**
	 * Construtor.
	 */
	DisplayFile();

	/**
	 * Destrutor.
	 */
	virtual ~DisplayFile();

	/**
	 * Operador de atribuição.
	 * @param displayFile objeto a ser copiado.
	 * @return display file copiado.
	 */
	DisplayFile& operator=(const DisplayFile& displayFile);

	/**
	 * Inserir um objeto geométrico.
	 * @param objeto objeto a ser adicionado.
	 */
	void inserirObjeto(const ObjetoGeometrico& objeto);

	/**
	 * Remover um objeto geométrico.
	 * @param nome nome do objeto a ser removido.
	 */
	void removerObjeto(const String& nome);

	/**
	 * Obter um objeto geométrico.
	 * @param nome nome do objeto a ser removido.
	 * @return o objeto.
	 */
	ObjetoGeometrico* getObjeto(const String& nome);

	/**
	 * Obter um objeto geométrico.
	 * @param posicao posição do objeto a ser removido.
	 * @return o objeto.
	 */
	ObjetoGeometrico* getObjeto(const unsigned int posicao);

	/**
	 * Obter o tamanho.
	 * @return número de objetos contidos no DisplayFile.
	 */
	unsigned int getTamanho() const;

	/**
	 * Verificar se a lista contém um objeto.
	 * @param nome nome do a ser verificado.
	 * @return true caso o objeto esteja na lista.
	 */
	bool contem(const String& nome) const;

	/**
	 * Obter a lista de objetos geométricos.
	 * @return lista contendo os objetos geométricos.
	 */
	QList<ObjetoGeometrico*> getObjetos() const;

	/**
	 * Remover todos os objetos do DisplayFile.
	 */
	void removerObjetos();

private:
	QMap<String, ObjetoGeometrico*> objetos;

};

#endif /* DISPLAYFILE_H_ */

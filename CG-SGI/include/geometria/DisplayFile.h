#ifndef DISPLAYFILE_H_
#define DISPLAYFILE_H_

#include <QtCore/qmap.h>
#include <string>

#include "geometria/ObjetoGeometrico.h"

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
	 * Adicionar um objeto geométrico.
	 * @param objeto objeto a ser adicionado.
	 */
	void adicionarObjeto(const ObjetoGeometrico& objeto);

	/**
	 * Remover um objeto geométrico.
	 * @param nome nome do objeto a ser removido.
	 * @return o objeto removido.
	 */
	ObjetoGeometrico removerObjeto(const String& nome);

	/**
	 * Verificar se a lista contém um objeto.
	 * @param nome nome do a ser verificado.
	 * @return true caso o objeto esteja na lista.
	 */
	bool contem(const String& nome);

	/**
	 * Obter a lista de objetos geométricos.
	 * @return mapa contendo os objetos geométricos.
	 */
	QList<ObjetoGeometrico> getObjetos();

private:
	QMap<String, ObjetoGeometrico> objetos;

};

#endif /* DISPLAYFILE_H_ */

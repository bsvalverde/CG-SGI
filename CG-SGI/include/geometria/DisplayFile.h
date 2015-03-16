#ifndef DISPLAYFILE_H_
#define DISPLAYFILE_H_

#include <QtCore/qmap.h>
#include <map>
#include <string>

#include "geometria/ObjetoGeometrico.h"

typedef std::string String;

/**
 * Lista de objetos geom�tricos.
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
	 * Adicionar um objeto geom�trico.
	 * @param objeto objeto a ser adicionado.
	 */
	void adicionarObjeto(const ObjetoGeometrico& objeto);

	/**
	 * Remover um objeto geom�trico.
	 * @param nome nome do objeto a ser removido.
	 * @return o objeto removido.
	 */
	ObjetoGeometrico removerObjeto(const String& nome);

	/**
	 * Verificar se a lista cont�m um objeto.
	 * @param nome nome do a ser verificado.
	 * @return true caso o objeto esteja na lista.
	 */
	bool contem(const String& nome);

	/**
	 * Obter a lista de objetos geom�tricos.
	 * @return mapa contendo os objetos geom�tricos.
	 */
	std::map<String, ObjetoGeometrico> getObjetos();

private:
	QMap<String, ObjetoGeometrico> objetos;

};

#endif /* DISPLAYFILE_H_ */

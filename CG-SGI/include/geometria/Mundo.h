#ifndef MUNDO_H_
#define MUNDO_H_

#include "geometria/DisplayFile.h"
#include "geometria/Window.h"

/**
 * Mundo de representação dos objetos reais.
 */
class Mundo {

public:
	/**
	 * Construtor.
	 */
	Mundo();

	/**
	 * Destrutor.
	 */
	virtual ~Mundo();

	/**
	 * Inserir objeto ao mundo.
	 * @param objeto objeto a ser inserido.
	 */
	void inserirObjeto(const ObjetoGeometrico& objeto);

	/**
	 * Remover objeto do mundo.
	 * @param nome nome do objeto.
	 */
	void removerObjeto(const String& nome);

	/**
	 * Verificar se o mundo contém um objeto.
	 * @param nome nome do objeto.
	 * @return true se o objeto existe.
	 */
	bool contemObjeto(const String& nome);

	/**
	 * Obter a window do mundo.
	 * @return a window.
	 */
	const Window& getWindow() const;

	/**
	 * Obter os objetos do mundo.
	 * @return lista de objetos do mundo.
	 */
	QList<ObjetoGeometrico> getObjetos() const;

private:
	DisplayFile displayFile;
	Window window;

};

#endif /* MUNDO_H_ */

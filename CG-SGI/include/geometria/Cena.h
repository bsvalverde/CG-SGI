#ifndef CENA_H_
#define CENA_H_

#include "geometria/ObjetoGeometrico.h"
#include "geometria/Window.h"

/**
 * Cena.
 */
class Cena {

public:
	/**
	 * Construtor.
	 * @param window window da cena.
	 * @param objetos lista de objetos geométricos da cena.
	 */
	Cena(Window* const window, const QList<ObjetoGeometrico*>& objetos);

	/**
	 * Destrutor.
	 */
	virtual ~Cena();

	/**
	 * Obter a window da cena.
	 * @return a window.
	 */
	Window* getWindow() const;

	/**
	 * Obter os objetos da cena.
	 * @return lista de objetos da cena.
	 */
	QList<ObjetoGeometrico*> getObjetos() const;

private:
	Window* window;
	QList<ObjetoGeometrico*> objetos;


};

#endif /* CENA_H_ */

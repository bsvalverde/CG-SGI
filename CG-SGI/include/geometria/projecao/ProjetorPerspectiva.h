#ifndef PROJETORPERSPECTIVA_H_
#define PROJETORPERSPECTIVA_H_

#include <cmath>

#include "geometria/projecao/Projetor.h"

/**
 * Projetor de perspectiva.
 */
class ProjetorPerspectiva : public Projetor {

public:
	/**
	 * Construtor.
	 * @param window janela de visualização.
	 */
	ProjetorPerspectiva(Window* const window);

	/**
	 * Destrutor.
	 */
	virtual ~ProjetorPerspectiva();

	/**
	 * Projetar objeto geométrico na window.
	 * @param objeto objeto a ser projetado.
	 */
	void projetarObjeto(ObjetoGeometrico* const objeto) const;

};

#endif /* PROJETORPERSPECTIVA_H_ */

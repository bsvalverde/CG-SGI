#ifndef PROJETORPARALELO_H_
#define PROJETORPARALELO_H_

#include "geometria/projecao/Projetor.h"

/**
 * Projetor paralelo ortogonal.
 */
class ProjetorParalelo : public Projetor {

public:
	/**
	 * Construtor.
	 * @param window janela de visualização.
	 */
	ProjetorParalelo(Window* const window);

	/**
	 * Destrutor.
	 */
	virtual ~ProjetorParalelo();

	/**
	 * Projetar objeto geométrico na window.
	 * @param objeto objeto a ser projetado.
	 */
	void projetarObjeto(ObjetoGeometrico* const objeto) const;

};

#endif /* PROJETORPARALELO_H_ */

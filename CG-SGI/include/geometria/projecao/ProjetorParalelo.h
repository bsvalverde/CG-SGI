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

};

#endif /* PROJETORPARALELO_H_ */

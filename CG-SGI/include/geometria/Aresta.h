#ifndef ARESTA_H_
#define ARESTA_H_

#include "geometria/Ponto.h"

/**
 * Aresta
 */
class Aresta {

public:
	/**
	 * Construtor.
	 * @param inicial ponto inicial.
	 * @param final ponto final.
	 * @param cor cor da aresta.
	 */
	Aresta(const Ponto& inicial, const Ponto& final);

	/**
	 * Destrutor.
	 */
	~Aresta();

	/**
	 * Obter os pontos do objeto.
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto> getPontos() const;

protected:
	Ponto* v_inicial;
	Ponto* v_final;

};

#endif

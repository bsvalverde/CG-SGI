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
	Aresta(Ponto& inicial, Ponto& final, const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	~Aresta();

	/**
	 * Obter os pontos da aresta.
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto> getPontos() const;

protected:
	Ponto* v_inicial;
	Ponto* v_final;
	QColor cor;

};

#endif

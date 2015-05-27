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
	Aresta(Ponto* const inicial, Ponto* const final, const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	~Aresta();

	/**
	 * Obter os pontos da aresta.
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto> getPontos() const;

	/**
	 * Obter os pontos da aresta.
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto*> getPontosObjeto();

	/**
	 * Obter a cor da aresta.
	 * @return a cor da aresta.
	 */
	QColor getCor() const;

protected:
	Ponto* v_inicial;
	Ponto* v_final;
	QColor cor;

};

#endif

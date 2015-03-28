#ifndef VIEWPORT_H_
#define VIEWPORT_H_

#include <QtWidgets/qgraphicsview.h>

/**
 * Janela de visualização da interface gráfica.
 */
class Viewport {

public:
	/**
	 * Construtor.
	 * @param janelaGrafica objeto gráfico de plotagem.
	 */
	Viewport(QGraphicsView* const janelaGrafica);

	/**
	 * Destrutor.
	 */
	virtual ~Viewport();

private:
	QGraphicsView* janelaGrafica;

};

#endif /* VIEWPORT_H_ */

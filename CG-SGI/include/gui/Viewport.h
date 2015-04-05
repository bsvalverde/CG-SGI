#ifndef VIEWPORT_H_
#define VIEWPORT_H_

#include <QtCore/qlist.h>
#include <QtCore/qvector.h>
#include <QtWidgets/qgraphicsview.h>

#include "geometria/Ponto.h"

/**
 * Janela de visualização da interface gráfica.
 */
class Viewport {

public:
	/**
	 * Construtor.
	 * @param janelaGrafica objeto gráfico de plotagem.
	 * @param largura largura da viewport.
	 * @param altura altura da viewport.
	 */
	Viewport(QGraphicsView* const janelaGrafica, const double largura, const double altura);

	/**
	 * Destrutor.
	 */
	virtual ~Viewport();

	/**
	 * Atualizar objetos.
	 * @param objetos objetos a serem desenhados.
	 */
	void atualizarObjetos(const QList<ObjetoGeometrico*>& objetos);

private:
	/**
	 * Transformar ponto.
	 * @param coordenadas coordenadas do ponto.
	 * @return coordenadas transformadas.
	 */
	QVector<double> transformarPonto(const QVector<double>& coordenadas);

	/**
	 * Transformar objeto.
	 * @param pontos pontos do objeto.
	 * @return pontos do objeto transformados.
	 */
	QList<Ponto> transformarObjeto(const QList<Ponto>& pontos);

	void desenharAreaClipping(QGraphicsScene* const scene);

	QGraphicsView* janelaGrafica;
	double largura;
	double altura;

	const unsigned int CLIPPING_MARGIN = 20;

};

#endif /* VIEWPORT_H_ */

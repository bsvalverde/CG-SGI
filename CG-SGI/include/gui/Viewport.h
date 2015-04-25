#ifndef VIEWPORT_H_
#define VIEWPORT_H_

#include <QtCore/qlist.h>
#include <QtCore/qvector.h>
#include <QtWidgets/qgraphicsview.h>

#include "geometria/Ponto.h"
#include "gui/clipping/ClippingCohenSutherland.h"
#include "gui/clipping/ClippingLiangBarsky.h"

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
	 * Atualizar a cena.
	 * @param objetos objetos a serem desenhados.
	 */
	void atualizarCena(const QList<ObjetoGeometrico*>& objetos);

	/**
	 * Definir o algoritmo de clipping.
	 * @param algoritmo algoritmo a ser utilizado no recorte de objetos.
	 */
	void setAlgoritmoClippingLinhas(Clipping::AlgoritmoClippingLinha algoritmo);

	/**
	 * Obter os pontos da viewport.
	 * @return lista com os pontos.
	 */
	QList<Ponto> getPontos() const;

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

	/**
	 * Desenhar a área de clipping.
	 * @param scene cena na qual será desenhada a área.
	 */
	void desenharAreaClipping(QGraphicsScene* const scene);

	QGraphicsView* janelaGrafica;
	Clipping* clipping;
	double largura;
	double altura;

	const unsigned int CLIPPING_MARGIN = 20;

};

#endif /* VIEWPORT_H_ */

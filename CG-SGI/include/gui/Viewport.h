#ifndef VIEWPORT_H_
#define VIEWPORT_H_

#include <QtCore/qlist.h>
#include <QtCore/qvector.h>
#include <QtWidgets/qgraphicsview.h>

#include "geometria/Ponto.h"
#include "geometria/Superficie.h"
#include "gui/clipping/ClippingCohenSutherland.h"
#include "gui/clipping/ClippingLiangBarsky.h"
#include "gui/Rasterizador.h"
#include "gui/Iluminador.h"

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
	Viewport(QGraphicsView* const janelaGrafica, const unsigned int largura, const unsigned int altura);

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

	void reiniciarMatrizPixels();
	void desenharCena(QGraphicsScene* const scene);

private:

	/**
	 * Desenhar a área de clipping.
	 * @param scene cena na qual será desenhada a área.
	 */
	void desenharAreaClipping(QGraphicsScene* const scene);

	const unsigned int MARGEM_CLIPPING = 20;
	QGraphicsView* janelaGrafica;
	Clipping* clipping;
	Rasterizador* rasterizador;
	unsigned int largura;
	unsigned int altura;
	Iluminador* iluminador;
	Pixel **matrizPixels;

};

#endif /* VIEWPORT_H_ */

#ifndef CLIPPING_H_
#define CLIPPING_H_

#include "geometria/Poligono.h"
#include "geometria/Ponto.h"
#include "geometria/Reta.h"

/**
 * Recorte de objetos.
 */
class Clipping {

public:
	/**
	 * Algoritmo de clipping de linhas.
	 */
	enum AlgoritmoClippingLinha {
		COHEN_SUTHERLAND,
		LIANG_BARSKY
	};

	enum BordaClipping {
		DIREITA,
		ESQUERDA,
		FUNDO,
		TOPO,
		TODAS
	};

	/**
	 * Construtor.
	 * @param xvMin x mínimo da viewport.
	 * @param xvMax x máximo da viewport.
	 * @param yvMin y mínimo da viewport.
	 * @param yvMax y máximo da viewport.
	 */
	Clipping(const double xvMin, const double xvMax, const double yvMin, const double yvMax);

	/**
	 * Destrutor.
	 */
	virtual ~Clipping();

	/**
	 * Aplicar clipping no objeto.
	 * @param objeto objeto a ser recortado.
	 */
	bool clip(ObjetoGeometrico* const objeto) const;

protected:
	virtual bool clipPoligono(Poligono* const poligono) const;
	virtual bool clipPonto(Ponto* const ponto) const;
	virtual bool clipReta(Reta* const reta) const = 0;

	double xvMin;
	double xvMax;
	double yvMin;
	double yvMax;

private:
	/**
	 * Aplicar clipping da reta sobre uma borda.
	 * @param p1 ponto inicial da reta.
	 * @param p2 ponto final da reta.
	 * @param borda borda na qual os pontos serão recortados.
	 * @return true se pelo menos algum ponto está dentro da viewport.
	 */
	bool clipPontosPorBorda(Ponto* const p1, Ponto* const p2, BordaClipping borda) const;

	/**
	 * Aplicar clipping da reta sobre uma borda.
	 * @param reta reta a ser recortada.
	 * @param borda borda na qual a reta será recortada.
	 */
	void clipRetaPorBorda(Reta* const reta, BordaClipping borda) const;

	/**
	 * Verificar se o ponto está dentro da viewport de acordo com uma borda.
	 * @param p ponto a ser verificado.
	 * @param borda borda a ser verificada.
	 */
	bool pontoDentroDaViewport(Ponto* const p, BordaClipping borda) const;

};

#endif /* CLIPPING_H_ */

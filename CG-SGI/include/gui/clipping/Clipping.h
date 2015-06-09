#ifndef CLIPPING_H_
#define CLIPPING_H_

#include "geometria/CurvaBSpline.h"
#include "geometria/CurvaBezier.h"
#include "geometria/Objeto3D.h"
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
		COHEN_SUTHERLAND, LIANG_BARSKY
	};

	/**
	 * Bordas da viewport para aplicar o clipping.
	 */
	enum BordaClipping {
		DIREITA, ESQUERDA, FUNDO, TOPO
	};

	/**
	 * Construtor.
	 * @param xvMin x mínimo da viewport.
	 * @param xvMax x máximo da viewport.
	 * @param yvMin y mínimo da viewport.
	 * @param yvMax y máximo da viewport.
	 */
	Clipping(const double xvMin, const double xvMax, const double yvMin,
			const double yvMax);

	/**
	 * Destrutor.
	 */
	virtual ~Clipping();

	/**
	 * Recortar o objeto.
	 * @param objeto objeto a ser recortado.
	 * @return lista de pontos recortados.
	 */
	ObjetoGeometrico* clip(ObjetoGeometrico* const objeto) const;

	/**
	 * Recortar o objeto 3D.
	 * @param objeto objeto 3D a ser recortado.
	 * @return lista de arestas recortadas.
	 */
	ObjetoGeometrico* clipObjeto3D(Objeto3D* const objeto) const;

protected:
	/**
	 * Recortar uma curva.
	 * @param curva curva a ser recortada.
	 * @return lista de pontos recortados.
	 */
	virtual ObjetoGeometrico* clipCurva(const Curva* const curva) const;

	/**
	 * Recortar um polígono.
	 * @param poligono polígono a ser recortado.
	 * @return lista de pontos recortados.
	 */
	virtual ObjetoGeometrico* clipPoligono(const Poligono* const poligono) const;

	/**
	 * Recortar um ponto.
	 * @param ponto ponto a ser recortado.
	 * @return lista de pontos recortados.
	 */
	virtual ObjetoGeometrico* clipPonto(const Ponto* const ponto) const;

	/**
	 * Recortar uma reta.
	 * @param reta reta a ser recortada.
	 * @return lista de pontos recortados.
	 */
	virtual ObjetoGeometrico* clipReta(const Reta* const reta) const = 0;

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
	bool clipPontosPorBorda(Ponto* const p1, Ponto* const p2,
			BordaClipping borda) const;

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

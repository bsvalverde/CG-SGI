#ifndef CLIPPINGCOHENSUTHERLAND_H_
#define CLIPPINGCOHENSUTHERLAND_H_

#include "gui/clipping/Clipping.h"

/**
 * Recorte de objetos de Cohen-Sutherland.
 */
class ClippingCohenSutherland : public Clipping {

public:
	/**
	 * Construtor.
	 * @param xvMin x mínimo da viewport.
	 * @param xvMax x máximo da viewport.
	 * @param yvMin y mínimo da viewport.
	 * @param yvMax y máximo da viewport.
	 */
	ClippingCohenSutherland(const double xvMin, const double xvMax, const double yvMin, const double yvMax);

	/**
	 * Destrutor.
	 */
	virtual ~ClippingCohenSutherland();

protected:
	/**
	 * Recortar uma reta.
	 * @param reta reta a ser recortada.
	 * @return true caso seja necessário desenhar a reta.
	 */
	virtual bool clipReta(Reta* const reta) const;

private:
	/**
	 * Carregar o region code do ponto.
	 * @param p ponto a ser verificado.
	 * @param rc vetor no qual o region code será carregado.
	 */
	void carregarRcPonto(const Ponto* const p, short rc[4]) const;

	/**
	 * Recortar ponto quando ele está em um dos quadrantes paralelos à viewport.
	 * @param rc region code do ponto.
	 * @param p ponto a ser recortado.
	 * @param coefAngular coeficiente angular da reta à qual o ponto pertence.
	 * @return true se o ponto foi recortado.
	 */
	bool clippingBasico(short *rc, Ponto* const p, const double coefAngular) const;

	/**
	 * Recortar ponto quando ele está em um dos quadrantes diagonais.
	 * @param rc region code do ponto.
	 * @param p ponto a ser recortado.
	 * @param coefAngular coeficiente angular da reta à qual o ponto pertence.
	 * @return true se o ponto foi recortado.
	 */
	bool clippingComposto(short *rc, Ponto* const p, const double coefAngular) const;

	/**
	 * Recortar o ponto na borda direita.
	 * @param p ponto a ser recortado.
	 * @param coefAngular coeficiente angular da reta à qual o ponto pertence.
	 * @return true se o ponto foi recortado.
	 */
	bool clippingDireita(Ponto* const p, const double coefAngular) const;

	/**
	 * Recortar o ponto na borda esquerda.
	 * @param p ponto a ser recortado.
	 * @param coefAngular coeficiente angular da reta à qual o ponto pertence.
	 * @return true se o ponto foi recortado.
	 */
	bool clippingEsquerda(Ponto* const p, const double coefAngular) const;

	/**
	 * Recortar o ponto na borda do fundo.
	 * @param p ponto a ser recortado.
	 * @param coefAngular coeficiente angular da reta à qual o ponto pertence.
	 * @return true se o ponto foi recortado.
	 */
	bool clippingFundo(Ponto* const p, const double coefAngular) const;

	/**
	 * Recortar o ponto na borda do topo.
	 * @param p ponto a ser recortado.
	 * @param coefAngular coeficiente angular da reta à qual o ponto pertence.
	 * @return true se o ponto foi recortado.
	 */
	bool clippingTopo(Ponto* const p, const double coefAngular) const;

};

#endif /* CLIPPINGCOHENSUTHERLAND_H_ */

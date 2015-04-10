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
	void carregarRcPonto(const Ponto* const p, short rc[4]) const;
	bool clippingBasico(short *rc, Ponto* const p, const double coefAngular) const;
	bool clippingComposto(short *rc, Ponto* const p, const double coefAngular) const;
	bool clippingDireita(Ponto* const p, const double coefAngular) const;
	bool clippingEsquerda(Ponto* const p, const double coefAngular) const;
	bool clippingFundo(Ponto* const p, const double coefAngular) const;
	bool clippingTopo(Ponto* const p, const double coefAngular) const;

};

#endif /* CLIPPINGCOHENSUTHERLAND_H_ */

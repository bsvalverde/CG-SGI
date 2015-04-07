#ifndef CLIPPINGLIANGBARSKY_H_
#define CLIPPINGLIANGBARSKY_H_

#include "gui/clipping/Clipping.h"

/**
 * Recorte de objetos de Liang-Barsky.
 */
class ClippingLiangBarsky: public Clipping {

public:
	/**
	 * Construtor.
	 * @param xvMin x mínimo da viewport.
	 * @param xvMax x máximo da viewport.
	 * @param yvMin y mínimo da viewport.
	 * @param yvMax y máximo da viewport.
	 */
	ClippingLiangBarsky(const double xvMin, const double xvMax,
			const double yvMin, const double yvMax);

	/**
	 * Destrutor.
	 */
	virtual ~ClippingLiangBarsky();

protected:
	virtual bool clipReta(Reta* const reta) const;

private:
	double sigma1(int *p, int *q) const;
	double sigma2(int *p, int *q) const;
};

#endif /* CLIPPINGLIANGBARSKY_H_ */

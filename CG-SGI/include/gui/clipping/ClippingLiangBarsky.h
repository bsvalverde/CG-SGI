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
	/**
	 * Recortar uma reta.
	 * @param reta reta a ser recortada.
	 * @return lista de pontos recortados.
	 */
	virtual QList<Ponto> clipReta(const Reta* const reta) const;

private:
	/**
	 * Obter o Csi 1.
	 * @param p vetor de parâmetros p.
	 * @param q vetor de parâmetros q.
	 * @return o valor de Csi 1.
	 */
	double csi1(double *p, double *q) const;

	/**
	 * Obter o Csi 2.
	 * @param p vetor de parâmetros p.
	 * @param q vetor de parâmetros q.
	 * @return o valor de Csi 2.
	 */
	double csi2(double *p, double *q) const;
};

#endif /* CLIPPINGLIANGBARSKY_H_ */

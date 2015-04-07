#ifndef CLIPPINGNICHOLLLEENICHOLL_H_
#define CLIPPINGNICHOLLLEENICHOLL_H_

#include "gui/clipping/Clipping.h"

/**
 * Recorte de objetos de Nicholl-Lee-Nicholl.
 */
class ClippingNichollLeeNicholl : public Clipping {

public:
	/**
	 * Construtor.
	 * @param xvMin x mínimo da viewport.
	 * @param xvMax x máximo da viewport.
	 * @param yvMin y mínimo da viewport.
	 * @param yvMax y máximo da viewport.
	 */
	ClippingNichollLeeNicholl(const double xvMin, const double xvMax, const double yvMin, const double yvMax);

	/**
	 * Destrutor.
	 */
	virtual ~ClippingNichollLeeNicholl();

protected:
	virtual bool clipReta(Reta* const reta) const;

};

#endif /* CLIPPINGNICHOLLLEENICHOLL_H_ */

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
	enum Algoritmo {
		COHEN_SUTHERLAND,
		LIANG_BARSKY
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

};

#endif /* CLIPPING_H_ */

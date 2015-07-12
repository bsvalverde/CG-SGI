#ifndef ILUMINADOR_H_
#define ILUMINADOR_H_

#include <QtCore/qlist.h>

#include "gui/Pixel.h"
#include "geometria/Ponto.h"

class Iluminador {

public:
	/**
	 * Construtor.
	 * @param tamX largura da viewport.
	 * @param tamY altura da viewport.
	 */
	Iluminador(const unsigned int tamX, const unsigned int tamY);

	/**
	 * Destrutor.
	 */
	~Iluminador();

	/**
	 * Calcula a cor de cada pixel da viewport
	 */
	QList<Pixel> iluminarCena(QList<Pixel> pixels);

private:
	/**
	 * Calcula a componente difusa da luz do pixel.
	 */
	QColor calcularComponenteDifusa(Pixel p);

	/**
	 * Calcula a componente especular da luz do pixel.
	 */
	QColor calcularComponenteEspecular(Pixel p);

	/**
	 * Calcula a componente ambiente da luz do pixel.
	 */
	QColor calcularComponenteAmbiente(Pixel p);

	unsigned int tamX;
	unsigned int tamY;
	Ponto fonteDeLuz;
};

#endif /* ILUMINADOR_H_ */

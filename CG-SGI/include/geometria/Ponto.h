#ifndef PONTO_H_
#define PONTO_H_

#include "geometria/ObjetoGeometrico.h"

/**
 * Ponto
 */
class Ponto : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Ponto();

	/**
	 * Construtor.
	 * @param ponto objeto a ser copiado.
	 */
	Ponto(const Ponto& ponto);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param x coordenada x do ponto.
	 * @param y coordenada y do ponto.
	 * @param z coordenada z do ponto.
	 */
	Ponto(const String& nome, const double x, const double y, const double z);

	/**
	 * Destrutor.
	 */
	virtual ~Ponto();

	/**
	 * Operador de atribuição.
	 * @param ponto objeto a ser copiado.
	 * @return ponto copiado.
	 */
	Ponto& operator=(const Ponto& ponto);

	/**
	 * Obter os pontos do objeto.
	 * @return lista de pontos.
	 */
	QList<Ponto*> getPontos();

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	const String toString() const;

	/**
	 * Obter a coordenada X.
	 * @return coordenada x do ponto.
	 */
	const double getX() const;

	/**
	 * Obter a coordenada Y.
	 * @return coordenada y do ponto.
	 */
	const double getY() const;

	/**
	 * Obter a coordenada Z.
	 * @return coordenada z do ponto.
	 */
	const double getZ() const;

	void setX(const double x);
	void setY(const double y);
	void setZ(const double z);

protected:
	double coord_x;
	double coord_y;
	double coord_z;

};

#endif

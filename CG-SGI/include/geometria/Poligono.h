#ifndef POLIGONO_H_
#define POLIGONO_H_

#include "geometria/Ponto.h"

class Poligono : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Poligono();

	/**
	 * Construtor.
	 * @param poligono objeto a ser copiado.
	 */
	Poligono(const Poligono& poligono);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param pontos pontos do polígono.
	 */
	Poligono(const String& nome, const QList<Ponto>& pontos);

	/**
	 * Destrutor.
	 */
	virtual ~Poligono();

	/**
	 * Operador de atribuição.
	 * @param poligono objeto a ser copiado.
	 * @return polígono copiado.
	 */
	Poligono& operator=(const Poligono& poligono);

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

private:
	QList<Ponto> pontos;

};

#endif

#ifndef POLIGONO_H_
#define POLIGONO_H_

#include "geometria/Ponto.h"

/**
 * Polígono.
 */
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
	 * @param cor cor do polígono.
	 */
	Poligono(const String& nome, const QList<Ponto>& pontos, const QColor& cor = QColor(0, 0, 0));

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
	 * Clonar o objeto.
	 * @return cópia do objeto geométrico.
	 */
	ObjetoGeometrico* clonar() const;

	/**
	 * Obter os pontos do objeto.
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto> getPontos() const;

	/**
	 * Obter os pontos do objeto.
	 * @return lista de pontos.
	 */
	QList<Ponto*> getPontosObjeto();

	void setPontos(const QList<Ponto>& pontos);

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	const String toString() const;

protected:
	QList<Ponto> pontos;

};

#endif

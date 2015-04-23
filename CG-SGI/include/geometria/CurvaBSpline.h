#ifndef CURVABSPLINE_H_
#define CURVABSPLINE_H_

#include "geometria/Curva.h"

/**
 * Curva B-Spline.
 */
class CurvaBSpline: public Curva {

public:
	/**
	 * Construtor.
	 */
	CurvaBSpline();

	/**
	 * Construtor.
	 * @param curva objeto a ser copiado.
	 */
	CurvaBSpline(const CurvaBSpline& curva);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param pontos pontos da curva
	 * @param cor cor da reta.
	 */
	CurvaBSpline(const String& nome, const QList<Ponto>& pontos,
			const QColor& cor);

	/**
	 * Destrutor.
	 */
	virtual ~CurvaBSpline();

	/**
	 * Operador de atribuição.
	 * @param curva objeto a ser copiado.
	 * @return curva copiada.
	 */
	CurvaBSpline& operator=(const CurvaBSpline& curva);

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

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	const String toString() const;

private:
	/**
	 * Calcular pontos paramétricos da curva.
	 * @param t passo de iteração.
	 */
	void calcularPontosParametricos(const double t = 0.01);

	/**
	 * Calcular todos os pontos da curva entre p[0] e p[n]
	 */
	QList<Ponto> calcularPontosParametricosIntermediario(Ponto *p, const double t) const;

	QList<Ponto> pontos;
	QList<Ponto> pontosParametricos;

};

#endif /* CURVABSPLINE_H_ */

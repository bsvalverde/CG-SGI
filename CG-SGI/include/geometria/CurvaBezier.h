#ifndef CURVABEZIER_H_
#define CURVABEZIER_H_

#include "geometria/Curva.h"

/**
 * Curva de Bezier.
 */
class CurvaBezier : public Curva {

public:
	/**
	 * Construtor.
	 */
	CurvaBezier();

	/**
	 * Construtor.
	 * @param curva objeto a ser copiado.
	 */
	CurvaBezier(const CurvaBezier& curva);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param p1 ponto inicial.
	 * @param p2 ponto de controle.
	 * @param p3 ponto de controle.
	 * @param p4 ponto final.
	 * @param cor cor da curva.
	 */
	CurvaBezier(const String& nome, const Ponto& p1, const Ponto& p2,
			const Ponto& p3, const Ponto& p4, const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	virtual ~CurvaBezier();

	/**
	 * Operador de atribuição.
	 * @param curva objeto a ser copiado.
	 * @return curva copiada.
	 */
	CurvaBezier& operator=(const CurvaBezier& curva);

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

protected:
	/**
	 * Calcular pontos paramétricos da curva.
	 * @param t passo de iteração.
	 */
	void calcularPontosParametricos(const double t = 0.01);

	Ponto p1;
	Ponto p2;
	Ponto p3;
	Ponto p4;
	QList<Ponto> pontosParametricos;

};

#endif /* CURVABEZIER_H_ */

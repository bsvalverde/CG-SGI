#ifndef CURVA_H_
#define CURVA_H_

#include "geometria/Ponto.h"

/**
 * Curva paramétrica.
 */
class Curva : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Curva();

	/**
	 * Construtor.
	 * @param curva objeto a ser copiado.
	 */
	Curva(const Curva& curva);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param tipo tipo da curva.
	 * @param cor cor da curva.
	 */
	Curva(const String& nome, const Tipo tipo, const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	virtual ~Curva();

	/**
	 * Operador de atribuição.
	 * @param curva objeto a ser copiado.
	 * @return curva copiada.
	 */
	Curva& operator=(const Curva& curva);

	/**
	 * Aplicar uma transformação ao objeto.
	 * @param matriz matriz de transformação.
	 */
	void aplicarTransformacao(const double matriz[4][4]);

protected:
	/**
	 * Calcular pontos paramétricos da curva.
	 * @param t passo de iteração.
	 */
	virtual void calcularPontosParametricos(const double t = 0.01) = 0;

};

#endif /* CURVA_H_ */

#ifndef SUPERFICIE_H_
#define SUPERFICIE_H_

#include "geometria/Ponto.h"

/**
 * Superfície paramétrica.
 */
class Superficie : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Superficie();

	/**
	 * Construtor.
	 * @param superficie objeto a ser copiado.
	 */
	Superficie(const Superficie& superficie);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param tipo tipo da superficie.
	 * @param cor cor da superficie.
	 */
	Superficie(const String& nome, const Tipo tipo, const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	virtual ~Superficie();

	/**
	 * Operador de atribuição.
	 * @param superficie objeto a ser copiado.
	 * @return superficie copiada.
	 */
	Superficie& operator=(const Superficie& superficie);

	/**
	 * Aplicar uma transformação ao objeto.
	 * @param matriz matriz de transformação.
	 */
	void aplicarTransformacao(const double matriz[4][4]);

	virtual QList<QList<Ponto>> getPontosParametricos() const = 0;

protected:
	/**
	 * Calcular pontos paramétricos da superficie.
	 * @param t passo de iteração.
	 */
	virtual void calcularPontosParametricos(const double t = 0.1) = 0;

};

#endif /* SUPERFICIE_H_ */

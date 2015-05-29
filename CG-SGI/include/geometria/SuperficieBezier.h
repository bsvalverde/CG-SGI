#ifndef SUPERFICIEBEZIER_H_
#define SUPERFICIEBEZIER_H_

#include "geometria/Superficie.h"

/**
 * Superfície Bicúbica de Bezier.
 */
class SuperficieBezier : public Superficie {

public:
	/**
	 * Construtor.
	 */
	SuperficieBezier();

	/**
	 * Construtor.
	 * @param superficie objeto a ser copiado.
	 */
	SuperficieBezier(const SuperficieBezier& superficie);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param pontos[4][4] pontos de controle.
	 * @param cor cor da superficie.
	 */
	SuperficieBezier(const String& nome, const QList<Ponto>& pontos, const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	virtual ~SuperficieBezier();

	/**
	 * Operador de atribuição.
	 * @param superficie objeto a ser copiado.
	 * @return superficie copiada.
	 */
	SuperficieBezier& operator=(const SuperficieBezier& superficie);

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

	QList<QList<Ponto>> getPontosParametricos() const;

protected:
	/**
	 * Calcular pontos paramétricos da superficie.
	 * @param t passo de iteração.
	 */
	void calcularPontosParametricos(const double t = 0.1);

	QList<Ponto> geraCurva(double x[4], double y[4], double z[4], double t);

	Ponto pontos[4][4];
	QList<QList<Ponto>> pontosParametricos;

};

#endif /* SUPERFICIEBEZIER_H_ */

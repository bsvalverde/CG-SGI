#ifndef SUPERFICIEBSPLINE_H_
#define SUPERFICIEBSPLINE_H_

#include "geometria/Superficie.h"

/**
 * Superfície Bicúbica B-Spline.
 */
class SuperficieBSpline: public Superficie {

public:
	/**
	 * Construtor.
	 */
	SuperficieBSpline();

	/**
	 * Construtor.
	 * @param superficie objeto a ser copiado.
	 */
	SuperficieBSpline(const SuperficieBSpline& superficie);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param pontos[4][4] pontos de controle.
	 * @param cor cor da superficie.
	 */
	SuperficieBSpline(const String& nome, const QList<Ponto>& pontos,
			const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	virtual ~SuperficieBSpline();

	/**
	 * Operador de atribuição.
	 * @param superficie objeto a ser copiado.
	 * @return superficie copiada.
	 */
	SuperficieBSpline& operator=(const SuperficieBSpline& superficie);

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

	/**
	 * Obter os pontos paramétricos.
	 * @return matriz de pontos.
	 */
	QList<QList<Ponto>> getPontosParametricos() const;

protected:
	/**
	 * Calcular pontos paramétricos da superficie.
	 * @param t passo de iteração.
	 */
	void calcularPontosParametricos(const double t = 0.1);

	/**
	 * Gerar uma curva b-spline.
	 * @param x1 parâmetro x da curva.
	 * @param x2 parâmetro x da curva.
	 * @param x3 parâmetro x da curva.
	 * @param x4 parâmetro x da curva.
	 * @param y1 parâmetro y da curva.
	 * @param y2 parâmetro y da curva.
	 * @param y3 parâmetro y da curva.
	 * @param y4 parâmetro y da curva.
	 * @param z1 parâmetro z da curva.
	 * @param z2 parâmetro z da curva.
	 * @param z3 parâmetro z da curva.
	 * @param z4 parâmetro z da curva.
	 * @param t parâmetro da curva.
	 * @return lista de pontos da curva gerada.
	 */
	QList<Ponto> geraCurva(double x1, double x2, double x3, double x4,
			double y1, double y2, double y3, double y4, double z1, double z2,
			double z3, double z4, double t);

	Ponto pontos[4][4];
	QList<QList<Ponto>> pontosParametricos;

};

#endif /* SUPERFICIEBSPLINE_H_ */

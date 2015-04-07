#ifndef RETA_H_
#define RETA_H_

#include "geometria/Ponto.h"

/**
 * Reta
 */
class Reta : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Reta();

	/**
	 * Construtor.
	 * @param reta objeto a ser copiado.
	 */
	Reta(const Reta& reta);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param inicial ponto inicial.
	 * @param final ponto final.
	 * @param cor cor da reta.
	 */
	Reta(const String& nome, const Ponto& inicial, const Ponto& final, const QColor& cor = QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	virtual ~Reta();

	/**
	 * Operador de atribuição.
	 * @param reta objeto a ser copiado.
	 * @return reta copiada.
	 */
	Reta& operator=(const Reta& reta);

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
	 * Obter o coeficiente angular da reta.
	 * @return coeficiente angular.
	 */
	double coeficienteAngular() const;

protected:
	Ponto v_inicial;
	Ponto v_final;

};

#endif

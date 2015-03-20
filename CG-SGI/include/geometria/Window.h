#ifndef WINDOW_H_
#define WINDOW_H_

#include "geometria/Ponto.h"

/**
 * Janela de visualização do mundo
 */
class Window : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Window();

	/**
	 * Construtor.
	 * @param window objeto a ser copiado.
	 */
	Window(const Window& window);

	/**
	 * Construtor.
	 * @param pInfEsq ponto inferior esquerdo.
	 * @param pSupDir ponto superior direito.
	 */
	Window(const Ponto& pInfEsq, const Ponto& pSupDir);

	/**
	 * Destrutor.
	 */
	virtual ~Window();

	/**
	 * Operador de atribuição.
	 * @param window objeto a ser copiado.
	 * @return window copiada.
	 */
	Window& operator=(const Window& window);

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
	Ponto pontoInferiorEsquerdo;
	Ponto pontoSuperiorDireito;

};

#endif /* WINDOW_H_ */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "geometria/DisplayFile.h"
#include "geometria/Ponto.h"

/**
 * Janela de visualização do mundo.
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
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto> getPontos() const;

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	const String toString() const;

	/**
	 * Obter o centro geométrico do objeto.
	 * @return o ponto correspondento ao centro.
	 */
	const Ponto getCentroGeometrico() const;

	/**
	 * Atualizar lista de objetos da Window.
	 * @param displayFile lista de objetos nas coordenadas do mundo.
	 */
	void atualizarDisplayFile(const DisplayFile& displayFile);

	/**
	 * Atualizar objeto ou inserí-lo caso não exista.
	 * @param obj objeto geométrico a ser atualizado.
	 */
	void atualizarObjeto(ObjetoGeometrico* obj);

	/**
	 * Remover objeto.
	 * @param nome nome do objeto a ser removido.
	 */
	void removerObjeto(const String& nome);

	/**
	 * Obter lista de objetos nas coordenadas da Window.
	 * @return lista de objetos geométricos.
	 */
	QList<ObjetoGeometrico*> getObjetos() const;

	/**
	 * Transladar a window.
	 * @param sX fator de translação do eixo x.
	 * @param sY fator de translação do eixo y.
	 * @param sZ fator de translação do eixo z.
	 */
	void transladar(const double sX, const double sY, const double sZ);

protected:
	/**
	 * Obter os pontos do objeto.
	 * @return lista de pontos.
	 */
	QList<Ponto*> getPontosObjeto();

	/**
	 * Obter o ângulo do View Up Vector com o eixo Y.
	 * @return o ângulo em radianos.
	 */
	double anguloViewUpVectorEixoY() const;

	/**
	 * Obter o tamanho do View Up Vector.
	 * @param o comprimento do vetor.
	 */
	double tamViewUpVector() const;

	Ponto centro;
	Ponto viewUpVector;
	DisplayFile displayFileNormalizado;

};

#endif /* WINDOW_H_ */

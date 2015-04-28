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
	 * @param centro centro da Window.
	 * @param largura largura da Window.
	 * @param altura altura da Window.
	 */
	Window(const Ponto& centro, const double largura, const double altura);

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
	 * Transladar a window.
	 * @param sX fator de translação do eixo x.
	 * @param sY fator de translação do eixo y.
	 * @param sZ fator de translação do eixo z.
	 */
	void transladar(const double sX, const double sY, const double sZ);

	/**
	 * Obter a largura da Window.
	 * @return largura da Window.
	 */
	const double getLargura() const;

	/**
	 * Obter a altura da Window.
	 * @return altura da Window.
	 */
	const double getAltura() const;

	/**
	 * Atualizar lista de objetos da Window.
	 * @param displayFile lista de objetos nas coordenadas do mundo.
	 */
	void atualizarDisplayFile(const DisplayFile& displayFile);

	/**
	 * Atualizar objeto ou inserí-lo caso não exista.
	 * @param obj objeto geométrico a ser atualizado.
	 */
	void atualizarObjeto(ObjetoGeometrico* const obj);

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
	 * Remover todos os objetos do mundo.
	 */
	void removerObjetos();

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
	double getTamanhoViewUpVector() const;

	/**
	 * Obter o tamanho do View Right Vector.
	 * @param o comprimento do vetor.
	 */
	double getTamanhoViewRightVector() const;

	Ponto centro;
	Ponto viewUpVector;
	Ponto viewRightVector;
	Ponto vpnVector;
	DisplayFile displayFileNormalizado;

};

#endif /* WINDOW_H_ */

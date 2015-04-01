#ifndef MUNDO_H_
#define MUNDO_H_

#include "geometria/DisplayFile.h"
#include "geometria/Poligono.h"
#include "geometria/Ponto.h"
#include "geometria/Reta.h"
#include "geometria/Window.h"

/**
 * Mundo de representação dos objetos reais.
 */
class Mundo {

public:
	/**
	 * Direção de navegação no mundo.
	 */
	enum Direcao {
		CIMA, BAIXO, ESQUERDA, DIREITA
	};

	/**
	 * Construtor.
	 */
	Mundo();

	/**
	 * Destrutor.
	 */
	virtual ~Mundo();

	/**
	 * Definir a janela de visualização do mundo.
	 * @param window janela de visualização.
	 */
	void setWindow(const Window& window);

	/**
	 * Obter os objetos do mundo no sistemas de coordenadas do mundo.
	 * @return lista de objetos normalizados do mundo.
	 */
	QList<ObjetoGeometrico*> getObjetosReais() const;

	/**
	 * Obter os objetos do mundo no sistemas de coordenadas da window.
	 * @return lista de objetos normalizados do mundo.
	 */
	QList<ObjetoGeometrico*> getObjetosNormalizados() const;

	/**
	 * Remover todos os objetos do mundo.
	 */
	void removerObjetos();

	/**
	 * Navegar no mundo (mover a window).
	 * @param direcao direção de navegação.
	 * @param fator fator de navegação.
	 */
	void navegar(const Direcao direcao, const double fator);

	/**
	 * Aplicar zoom no mundo (redimensionar a window do mundo).
	 * @param fator fator de zoom.
	 */
	void aplicarZoom(const double fator);

	/**
	 * Rotacionar a janela de visualização do mundo (window).
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarVisualizacao(const double angulo);

	/**
	 * Reposicionar a visualização do mundo (window), reestabelecendo as coordenadas iniciais.
	 */
	void reiniciarVisualizacao();

	/**
	 * Inserir objeto ao mundo.
	 * @param objeto objeto a ser inserido.
	 */
	void inserirObjeto(const ObjetoGeometrico& objeto);

	/**
	 * Remover objeto do mundo.
	 * @param nome nome do objeto.
	 */
	void removerObjeto(const String& nome);

	/**
	 * Verificar se o mundo contém um objeto.
	 * @param nome nome do objeto.
	 * @return true se o objeto existe.
	 */
	bool contemObjeto(const String& nome) const;

	/**
	 * Escalonar objeto.
	 * @param nome nome do objeto.
	 * @param sX fator de escalonamento da coordenada x.
	 * @param sY fator de escalonamento da coordenada y.
	 * @param sZ fator de escalonamento da coordenada z.
	 */
	void escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ);

	/**
	 * Transladar objeto.
	 * @param nome nome do objeto.
	 * @param sX fator de translação da coordenada x.
	 * @param sY fator de translação da coordenada y.
	 * @param sZ fator de translação da coordenada z.
	 */
	void transladarObjeto(const String& nome, const double sX, const double sY, const double sZ);

	/**
	 * Rotacionar objeto em relação a um ponto específico.
	 * @param nome nome do objeto.
	 * @param ponto ponto de rotação.
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo);

	/**
	 * Rotacionar objeto em relação ao centro geométrico.
	 * @param nome nome do objeto.
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarObjetoPeloCentro(const String& nome, const double angulo);

protected:
	DisplayFile displayFile;
	Window* window;

};

#endif /* MUNDO_H_ */

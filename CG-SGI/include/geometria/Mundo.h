#ifndef MUNDO_H_
#define MUNDO_H_

#include "geometria/DisplayFile.h"
#include "geometria/CurvaBezier.h"
#include "geometria/CurvaBSpline.h"
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
	 * Eixo do mundo.
	 */
	enum Eixo {
		EIXO_X, EIXO_Y, EIXO_Z
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
	 * @return lista de objetos reais do mundo.
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
	 * Obter objeto do mundo.
	 * @param nome nome do objeto.
	 * @return objeto geométrico correspondente.
	 */
	ObjetoGeometrico* getObjeto(const String& nome);

	/**
	 * Verificar se o mundo contém um objeto.
	 * @param nome nome do objeto.
	 * @return true se o objeto existe.
	 */
	bool contemObjeto(const String& nome) const;

	/**
	 * Escalonar objeto.
	 * @param objeto objeto a ser escalonado.
	 * @param sX fator de escalonamento da coordenada x.
	 * @param sY fator de escalonamento da coordenada y.
	 * @param sZ fator de escalonamento da coordenada z.
	 */
	void escalonarObjeto(ObjetoGeometrico* const objeto, const double sX,
			const double sY, const double sZ);

	/**
	 * Transladar objeto.
	 * @param objeto objeto a ser transladado.
	 * @param sX fator de translação da coordenada x.
	 * @param sY fator de translação da coordenada y.
	 * @param sZ fator de translação da coordenada z.
	 */
	void transladarObjeto(ObjetoGeometrico* const objeto, const double sX,
			const double sY, const double sZ);

	/**
	 * Rotacionar objeto em relação a um ponto específico, pelo eixo definido.
	 * @param objeto objeto a ser rotacionado.
	 * @param ponto ponto de rotação.
	 * @param angulo ângulo de rotação em graus.
	 * @param eixo eixo pelo qual a rotação deve ser feita.
	 */
	void rotacionarObjetoPorPonto(ObjetoGeometrico* const objeto,
			const Ponto& ponto, const double angulo, Eixo eixo);

	/**
	 * Rotacionar objeto em relação ao centro geométrico, pelo eixo definido.
	 * @param objeto objeto a ser rotacionado.
	 * @param angulo ângulo de rotação em graus.
	 * @param eixo eixo pelo qual a rotação deve ser feita.
	 */
	void rotacionarObjetoPeloCentro(ObjetoGeometrico* const objeto,
			const double angulo, Eixo eixo);
	/**
	 * Rotacionar objeto em relação ao eixo definido pelo usuário.
	 * @param objeto objeto a ser rotacionado.
	 * @param angulo ângulo de rotação em graus.
	 * @param eixo eixo pelo qual a rotação deve ser feita.
	 */
	void rotacionarObjetoPeloEixo(ObjetoGeometrico* const objeto,
			const double angulo, Reta eixo);

protected:
	DisplayFile displayFile;
	Window* window;

};

#endif /* MUNDO_H_ */

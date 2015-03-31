#ifndef MUNDO_H_
#define MUNDO_H_

#include "geometria/DisplayFile.h"
#include "geometria/Window.h"
#include "geometria/Ponto.h"
#include "geometria/Poligono.h"
#include "geometria/Reta.h"

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

	void setWindow(const Window& window);

	/**
	 * Obter a window do mundo.
	 * @return a window.
	 */
	Window* getWindow() const;

	/**
	 * Obter os objetos do mundo.
	 * @return lista de objetos do mundo.
	 */
	QList<ObjetoGeometrico*> getObjetos() const;

	/**
	 * Navegar no mundo (mover a window).
	 * @param direcao direção de navegação.
	 * @param fator fator de navegação.
	 */
	void navegar(const Direcao direcao, const double fator);

	/**
	 * Redimensionar a window do mundo (aplicação de zoom).
	 * @param fator fator de escalonamento.
	 */
	void redimensionarWindow(const double fator);

	/**
	 * Rotacionar a Window.
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarWindow(const double angulo);

	/**
	 * Escalonar objeto.
	 * @nome nome do objeto.
	 * @param sX fator de escalonamento da coordenada x.
	 * @param sY fator de escalonamento da coordenada y.
	 * @param sZ fator de escalonamento da coordenada z.
	 */
	void escalonarObjeto(const String& nome, const double sX, const double sY,
			const double sZ);

	/**
	 * Transladar objeto.
	 * @nome nome do objeto.
	 * @param sX fator de translação da coordenada x.
	 * @param sY fator de translação da coordenada y.
	 * @param sZ fator de translação da coordenada z.
	 */
	void transladarObjeto(const String& nome, const double sX, const double sY,
			const double sZ);

	/**
	 * Rotacionar objeto em relação a um ponto específico.
	 * @nome nome do objeto.
	 * @param ponto ponto de rotação.
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto,
			const double angulo);

	/**
	 * Rotacionar objeto em relação ao centro geométrico.
	 * @nome nome do objeto.
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarObjetoPeloCentro(const String& nome, const double angulo);

	/**
	 * Reposicionar window, reestabelecendo as coordenadas iniciais.
	 */
	void reiniciarWindow();

protected:
	DisplayFile displayFile;
	Window* window;

};

#endif /* MUNDO_H_ */

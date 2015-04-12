#ifndef CONTROLADORMUNDO_H_
#define CONTROLADORMUNDO_H_

#include "geometria/Mundo.h"

/**
 * Controlador do Mundo.
 */
class ControladorMundo {

public:
	/**
	 * Construtor.
	 */
	ControladorMundo();

	/**
	 * Destrutor.
	 */
	virtual ~ControladorMundo();

	/**
	 * Navegar no mundo (mover a window).
	 * @param direcao direção de navegação.
	 * @param fator fator de navegação.
	 */
	void navegarNoMundo(const Mundo::Direcao direcao, const double fator);

	/**
	 * Aplicar zoom no mundo (redimensionar a window do mundo).
	 * @param fator fator de zoom.
	 */
	void aplicarZoomNoMundo(const double fator);

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
	 * Atualizar todos os objetos do mundo.
	 * @param objetos objetos do mundo.
	 */
	void atualizarObjetos(const QList<ObjetoGeometrico*>& objetos);

	/**
	 * Inserir objeto geométrico.
	 * @param nome nome do objeto.
	 * @param pontos pontos do objeto.
	 * @param tipo tipo do objeto.
	 * @param cor cor do objeto.
	 */
	void inserirObjeto(const String& nome, const QList<Ponto>& pontos, ObjetoGeometrico::Tipo tipo, const QColor& cor);

	/**
	 * Remover objeto geométrico.
	 * @param nome nome do objeto.
	 */
	void removerObjeto(const String& nome);

	/**
	 * Verificar se o mundo contém um objeto.
	 * @param nome nome do objeto.
	 * @return true se o objeto existe.
	 */
	bool contemObjeto(const String& nome);

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
	void transladarObjeto(const String& nome, const double sX, const double sY,	const double sZ);

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

private:
	Mundo mundo;

};

#endif /* CONTROLADORMUNDO_H_ */

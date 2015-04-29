#ifndef CONTROLADORPRINCIPAL_H_
#define CONTROLADORPRINCIPAL_H_

#include "geometria/Mundo.h"

class ControladorMundo;
class ControladorPersistencia;
class ControladorUI;

/**
 * Controlador principal do sistema.
 */
class ControladorPrincipal {

public:
	/**
	 * Construtor.
	 */
	ControladorPrincipal();

	/**
	 * Destrutor.
	 */
	virtual ~ControladorPrincipal();

	/**
	 * Executar a aplicação.
	 */
	void executar();

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
	 * @param eixo eixo de rotação.
	 */
	void rotacionarVisualizacao(const double angulo, const Mundo::Eixo& eixo);

	/**
	 * Reposicionar a visualização do mundo (window), reestabelecendo as coordenadas iniciais.
	 */
	void reiniciarVisualizacao();

	/**
	 * Definir o tipo de projeção da window.
	 * @param tipoProjecao tipo de projeção.
	 */
	void setProjetorVisualizacao(const Projetor::TipoProjecao& tipoProjecao);

	/**
	 * Inserir objeto geométrico no mundo.
	 * @param nome nome do objeto.
	 * @param pontos pontos do objeto.
	 * @param tipo tipo do objeto.
	 * @param cor cor do objeto.
	 */
	void inserirObjeto(const String& nome, const QList<Ponto>& pontos, ObjetoGeometrico::Tipo tipo, const QColor& cor);

	/**
	 * Remover objeto geométrico do mundo.
	 * @param nome nome do objeto.
	 */
	void removerObjeto(const String& nome);

	/**
	 * Remover objetos do mundo.
	 */
	void removerObjetosMundo();

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

	/**
	 * Importar cena de um arquivo OBJ (Wavefront).
	 * @param nomeArquivo nome completo do arquivo.
	 */
	void importarCena(const String& nomeArquivo);

	/**
	 * Exportar cena para um arquivo OBJ (Wavefront).
	 * @param nomeArquivo nome completo do arquivo.
	 */
	void exportarCena(const String& nomeArquivo);

private:
	ControladorMundo* controladorMundo;
	ControladorPersistencia* controladorPersistencia;
	ControladorUI* controladorUI;

};

#endif /* CONTROLADORPRINCIPAL_H_ */

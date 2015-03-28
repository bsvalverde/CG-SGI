#ifndef CONTROLADORUI_H_
#define CONTROLADORUI_H_

#include <QtWidgets/qmessagebox.h>

#include <string>
#include "geometria/Ponto.h"
#include "geometria/Mundo.h"

class MainWindow;
class ObjectInsertionWindow;
class ObjectTransformationWindow;

typedef std::string String;

/**
 * Controlador da Interface Gráfica.
 */
class ControladorUI {

public:
	/**
	 * Construtor.
	 */
	ControladorUI();

	/**
	 * Destrutor.
	 */
	virtual ~ControladorUI();

	/**
	 * Executar a interface gráfica.
	 */
	void executar();

	/**
	 * Exibir janela de inserção de objetos.
	 */
	void exibirObjectInsertionWindow();

	/**
	 * Exibir janela de transformação de objetos.
	 * @param nomeObjeto nome do objeto a ser transformado.
	 */
	void exibirObjectTransformationWindow(const String& nomeObjeto);

	/**
	 * Navegar no mundo (mover a window).
	 * @param direcao direção de navegação.
	 * @param fator fator de navegação.
	 */
	void navegarNoMundo(const Mundo::Direcao direcao, const double fator);

	/**
	 * Redimensionar a window do mundo (aplicação de zoom).
	 * @param fator fator de escalonamento.
	 */
	void redimensionarWindow(const double fator);

	void rotacionarWindow(const double angulo);

	/**
	 * Escalonar objeto.
	 * @nome nome do objeto.
	 * @param sX fator de escalonamento da coordenada x.
	 * @param sY fator de escalonamento da coordenada y.
	 * @param sZ fator de escalonamento da coordenada z.
	 */
	void escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ);

	/**
	 * Transladar objeto.
	 * @nome nome do objeto.
	 * @param sX fator de translação da coordenada x.
	 * @param sY fator de translação da coordenada y.
	 * @param sZ fator de translação da coordenada z.
	 */
	void transladarObjeto(const String& nome, const double sX, const double sY, const double sZ);

	/**
	 * Rotacionar objeto em relação a um ponto específico.
	 * @nome nome do objeto.
	 * @param ponto ponto de rotação.
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo);

	/**
	 * Rotacionar objeto em relação ao centro geométrico.
	 * @nome nome do objeto.
	 * @param angulo ângulo de rotação em graus.
	 */
	void rotacionarObjetoPeloCentro(const String& nome, const double angulo);

	/**
	 * Inserir objeto geométrico.
	 * @param nome nome do objeto.
	 * @param pontos pontos do objeto.
	 * @param cor cor do objeto.
	 */
	void inserirObjeto(const String& nome, const QList<Ponto> pontos, const QColor& cor);

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
	 * Exibir mensagem de erro.
	 * @param mensagem mensagem de erro.
	 */
	void exibirMensagemErro(const String& mensagem) const;

protected:
	Mundo mundo;
	MainWindow* mainWindow;
	ObjectInsertionWindow* objectInsertionWindow;
	ObjectTransformationWindow* objectTransformationWindow;

};

#endif /* CONTROLADORUI_H_ */

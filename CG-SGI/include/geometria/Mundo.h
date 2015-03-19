#ifndef MUNDO_H_
#define MUNDO_H_

#include "geometria/DisplayFile.h"
#include "geometria/Window.h"

/**
 * Mundo de representação dos objetos reais.
 */
class Mundo {

public:

	enum Direcao {
		CIMA,
		BAIXO,
		ESQUERDA,
		DIREITA
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
	void inserirObjeto(ObjetoGeometrico* const objeto);

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
	bool contemObjeto(const String& nome);

	/**
	 * Obter a window do mundo.
	 * @return a window.
	 */
	const Window& getWindow() const;

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

private:
	DisplayFile displayFile;
	Window window;

};

#endif /* MUNDO_H_ */

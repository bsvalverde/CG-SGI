#ifndef CONTROLADORUI_H_
#define CONTROLADORUI_H_

#include <string>
#include "geometria/Ponto.h"
#include "geometria/Mundo.h"

class MainWindow;
class ObjectInsertionWindow;

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
	 */
	void exibirObjectTransformationWindow();

	/**
	 * Inserir objeto geométrico.
	 * @param nome nome do objeto.
	 * @param pontos pontos do objeto.
	 */
	void inserirObjeto(const String& nome, const QList<Ponto> pontos);

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
	 * Obter as coordenadas da window do mundo.
	 * @return lista de pontos.
	 */
	QList<Ponto> getPontosWindow() const;

private:
	Mundo mundo;
	MainWindow* mainWindow;
	ObjectInsertionWindow* objectInsertionWindow;

};

#endif /* CONTROLADORUI_H_ */

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

	void exibirObjectInsertionWindow();

	void inserirObjeto(String nome, QList<Ponto> pontos);

	Mundo getMundo() const;

private:
	Mundo mundo;
	MainWindow* mainWindow;
	ObjectInsertionWindow* objectInsertionWindow;

};

#endif /* CONTROLADORUI_H_ */

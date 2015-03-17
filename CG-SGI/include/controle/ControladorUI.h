#ifndef CONTROLADORUI_H_
#define CONTROLADORUI_H_

#include "geometria/DisplayFile.h"
#include "geometria/Poligono.h"
#include "geometria/Ponto.h"
#include "geometria/Reta.h"

class MainWindow;
class ObjectInsertionWindow;

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

private:
	DisplayFile displayFile;
	MainWindow* mainWindow;
	ObjectInsertionWindow* objectInsertionWindow;

};

#endif /* CONTROLADORUI_H_ */

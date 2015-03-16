#ifndef CONTROLADORUI_H_
#define CONTROLADORUI_H_

#include "gui/forms/MainWindow.h"

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

private:
	MainWindow *mainWindow;

};

#endif /* CONTROLADORUI_H_ */

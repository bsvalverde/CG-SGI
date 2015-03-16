#ifndef CONTROLADORUI_H_
#define CONTROLADORUI_H_

#include "gui/forms/MainWindow.h"

/**
 * Controlador da Interface Gr�fica.
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
	 * Executar a interface gr�fica.
	 */
	void executar();

private:
	MainWindow *mainWindow;

};

#endif /* CONTROLADORUI_H_ */

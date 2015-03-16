#ifndef CONTROLADORUI_H_
#define CONTROLADORUI_H_

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

	void showObjectInsertionWindow();

private:
	MainWindow* mainWindow;
	ObjectInsertionWindow* objectInsertionWindow;

};

#endif /* CONTROLADORUI_H_ */

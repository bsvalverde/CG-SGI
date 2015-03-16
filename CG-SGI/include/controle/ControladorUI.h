#ifndef CONTROLADORUI_H_
#define CONTROLADORUI_H_

class MainWindow;
class ObjectInsertionWindow;

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

	void showObjectInsertionWindow();

private:
	MainWindow* mainWindow;
	ObjectInsertionWindow* objectInsertionWindow;

};

#endif /* CONTROLADORUI_H_ */

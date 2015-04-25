#ifndef FORM_H_
#define FORM_H_

#include <QtWidgets/qdialog.h>
#include <QtWidgets/qdesktopwidget.h>

#include "controle/ControladorUI.h"

/**
 * Formulário.
 */
class Form : public QDialog {

public:
	/**
	 * Construtor.
	 * @param controladorUI controlador da interface gráfica.
	 * @param pai formulário pai.
	 * @param flags flags de propriedades do formulário.
	 */
	Form(ControladorUI* controladorUI, QWidget* pai = 0, Qt::WindowFlags flags = Qt::Widget);

	/**
	 * Destrutor.
	 */
	virtual ~Form();

	/**
	 * Mover o formulário para o centro.
	 */
	void centralizar();

	/**
	 * Obter o controlador de interface gráfica.
	 * @return o controlador.
	 */
	ControladorUI* getControladorUI();

protected:
	/**
	 * Conectar os sinais e slots dos objetos do formulário.
	 */
	virtual void conectarSinaisSlots() = 0;

protected:
	ControladorUI* controladorUI;

};

#endif /* FORM_H_ */

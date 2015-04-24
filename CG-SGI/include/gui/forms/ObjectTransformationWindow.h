#ifndef OBJECTTRANSFORMATIONWINDOW_H_
#define OBJECTTRANSFORMATIONWINDOW_H_

#include "controle/ControladorUI.h"
#include "geometria/Ponto.h"
#include "gui/forms/Form.h"
#include "gui/forms/ui/ui_ObjectTransformationWindow.h"

class ObjectTransformationWindow : public Form, private Ui::ObjectTransformationWindow {
	Q_OBJECT

public:
	ObjectTransformationWindow(ControladorUI* controladorUI, QWidget* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	void clearFields();
	void show(const String& nomeObjeto);

protected:
	void conectarSinaisSlots();
	bool validateFields();

	String nomeObjeto;

private slots:
	void transformObject();
	void specificPointSelected(bool selected);

};

#endif /* OBJECTTRANSFORMATIONWINDOW_H_ */

#ifndef OBJECTTRANSFORMATIONWINDOW_H_
#define OBJECTTRANSFORMATIONWINDOW_H_

#include <QtWidgets/qmessagebox.h>

#include "controle/ControladorUI.h"
#include "geometria/Ponto.h"
#include "gui/forms/ui/ui_ObjectTransformationWindow.h"
#include "gui/forms/DefaultWindow.h"

class ObjectTransformationWindow : public DefaultWindow, private Ui::ObjectTransformationWindow {
	Q_OBJECT

public:
	ObjectTransformationWindow(ControladorUI* controladorUI, QWidget* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	void clearFields();
	void show(const String& nomeObjeto);

protected:
	void connectSignalsAndSlots();
	bool validateFields();

private slots:
	void transformObject();
	void specificPointSelected(bool selected);

private:
	String nomeObjeto;

};

#endif /* OBJECTTRANSFORMATIONWINDOW_H_ */

#ifndef OBJECTINSERTIONWINDOW_H_
#define OBJECTINSERTIONWINDOW_H_

#include "gui/forms/ui/ui_ObjectInsertionWindow.h"
#include "gui/forms/Window.h"
#include <iostream>

class ObjectInsertionWindow : public Window, private Ui::ObjectInsertionWindow {
	Q_OBJECT

public:
	ObjectInsertionWindow(ControladorUI* controladorUI, QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	void clearFields();

protected:
	void connectSignalsAndSlots();

private slots:
	void insertObject();
	void insertPoligonPoint();
	void removePoligonPoint();

};

#endif /* OBJECTINSERTIONWINDOW_H_ */

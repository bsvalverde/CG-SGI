#ifndef OBJECTINSERTIONWINDOW_H_
#define OBJECTINSERTIONWINDOW_H_

#include <QtWidgets/qcolordialog.h>

#include "controle/ControladorUI.h"
#include "geometria/Ponto.h"
#include "gui/forms/DefaultWindow.h"
#include "gui/forms/ui/ui_ObjectInsertionWindow.h"

class ObjectInsertionWindow : public DefaultWindow, private Ui::ObjectInsertionWindow {
	Q_OBJECT

public:
	ObjectInsertionWindow(ControladorUI* controladorUI, QWidget* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	void clearFields();

protected:
	void connectSignalsAndSlots();
	bool validateFields();

private slots:
	void insertObject();
	void insertPoligonPoint();
	void removePoligonPoint();
	void insertBSplinePoint();
	void removeBSplinePoint();
	void btnSelectColorClicked();

};

#endif /* OBJECTINSERTIONWINDOW_H_ */

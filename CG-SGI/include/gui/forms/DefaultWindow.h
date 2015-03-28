#ifndef DEFAULTWINDOW_H_
#define DEFAULTWINDOW_H_

#include <QtWidgets/qdialog.h>
#include <QtWidgets/qdesktopwidget.h>

#include "controle/ControladorUI.h"

class DefaultWindow : public QDialog {

public:
	DefaultWindow(ControladorUI* controladorUI, QWidget* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	virtual ~DefaultWindow();
	void moveToCenter();
	ControladorUI* getControladorUI();

protected:
	virtual void connectSignalsAndSlots() = 0;

protected:
	ControladorUI* controladorUI;

};

#endif /* WINDOW_H_ */

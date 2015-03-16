#ifndef WINDOW_H_
#define WINDOW_H_

#include <QtWidgets/qdialog.h>
#include <QtWidgets/qdesktopwidget.h>

#include "controle/ControladorUI.h"

class Window : public QDialog {

public:
	Window(ControladorUI* controladorUI, QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	virtual ~Window();
	void moveToCenter();

protected:
	virtual void connectSignalsAndSlots() = 0;

protected:
	ControladorUI* controladorUI;

};

#endif /* WINDOW_H_ */

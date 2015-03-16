#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "gui/forms/ui/ui_MainWindow.h"
#include "gui/forms/Window.h"
#include <iostream>

class MainWindow : public Window, private Ui::MainWindow {
	Q_OBJECT

public:
	MainWindow(ControladorUI* controladorUI, QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);

protected:
	void connectSignalsAndSlots();

private slots:
     void btnZoomInPressed();
     void btnZoomOutPressed();
     void zoomControlValueChanged(int currentValue);
     void btnInsertObjectClicked();
     void btnRemoveObjectClicked();

};

#endif /* MAINWINDOW_H_ */

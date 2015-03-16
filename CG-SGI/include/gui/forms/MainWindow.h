#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "gui/forms/ui/ui_MainWindow.h"
#include "gui/forms/Window.h"
#include <iostream>

class MainWindow : public Window, private Ui::MainWindow {
	Q_OBJECT

public:
	MainWindow(QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);

private:
	void connectSignalsAndSlots();

private slots:
     void btnZoomInPressed();
     void btnZoomOutPressed();
     void zoomControlValueChanged(int currentValue);

};

#endif /* MAINWINDOW_H_ */

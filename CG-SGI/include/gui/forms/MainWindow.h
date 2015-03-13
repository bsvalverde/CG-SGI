#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "Window.h"
#include "ui/ui_MainWindow.h"
#include <iostream>

class MainWindow : public Window, private Ui::MainWindow {

public:
	MainWindow(QDialog *parent = 0, Qt::WindowFlags flags = Qt::Widget);

protected:
	void connectSignalsAndSlots();

private slots:
     void on_btnZoomIn_pressed();
     void on_btnZoomOut_pressed();

};

#endif /* MAINWINDOW_H_ */

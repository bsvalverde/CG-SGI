#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "Window.h"
#include "ui/ui_MainWindow.h"

class MainWindow : public Window, private Ui::MainWindow {

public:
	MainWindow(QDialog *parent = 0);

};

#endif /* MAINWINDOW_H_ */

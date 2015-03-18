#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QtWidgets/qmessagebox.h>

#include "gui/forms/DefaultWindow.h"
#include "gui/forms/ui/ui_MainWindow.h"
#include "geometria/Mundo.h"
#include <iostream>

class MainWindow : public DefaultWindow, private Ui::MainWindow {
	Q_OBJECT

public:
	MainWindow(ControladorUI* controladorUI, QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	virtual ~MainWindow();
	void updateObjects(QList<ObjetoGeometrico> objects);
	QList<ObjetoGeometrico> viewportTransformation(QList<ObjetoGeometrico> objects);
	Ponto pointTransformation(const Ponto& point, double xwMin, double xwMax, double ywMin, double ywMax);

protected:
	void connectSignalsAndSlots();

private slots:
     void btnZoomInPressed();
     void btnZoomOutPressed();
     void zoomControlValueChanged(int currentValue);
     void btnNavigationUpPressed();
     void btnNavigationLeftPressed();
     void btnNavigationCenterPressed();
     void btnNavigationRightPressed();
     void btnNavigationDownPressed();
     void btnInsertObjectClicked();
     void btnRemoveObjectClicked();
     void btnTransformObjectClicked();

private:
     double viewportWidth;
     double viewportHeight;

};

#endif /* MAINWINDOW_H_ */

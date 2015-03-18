#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "geometria/Window.h"
#include "gui/forms/ui/ui_MainWindow.h"
#include "gui/forms/DefaultWindow.h"

class MainWindow : public DefaultWindow, private Ui::MainWindow {
	Q_OBJECT

public:
	MainWindow(ControladorUI* controladorUI, QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	void updateObjects(Window& window, QList<ObjetoGeometrico> objects);
	QList<ObjetoGeometrico> viewportTransformation(Window& window, QList<ObjetoGeometrico> objects);
	Ponto pointTransformation(Ponto point, double xwMin, double xwMax, double ywMin, double ywMax);

protected:
	void connectSignalsAndSlots();

private slots:
     void btnZoomInPressed();
     void btnZoomOutPressed();
     void zoomControlValueChanged(int currentValue);
     void btnInsertObjectClicked();
     void btnRemoveObjectClicked();
     void btnNavigationUpPressed();
     void btnNavigationLeftPressed();
     void btnNavigationCenterPressed();
     void btnNavigationRightPressed();
     void btnNavigationDownPressed();

private:
     double viewportWidth;
     double viewportHeight;

};

#endif /* MAINWINDOW_H_ */

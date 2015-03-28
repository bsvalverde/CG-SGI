#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QtWidgets/qmessagebox.h>

#include "gui/forms/DefaultWindow.h"
#include "gui/forms/ui/ui_MainWindow.h"
#include "gui/Viewport.h"

class MainWindow : public DefaultWindow, private Ui::MainWindow {
	Q_OBJECT

public:
	MainWindow(ControladorUI* controladorUI, QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	virtual ~MainWindow();
	void updateObjects(const QList<ObjetoGeometrico*>& objects);

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
     void btnRotateLeftPressed();
     void btnRotateRightPressed();
     void btnInsertObjectClicked();
     void btnRemoveObjectClicked();
     void btnTransformObjectClicked();

private:
     Viewport* viewport;
     int zoomValue;

};

#endif /* MAINWINDOW_H_ */

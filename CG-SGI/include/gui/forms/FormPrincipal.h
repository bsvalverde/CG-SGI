#ifndef FORMPRINCIPAL_H_
#define FORMPRINCIPAL_H_

#include <QtWidgets/qdesktopwidget.h>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qmenubar.h>

#include "controle/ControladorUI.h"
#include "gui/forms/ui/ui_FormPrincipal.h"
#include "gui/Viewport.h"

class FormPrincipal : public QMainWindow, private Ui::FormPrincipal {
	Q_OBJECT

public:
	FormPrincipal(ControladorUI* controladorUI, QDialog* parent = 0, Qt::WindowFlags flags = Qt::Widget);
	virtual ~FormPrincipal();
	void moveToCenter();
	ControladorUI* getControladorUI();
	void updateObjects(const QList<ObjetoGeometrico*>& objects);

protected:
	void connectSignalsAndSlots();
	void initializeMenuBar();

private slots:
	void encerrar();
	void btnZoomInPressed();
	void btnZoomOutPressed();
	void zoomControlValueChanged(int currentValue);
	void btnNavigationUpPressed();
	void btnNavigationLeftPressed();
	void btnNavigationCenterPressed();
	void btnNavigationRightPressed();
	void btnNavigationDownPressed();
	void btnRotation(int currentValue);
	void btnInsertObjectClicked();
	void btnRemoveObjectClicked();
	void btnTransformObjectClicked();
	void btnImportScene();
	void btnExportScene();
	void btnCleanScene();
	void btnAtalhos();
	void btnSobre();
	void btnClippingCSToggled(bool cohenSutherland);

private:
	ControladorUI* controladorUI;
	Viewport* viewport;
	int zoomValue;
	int rotationValue;

};

#endif /* FORMPRINCIPAL_H_ */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <qt5/QtWidgets/qdialog.h>
#include <qt5/QtWidgets/qdesktopwidget.h>

class Window : public QDialog {
	Q_OBJECT

public:
	Window(QDialog *parent = 0, Qt::WindowFlags flags = Qt::Widget);
	void moveToCenter();

protected:
	virtual void connectSignalsAndSlots() = 0;

private slots:
	virtual void on_btnZoomIn_pressed() = 0;
	virtual void on_btnZoomOut_pressed() = 0;

};

#endif /* WINDOW_H_ */

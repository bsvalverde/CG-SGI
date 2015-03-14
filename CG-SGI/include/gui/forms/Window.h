#ifndef WINDOW_H_
#define WINDOW_H_

#include <qt5/QtWidgets/qdialog.h>
#include <qt5/QtWidgets/qdesktopwidget.h>

class Window : public QDialog {

public:
	Window(QDialog *parent = 0, Qt::WindowFlags flags = Qt::Widget);
	void moveToCenter();

};

#endif /* WINDOW_H_ */

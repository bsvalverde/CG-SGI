#ifndef WINDOW_H_
#define WINDOW_H_

#include <qt5/QtWidgets/qwidget.h>
#include <qt5/QtWidgets/qdesktopwidget.h>

class Window : public QWidget {
	Q_OBJECT

public:
	Window(QWidget *parent = 0);
	void moveToCenter();

};

#endif /* WINDOW_H_ */

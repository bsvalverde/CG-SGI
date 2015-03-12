#include "control/SGIApp.h"

SGIApp::SGIApp(int argc, char *argv[]) : QApplication(argc, argv) { }

SGIApp::~SGIApp() { }

int SGIApp::exec() {
	MainWindow mainWindow;
	mainWindow.show();
	return QApplication::exec();
}

int main(int argc, char *argv[]) {
	SGIApp app(argc, argv);
	return app.exec();
}

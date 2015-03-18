#include "controle/SGIApp.h"

#include "geometria/Ponto.h"
#include "geometria/Reta.h"
#include "geometria/Poligono.h"

SGIApp::SGIApp(int argc, char *argv[]) : QApplication(argc, argv) {
}

SGIApp::~SGIApp() {}

int SGIApp::exec() {
	ControladorUI controladorUI;
	controladorUI.executar();
	return QApplication::exec();
}

int main(int argc, char *argv[]) {
	SGIApp app(argc, argv);
	return app.exec();
}

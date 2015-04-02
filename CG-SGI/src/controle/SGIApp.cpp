#include "controle/SGIApp.h"
#include "controle/ControladorPrincipal.h"

SGIApp::SGIApp(int argc, char *argv[]) : QApplication(argc, argv) {}

SGIApp::~SGIApp() {}

int SGIApp::exec() {
	ControladorPrincipal controlador;
	controlador.executar();
	return QApplication::exec();
}

int main(int argc, char *argv[]) {
	SGIApp app(argc, argv);
	return app.exec();
}

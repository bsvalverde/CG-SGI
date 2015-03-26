#include "controle/SGIApp.h"
#include "persistencia/ArquivoOBJ.h"

SGIApp::SGIApp(int argc, char *argv[]) : QApplication(argc, argv) {}

SGIApp::~SGIApp() {}

int SGIApp::exec() {
	ControladorUI controladorUI;
	controladorUI.executar();
	return QApplication::exec();
}

int main(int argc, char *argv[]) {
	ArquivoOBJ arq("teste.obj");
	arq.carregarObjetos();

	SGIApp app(argc, argv);
	return app.exec();
}

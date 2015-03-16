#include "controle/SGIApp.h"

#include "geometria/Ponto.h"
#include "geometria/Reta.h"
#include "geometria/Poligono.h"

SGIApp::SGIApp(int argc, char *argv[]) : QApplication(argc, argv) {}

SGIApp::~SGIApp() {}

int SGIApp::exec() {
	ControladorUI controladorUI;
	controladorUI.executar();
	return QApplication::exec();
}

int main(int argc, char *argv[]) {
	SGIApp app(argc, argv);
	app.test();
	return app.exec();
}

void SGIApp::test() {
	Ponto p1("p1", 1, 2, 3);
	std::cout << p1.getNome() << p1.toString() << std::endl;
	std::cout << p1.getPontos().at(0).getNome() << std::endl;

	Ponto p2("p2", 5, 4, 98);
	std::cout << p2.getNome() << p2.toString() << std::endl;
	std::cout << p2.getPontos().at(0).getNome() << std::endl;

	Reta r("r1", p1, p2);
	std::cout << r.getNome() << r.toString() << std::endl;
	QList<Ponto> ps = r.getPontos();
	std::cout << ps.at(0).toString() << std::endl;
	std::cout << ps.at(1).toString() << std::endl;

	Ponto p3("p3", 10, 10, 10);

	QList<Ponto> pts;
	pts.insert(0, p1);
	pts.insert(1, p2);
	pts.insert(2, p3);

	Poligono pol("pol1", pts);
	std::cout << pol.getNome() << pol.toString() << std::endl;

}

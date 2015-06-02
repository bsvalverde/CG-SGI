#include "geometria/projecao/ProjetorPerspectiva.h"
#include "geometria/ObjetoGeometrico.h"
#include "geometria/Window.h"

ProjetorPerspectiva::ProjetorPerspectiva(Window* const window) :
		Projetor(Projetor::PERSPECTIVA, window) {
}

ProjetorPerspectiva::~ProjetorPerspectiva() {
}

void ProjetorPerspectiva::projetarObjeto(ObjetoGeometrico* const objeto) const {
	Ponto vrp = this->window->getCentroGeometrico();
	Ponto cop = this->window->getCentroProjecao();
	Ponto vpn = this->window->getVpnVector();
	double x = cop.getX();
	double y = cop.getY();
	double z = cop.getZ();
	double xC = vpn.getX() - vrp.getX();
	double yC = vpn.getY() - vrp.getY();
	double zC = vpn.getZ() - vrp.getZ();
	double d = -z;

	double angX = atan(yC / sqrt(xC * xC + zC * zC));
	double angY = atan(xC / sqrt(yC * yC + zC * zC));

//	if (xC > 0 && zC < 0) {
//		angY += M_PI;
//	} else if (xC < 0 && zC < 0) {
//		angY += -M_PI;
//	}
//
//	if (yC > 0 && zC < 0) {
//		angX += M_PI;
//	} else if (yC < 0 && zC < 0) {
//		angX += -M_PI;
//	}

	double matriz[4][4] = { { cos(-angY), 0, sin(-angY), 0 },
					{ sin(-angX)*sin(-angY), cos(-angX), -sin(-angX)*cos(-angY), 0 },
					{ -cos(-angX)*sin(-angY), sin(-angX), cos(-angX)*cos(-angY), 0 },
					{ -x*cos(-angY) - y*sin(-angX)*sin(-angY) + z*cos(-angX)*sin(-angY),
						-y*cos(-angX) - z*sin(-angX), -x*sin(-angY) + y*sin(-angX)*cos(-angY) - z*cos(-angX)*cos(-angY), 1 } };

	QList<Ponto*> pontosObj = objeto->getPontosObjeto();

	for(Ponto* ponto : pontosObj) {
		ponto->aplicarTransformacao(matriz);
		double xp = d * ponto->getX() / ponto->getZ();
		double yp = d * ponto->getY() / ponto->getZ();
		ponto->setX(xp);
		ponto->setY(yp);
	}
}

#include "geometria/projecao/ProjetorParalelo.h"
#include "geometria/ObjetoGeometrico.h"
#include "geometria/Window.h"

ProjetorParalelo::ProjetorParalelo(Window* const window) :
		Projetor(Projetor::PARALELA_ORTOGONAL, window) {
}

ProjetorParalelo::~ProjetorParalelo() {
}

void ProjetorParalelo::projetarObjeto(ObjetoGeometrico* const objeto) const {
	Ponto vrp = this->window->getCentroGeometrico();
	Ponto vpn = this->window->getVpnVector();
	double xC = vpn.getX() - vrp.getX();
	double yC = vpn.getY() - vrp.getY();
	double zC = vpn.getZ() - vrp.getZ();

	double angX = atan(yC / sqrt(xC * xC + zC * zC));
	double angY = atan(xC / zC);

	double matriz[4][4] = { { cos(angY), 0, -sin(angY), 0 },
					{ sin(angX)*sin(angY), cos(angX), sin(angX)*cos(angY), 0 },
					{ cos(angX)*sin(angY), -sin(angX), cos(angX)*cos(angY), 0 },
					{ -xC*cos(angY) + sin(angY)*(-yC*sin(angX) -zC*cos(angX)),
					-yC*cos(angX) + zC*sin(angX), xC*sin(angY) + cos(angY)*(-yC*sin(angX) -zC*cos(angX)), 1 } };
	objeto->aplicarTransformacao(matriz);
}

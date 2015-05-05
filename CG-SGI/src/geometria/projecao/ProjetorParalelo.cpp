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
	double angY = atan(xC / sqrt(yC * yC + zC * zC));

	if (xC < 0 && zC < 0) { // 3º quadrante
		angY += M_PI;
	} else if (xC > 0 && zC < 0) { // 4º quadrante
		angY += -M_PI;
	}

	if (yC < 0 && zC < 0) { // 3º quadrante
		angX += M_PI;
	} else if (yC > 0 && zC < 0) { // 4º quadrante
		angX += -M_PI;
	}

	double matriz[4][4] = { { cos(-angY), 0, -sin(-angY), 0 },
					{ -sin(-angX)*sin(-angY), cos(-angX), -sin(-angX)*cos(-angY), 0 },
					{ cos(-angX)*sin(-angY), sin(-angX), cos(-angX)*cos(-angY), 0 },
					{ 0, 0, 0, 1 } };
	objeto->aplicarTransformacao(matriz);
	objeto->rotacionarPorX(Ponto("", 0, 0, 0), -angX);
	objeto->rotacionarPorY(Ponto("", 0, 0, 0), -angY);
}

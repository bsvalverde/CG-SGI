#include "gui/Iluminador.h"

#include <iostream>
using namespace std;

Iluminador::Iluminador(const unsigned int tamX, const unsigned int tamY) {
	this->tamX = tamX;
	this->tamY = tamY;
	this->fonteDeLuz = Ponto("", 0, 0, 0);
}

Iluminador::~Iluminador() {
}

Pixel Iluminador::iluminarPixel(Pixel p) {
	QColor corDif = this->calcularComponenteDifusa(p);
	QColor corEsp = this->calcularComponenteEspecular(p);
	QColor corAmb = this->calcularComponenteAmbiente(p);
	int rDif;
	int gDif;
	int bDif;
	int rEsp;
	int gEsp;
	int bEsp;
	int rAmb;
	int gAmb;
	int bAmb;
	int a;
	corDif.getRgb(&rDif, &gDif, &bDif, &a);
	corEsp.getRgb(&rEsp, &gEsp, &bEsp, &a);
	corAmb.getRgb(&rAmb, &gAmb, &bAmb, &a);
	int iR = rDif + rEsp + rAmb;
	if (iR > 255) {
		iR = 255;
	}
	int iG = gDif + gEsp + gAmb;
	if (iG > 255) {
		iG = 255;
	}
	int iB = bDif + bEsp + bAmb;
	if (iB > 255) {
		iB = 255;
	}
	p.setCor(QColor(iR, iG, iB));
	return p;
}

QColor Iluminador::calcularComponenteDifusa(Pixel p) {
	Ponto normal = p.getNormal();
	double xN = this->fonteDeLuz.getX() - p.getX();
	double yN = this->fonteDeLuz.getY() - p.getY();
	double zN = this->fonteDeLuz.getZ() - p.getZ();
	double comprimento = sqrt(xN * xN + yN * yN + zN * zN);
	Ponto vN("", xN / comprimento, yN / comprimento, zN / comprimento); //vetor normalizado apontando para a fonte de luz
	double multVetores = normal.getX() * vN.getX() + normal.getY() * vN.getY()
			+ normal.getZ() * vN.getZ();
	if(multVetores<0)
		multVetores = 0;
	QColor cor = p.getCor();
	int r;
	int g;
	int b;
	int a;
	cor.getRgb(&r, &g, &b, &a);
	double kD = 0.9; //coeficiente de reflectividade difusa
	int rDif = (int) (kD * r * multVetores);
	int gDif = (int) (kD * g * multVetores);
	int bDif = (int) (kD * b * multVetores);
	//cout << "r" << rDif << endl;
	//cout << "g" << gDif << endl;
	//cout << "b" << bDif << endl;
	return QColor(rDif, gDif, bDif);
}

QColor Iluminador::calcularComponenteEspecular(Pixel p) {
	//calcular vetor raio refletido
	double xL = this->fonteDeLuz.getX() - p.getX();
	double yL = this->fonteDeLuz.getY() - p.getY();
	double zL = this->fonteDeLuz.getZ() - p.getZ();
	double comprimento = sqrt(xL * xL + yL * yL + zL * zL);
	Ponto vLuz("", xL / comprimento, yL / comprimento, zL / comprimento);
	Ponto normal = p.getNormal();
	double mult = 2
			* (vLuz.getX() * normal.getX() + vLuz.getY() * normal.getY()
					+ vLuz.getZ() * normal.getZ());
	double xR = mult * normal.getX() - vLuz.getX();
	double yR = mult * normal.getY() - vLuz.getY();
	double zR = mult * normal.getZ() - vLuz.getZ();
	Ponto vRef("", xR, yR, zR);
	//calcular vetor observador
	double xO = p.getX() - this->tamX;
	double yO = p.getY() - this->tamY;
	double zO = p.getZ() + 15;
	comprimento = sqrt(xO * xO + yO * yO + zO * zO);
	Ponto vObs("", xO / comprimento, yO / comprimento, zO / comprimento);
	double multVetores = vRef.getX() * vObs.getX() + vRef.getY() * vObs.getY()
			+ vRef.getZ() * vObs.getZ();
	double s = 10; //expoente especular
	multVetores = pow(multVetores, s);
	double kE = 0.5; //coeficiente de reflectividade especular
	int rEsp = (int) (kE * 255 * multVetores);
	int gEsp = (int) (kE * 255 * multVetores);
	int bEsp = (int) (kE * 255 * multVetores);
	//cout << "r" << rEsp << endl;
	//cout << "g" << gEsp << endl;
	//cout << "b" << bEsp << endl;
	if (rEsp > 255) {
		rEsp = 255;
	}
	if (gEsp > 255) {
		gEsp = 255;
	}
	if (bEsp > 255) {
		bEsp = 255;
	}
	return QColor(rEsp, gEsp, bEsp);
}

QColor Iluminador::calcularComponenteAmbiente(Pixel p) {
	QColor cor = p.getCor();
	int r;
	int g;
	int b;
	int a;
	cor.getRgb(&r, &g, &b, &a);
	double kA = 0.4;
	int rAmb = (int) (kA * r);
	int gAmb = (int) (kA * g);
	int bAmb = (int) (kA * b);
	return QColor(rAmb, gAmb, bAmb);
}

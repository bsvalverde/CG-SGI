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

QList<Pixel> Iluminador::iluminarCena(QList<Pixel> pixels) {
	//for (int x = 0; x < this->tamX; x++) {
	//for (int y = 0; y < this->tamY; y++) {
	//Pixel p = pixels[x][y];
	QList<Pixel> novosPixels;
	for (int i = 0; i < pixels.size(); i++) {
		Pixel p = pixels.at(i);
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
		novosPixels.append(p);
		//}
		//}
	}
	return novosPixels;
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
	cout << "r" << rDif << endl;
	//cout << "g" << gDif << endl;
	//cout << "b" << bDif << endl;
	return QColor(rDif, gDif, bDif);
}

QColor Iluminador::calcularComponenteEspecular(Pixel p) {
	//calcular vetor raio refletido
	double xR = this->fonteDeLuz.getX() - p.getX();
	double yR = this->fonteDeLuz.getY() - p.getY();
	double zR = this->fonteDeLuz.getZ() - p.getZ();
	double comprimento = sqrt(xR * xR + yR * yR + zR * zR);
	Ponto vRef("", xR / comprimento, yR / comprimento, zR / comprimento);
	Ponto normal = p.getNormal();
	double cosX = (vRef.getY() * normal.getY() + vRef.getZ() * normal.getZ()); //angulo entre vetor e a normal pelo eixo x
	double arcX = acos(cosX);
	double anguloX = arcX * 180 / M_PI;
	double cosZ = (vRef.getX() * normal.getX() + vRef.getY() * normal.getY()); // angulo entre vetor e a normal pelo eixo z
	double arcZ = acos(cosZ);
	double anguloZ = arcZ * 180 / M_PI;
	vRef.rotacionarPorX(Ponto("", 0, 0, 0), 2 * anguloX);
	vRef.rotacionarPorZ(Ponto("", 0, 0, 0), 2 * anguloZ);
	//calcular vetor observador
	double xO = p.getX() - this->tamX / 2;
	double yO = p.getY() - this->tamY / 2;
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
	cout << "r" << rEsp << endl;
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

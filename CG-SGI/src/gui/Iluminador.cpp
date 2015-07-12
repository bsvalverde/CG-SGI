#include "gui/Iluminador.h"

Iluminador::Iluminador(const unsigned int tamX, const unsigned int tamY) {
	this->tamX = tamX;
	this->tamY = tamY;
	this->fonteDeLuz = Ponto("", 0, 0, 0);
}

Iluminador::~Iluminador() {
}

void Iluminador::iluminarCena(Pixel pixels[2][2]) {
	for (int x = 0; x < this->tamX; x++) {
		for (int y = 0; y < this->tamY; y++) {
			Pixel p = pixels[x][y];
			QColor corDif = this->calcularComponenteDifusa(p);
			QColor corEsp = this->calcularComponenteEspecular(p);
			QColor corAmb = this->zN(p);
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
		}
	}
}

void Iluminador::atualizarFonteDeLuz(Ponto posicao, double intensidade) {
	this->fonteDeLuz = posicao;
}

QColor Iluminador::calcularComponenteDifusa(Pixel p) {
	Ponto normal = p.getNormal();
	Ponto vN("", this->fonteDeLuz.getX() - p.getX(),
			this->fonteDeLuz.getY() - p.getY(),
			this->fonteDeLuz.getZ() - p.getZ()); //vetor normalizado apontando para fonte de luz
	double multVetores = normal.getX() * vN.getX() + normal.getY() * vN.getY()
			+ normal.getZ() * vN.getZ();
	QColor cor = p.getCor();
	int r;
	int g;
	int b;
	int a;
	cor.getRgb(&r, &g, &b, &a);
	double kD = 0.85; //coeficiente de reflectividade difusa
	int rDif = (int) (kD * r * multVetores);
	int gDif = (int) (kD * g * multVetores);
	int bDif = (int) (kD * b * multVetores);
	return QColor(rDif, gDif, bDif);
}

QColor Iluminador::calcularComponenteEspecular(Pixel p) {
	Ponto vRef("", this->fonteDeLuz.getX() - p.getX(),
			this->fonteDeLuz.getY() - p.getY(),
			this->fonteDeLuz.getZ() - p.getZ()); //vetor entre pixel e fonte de luz
	Ponto normal = p.getNormal();
	double cos = (vRef.getX() * normal.getX() + vRef.getY() * normal.getY()
			+ vRef.getZ() * normal.getZ())
			/ sqrt(
					vRef.getX() * vRef.getX() + vRef.getY() * vRef.getY()
							+ vRef.getZ() * vRef.getZ())
			* sqrt(
					normal.getX() * normal.getX()
							+ normal.getY() * normal.getY()
							+ normal.getZ() * normal.getZ()); //angulo entre vetor e a normal
	double arc = acos(cos);
	double xO = this->fonteDeLuz.getX() - p.getX();
	double yO = this->fonteDeLuz.getY() - p.getY();
	double zO = this->fonteDeLuz.getZ() - p.getZ();
	double max = xO;
	if (yO > max)
		max = yO;
	if (zO > max)
		max = zO;
	Ponto vN("", xO / max, yO / max, zO / max); //vetor normalizado apontando para a fonte de luz

	Ponto vObs("", p.getX() - this->tamX / 2, p.getY() - this->tamY / 2,
			p.getZ() + 15); //vetor da direção do observador
	double multVetores = vRef.getX() * vObs.getX() + vRef.getY() * vObs.getY()
			+ vRef.getZ() * vObs.getZ();
	double s = 10; //expoente especular
	multVetores = pow(multVetores, s);
	double kE = 0.5; //coeficiente de reflectividade especular
	int rDif = (int) (kE * 255 * multVetores);
	int gDif = (int) (kE * 255 * multVetores);
	int bDif = (int) (kE * 255 * multVetores);
	return QColor(rDif, gDif, bDif);
}

QColor Iluminador::zN(Pixel p) {
	QColor cor = p.getCor();
	int r;
	int g;
	int b;
	int a;
	cor.getRgb(&r, &g, &b, &a);
	double kA = 0.015;
	int rAmb = (int) (kA * r);
	int gAmb = (int) (kA * g);
	int bAmb = (int) (kA * b);
	return QColor(rAmb, gAmb, bAmb);
}

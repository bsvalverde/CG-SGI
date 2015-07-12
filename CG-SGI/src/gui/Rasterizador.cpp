#include "gui/Rasterizador.h"

Rasterizador::Rasterizador(const unsigned int tamX, const unsigned int tamY) {
	this->tamX = tamX;
	this->tamY = tamY;
}

Rasterizador::~Rasterizador() {
}

QList<Pixel> Rasterizador::rasterizarObjeto(ObjetoGeometrico* const objeto) {
	QList<Poligono> triangulos = this->triangularObjeto(objeto);
	QList<Poligono> trapezios = this->paralelizarTriangulos(triangulos);

	QList<Pixel> pixels;
	for (Poligono p : trapezios) {
		pixels.append(this->pixelarTriangulo(p));
	}

	return pixels;
}

QList<Poligono> Rasterizador::triangularObjeto(ObjetoGeometrico* const objeto) {
	QList<Poligono> triangulos;
	QList<Ponto> pontos = objeto->getPontos();

	while (pontos.size() > 3) {
		int numPontos = pontos.size();
		for (int i = 0; i < numPontos; i++) {
			// Selecionar três pontos do polígono
			Ponto p1 = pontos[i];
			Ponto p2 = pontos[(i + 1) % numPontos];
			Ponto p3 = pontos[(i + 2) % numPontos];
			QList<Ponto> novosPontos = { p1, p2, p3 };

			bool trianguloInvalido = false;

			QList<Ponto> pontosRest = pontos;
			pontosRest.removeOne(p1);
			pontosRest.removeOne(p2);
			pontosRest.removeOne(p3);

			for (int j = 0; j < pontosRest.size(); j++) {
				if (this->poligonoContemPonto(novosPontos, pontosRest[j])) {
					trianguloInvalido = true;
					break;
				}
			}

			// Se algum dos outros pontos do polígono está no triângulo, vai pra próxima iteração
			if (trianguloInvalido)
				continue;

			// Verificar se o triângulo formado está dentro do polígono
			double x = (p1.getX() + p2.getX() + p3.getX()) / 3;
			double y = (p1.getY() + p2.getY() + p3.getY()) / 3;

			if (this->poligonoContemPonto(pontos, Ponto("", x, y, 0))) {
				// Criar o triângulo
				Poligono p("", novosPontos, objeto->getCor());
				triangulos.append(p);
				pontos.removeAt((i + 1) % numPontos);
				break;
			}
		}
	}

	Poligono p("", pontos, objeto->getCor());
	triangulos.append(p);
	return triangulos;
}

bool Rasterizador::poligonoContemPonto(const QList<Ponto>& pontos,
		const Ponto& p) {
	bool contem = false;
	int numPontos = pontos.size();

	for (int i = 0, j = numPontos - 1; i < numPontos; j = i++) {
		if (((pontos[i].getY() > p.getY()) != (pontos[j].getY() > p.getY()))
				&& (p.getX()
						< (pontos[j].getX() - pontos[i].getX())
								* (p.getY() - pontos[i].getY())
								/ (pontos[j].getY() - pontos[i].getY())
								+ pontos[i].getX()))
			contem = !contem;
	}

	return contem;
}

QList<Poligono> Rasterizador::paralelizarTriangulos(
		const QList<Poligono>& triangulos) {
	QList<Poligono> trapezios;

	for (Poligono p : triangulos) {
		QList<Ponto> pontos = p.getPontos();

		// Definir P1 com o maior Y
		Ponto p1 = pontos.at(0);

		for (int i = 1; i < pontos.size(); i++) {
			Ponto pt = pontos.at(i);
			if (p1.getY() < pt.getY())
				p1 = pt;
		}
		pontos.removeOne(p1);
		Ponto p2 = pontos.at(0);
		Ponto p3 = pontos.at(1);

		// Definir P2 com o menor Y
		if (p3.getY() < p2.getY()) {
			Ponto temp = p2;
			p2 = p3;
			p3 = temp;
		}

		//Normalizar
		// P1 P4
		// P2 P3
		if (p1.getY() == p3.getY()) { // Lado (P1, P3) paralelo ao eixo Y
			if (p3.getX() < p1.getX()) {
				Ponto temp = p1;
				p1 = p3;
				p3 = temp;
			}
			trapezios.append(Poligono("", { p1, p2, p2, p3 }, p.getCor()));
		} else if (p2.getY() == p3.getY()) { // Lado (P2, P3) paralelo ao eixo Y
			if (p3.getX() < p2.getX()) {
				Ponto temp = p2;
				p2 = p3;
				p3 = temp;
			}
			Poligono pol("", { p1, p2, p3, p1 }, p.getCor());
			trapezios.append(pol);
		} else { // Triângulo é dividido em dois
			Ponto p4 = this->calcularInterseccao(p3, Reta("", p1, p2));
			if (p4.getX() < p3.getX()) {
				Ponto temp = p4;
				p4 = p3;
				p3 = temp;
			}
			Poligono trapezio1("", { p1, p3, p4, p1 }, p.getCor());
			Poligono trapezio2("", { p3, p2, p2, p4 }, p.getCor());
			trapezios.append(trapezio1);
			trapezios.append(trapezio2);
		}
	}

	return trapezios;
}

Ponto Rasterizador::calcularInterseccao(Ponto p, Reta r) {
	double mX = r.coeficienteAngular();
	double mZ = r.coeficienteAngularZ();
	double y = p.getY();
	Ponto pr = r.getPontos().at(0);
	double x = pr.getX() + (y - pr.getY()) / mX;
	double z = pr.getZ() + (y - pr.getY()) / mZ;
	Ponto p4("", x, y, z);
	return p4;
}

QList<Pixel> Rasterizador::pixelarTriangulo(const Poligono& triangulo) {
	QList<Ponto> pontos = triangulo.getPontos();

	Ponto p1 = pontos.at(0);
	Ponto p2 = pontos.at(1);
	Ponto p3 = pontos.at(2);
	Ponto p4 = pontos.at(3);
	// Normalizar os pontos para as medidas da Viewport

	// Transladar para deixar os pontos entre 0 e 2
	p1.transladar(1, 1, 0);
	p2.transladar(1, 1, 0);
	p3.transladar(1, 1, 0);
	p4.transladar(1, 1, 0);

	// Escalonar para colocar nas medidas da Viewport
	double fatorX = (double) this->tamX / 2;
	double fatorY = (double) this->tamY / 2;

	p1.setX(p1.getX() * fatorX);
	p2.setX(p2.getX() * fatorX);
	p3.setX(p3.getX() * fatorX);
	p4.setX(p4.getX() * fatorX);
	p1.setY(p1.getY() * fatorY);
	p2.setY(p2.getY() * fatorY);
	p3.setY(p3.getY() * fatorY);
	p4.setY(p4.getY() * fatorY);

	// Criar pixels
	QList<Pixel> pixels;

	Reta esq("", p1, p2);
	Reta dir("", p3, p4);

	double mXEsq = esq.coeficienteAngular();
	double mXDir = dir.coeficienteAngular();

	int inicial = (int) p1.getY();
	int final = (int) p2.getY();

	double xEsq = p1.getX() + ((double) inicial - p1.getY()) / mXEsq;
	double xDir = p4.getX() + ((double) inicial - p4.getY()) / mXDir;

	double incXEsq = -1 / mXEsq;
	double incXDir = -1 / mXDir;

	//definir a normal
	Ponto vetor1("", p1.getX() - p2.getX(), p1.getY() - p2.getY(),
			p1.getZ() - p2.getZ());
	Ponto vetor2("", p3.getX() - p4.getX(), p3.getY() - p4.getY(),
			p3.getZ() - p4.getZ());

	double xNormal = vetor1.getY() * vetor2.getZ()
			- vetor1.getZ() * vetor2.getY();
	double yNormal = vetor1.getX() * vetor2.getZ()
			- vetor1.getZ() * vetor2.getX();
	double zNormal = vetor1.getX() * vetor2.getY()
			- vetor1.getY() * vetor2.getX();
	double max = xNormal;
	if (yNormal > max)
		max = yNormal;
	if (zNormal > max)
		max = zNormal;

	if (zNormal > 0) {
		xNormal *= -1;
		yNormal *= -1;
		zNormal *= -1;
	}

	Ponto normal("", xNormal/max, yNormal/max, zNormal/max);

	double mZVer = esq.coeficienteAngularZ();
	double incZVer = -1 / mZVer;
	double incZHor = -normal.getX() / normal.getZ();

	double zRef = p1.getZ() + ((double) inicial - p1.getY()) / mZVer;

	for (int y = inicial; y >= final; y--) {
		double zPix = zRef + ((double) ((int) xEsq) - xEsq) * incZHor;
		for (int x = (int) xEsq; x <= (int) xDir; x++) {
			pixels.append(
					Pixel(x, this->tamY - y, zPix, triangulo.getCor(),
							normal));
			zPix += incZHor;
		}
		xEsq += incXEsq;
		xDir += incXDir;
		zRef += incZVer;
	}

	return pixels;
}

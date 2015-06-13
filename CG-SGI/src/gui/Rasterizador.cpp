#include "gui/Rasterizador.h"
#include <iostream>

Rasterizador::Rasterizador(const unsigned int tamX, const unsigned int tamY) {
	this->tamX = tamX;
	this->tamY = tamY;
}

Rasterizador::~Rasterizador() {
}

QList<Pixel> Rasterizador::rasterizarObjeto(ObjetoGeometrico* const objeto) {
	this->triangulos.clear(); // TODO
	QList<Poligono> triangulos = this->triangularObjeto(objeto);
	this->adaptarTriangulos(triangulos);

	QList<Pixel> pixels;
	for(Poligono p : this->triangulos) {
		pixels.append(this->pixelarTriangulo(p));
	}

	return pixels;
}

QList<Poligono> Rasterizador::triangularObjeto(const ObjetoGeometrico* objeto) {
	QList<Poligono> triangulos;
	QList<Ponto> pontos = objeto->getPontos();

	while (pontos.size() > 3) {
		for (int i = 0; i < pontos.size(); i++) {
			QList<Ponto> novosPontos;
			//Seleciona três pontos do polígono
			Ponto p1 = pontos.at(i);
			Ponto p2 = pontos.at((i + 1) % pontos.size());
			Ponto p3 = pontos.at((i + 2) % pontos.size());
			novosPontos.append(p1);
			novosPontos.append(p2);
			novosPontos.append(p3);
			bool continua = true;
			int k = i + 3;
			//Verifica se algum dos demais pontos está dentro do triângulo
			for (int j = 0; j < pontos.size() - 3; j++) {
				if (this->estaDentro(pontos.at((k) % pontos.size()),
						novosPontos)) {
					//se há algum ponto dentro, esta triangularização não funciona
					continua = false;
					break;
				}
				k = (k + 1) % pontos.size();
			}
			if (continua) {
				//verifica se o triangulo formado está dentro do polígono
				double x = (p1.getX() + p2.getX() + p3.getX()) / 3;
				double y = (p1.getY() + p2.getY() + p3.getY()) / 3;
				if (this->estaDentro(Ponto("", x, y, 0), pontos)) {
					Poligono p("", novosPontos, objeto->getCor());
					triangulos.append(p);
					pontos.removeAt(i + 1);
				}
			}
		}
	}
	Poligono p("", pontos, objeto->getCor());
	triangulos.append(p);
	return triangulos;
}

bool Rasterizador::estaDentro(Ponto p, QList<Ponto> pontos) {
	int interseccoes = 0;
	double y = p.getY();
	for (int i = 0; i < pontos.size(); i++) {
		Ponto p1 = pontos.at(i);
		Ponto p2 = pontos.at((i + 1) % pontos.size());
		double y1 = p1.getY();
		double y2 = p2.getY();
		Reta r("", p1, p2);
		double m = r.coeficienteAngular();
		double xR = p1.getX() + (y - y1) / m;
		if (xR > p.getX()) {
			if ((y1 > y && y2 < y) || (y1 < y && y2 > y)) {
				interseccoes++;
			} else if (y2 == y) {
				Ponto p3 = pontos.at((i + 2) % pontos.size());
				double y3 = p3.getY();
				if ((y1 > y && y3 < y) || (y1 < y && y3 > y)) {
					interseccoes++;
				}
			}
		}
	}
	return ((interseccoes % 2) == 1);
}

void Rasterizador::adaptarTriangulos(const QList<Poligono> triangulos) {
	for (int i = 0; i < triangulos.size(); i++) {
		Poligono triangulo = triangulos.at(i);
		QList<Ponto> pontos = triangulo.getPontos();
		//calcula o ponto mais alto
		Ponto p1 = pontos.at(0);
		int posicao = 0;
		for (int j = 1; j < pontos.size(); j++) {
			Ponto p = pontos.at(j);
			if (p1.getY() < p.getY()) {
				p1 = p;
				posicao = j;
			}
		}
		int pos = (posicao + 1) % pontos.size();
		int ant = (posicao - 1 + pontos.size()) % pontos.size();
		Ponto p2 = pontos.at(pos);
		Ponto p3 = pontos.at(ant);
		double y1 = p1.getY();
		double y2 = p2.getY();
		double y3 = p3.getY();
		if (y1 == y2 || y1 == y3 || y2 == y3) {
			this->triangulos.append(triangulo);
		} else if (y2 < y3) {
			Ponto temp = p2;
			p2 = p3;
			p3 = temp;
		}
		Ponto p4 = this->calcularInterseccao(p2, Reta("", p1, p3));
		QList<Ponto> novosPontos1;
		novosPontos1.append(p1);
		novosPontos1.append(p2);
		novosPontos1.append(p4);
		Poligono t1("", novosPontos1, triangulo.getCor());
		this->triangulos.append(t1);
		QList<Ponto> novosPontos2;
		novosPontos2.append(p2);
		novosPontos2.append(p3);
		novosPontos2.append(p4);
		Poligono t2("", novosPontos2, triangulo.getCor());
		this->triangulos.append(t2);
	}
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

	// Padronizar as posições dos pontos
	// P1  P4
	// P2  P3

	// Definir P1, P2, P3 do maior para o menor Y
	Ponto p1 = pontos.at(0);

	for (int i = 1; i < pontos.size(); i++) {
		Ponto p = pontos.at(i);
		if (p1.getY() < p.getY())
			p1 = p;
	}
	pontos.removeOne(p1);
	Ponto p2 = pontos.at(0);
	Ponto p3 = pontos.at(1);
	Ponto p4;

	if(p2.getY() < p3.getY()) {
		Ponto temp = p2;
		p2 = p3;
		p3 = temp;
	}

	if(p1.getY() == p2.getY()) { // Lado Paralelo = (P1, P2)
		if(p1.getX() > p2.getX()) {
			Ponto temp = p1;
			p1 = p2;
			p2 = temp;
		}

		p4 = p2;
		p2 = p3;
	} else { // Lado Paralelo = (P2, P3)
		if(p2.getX() > p3.getX()) {
			Ponto temp = p2;
			p2 = p3;
			p3 = temp;
		}

		p4 = p1;
	}

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

	for (int y = inicial; y >= final; y--) {

		int xEsq = p1.getX() + (y - p1.getY()) / mXEsq;
		int xDir = p4.getX() + (y - p4.getY()) / mXDir;

		for (int x = xEsq; x <= xDir; x++) {
			pixels.append(Pixel(x, (1 - y / (double) this->tamY) * this->tamY, 0/*z a determinar*/, triangulo.getCor()));
		}
	}

	return pixels;
}

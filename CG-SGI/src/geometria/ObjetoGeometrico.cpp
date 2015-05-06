#include "geometria/ObjetoGeometrico.h"
#include "geometria/Ponto.h"
#include "geometria/Reta.h"

ObjetoGeometrico::ObjetoGeometrico(const ObjetoGeometrico& objeto) {
	this->nome = objeto.nome;
	this->tipo = objeto.tipo;
	this->cor = objeto.cor;
}

ObjetoGeometrico::ObjetoGeometrico() {
	this->nome = "";
	this->tipo = Tipo::POLIGONO;
	this->cor = QColor(0, 0, 0);
}

ObjetoGeometrico::ObjetoGeometrico(const String& nome, const Tipo tipo,
		const QColor& cor) {
	this->nome = nome;
	this->tipo = tipo;
	this->cor = cor;
}

ObjetoGeometrico::~ObjetoGeometrico() {
}

ObjetoGeometrico& ObjetoGeometrico::operator=(const ObjetoGeometrico& objeto) {
	this->nome = objeto.nome;
	this->tipo = objeto.tipo;
	this->cor = objeto.cor;
	return *this;
}

const String ObjetoGeometrico::toString() const {
	return this->nome;
}

const String& ObjetoGeometrico::getNome() const {
	return this->nome;
}

const QColor& ObjetoGeometrico::getCor() const {
	return this->cor;
}

ObjetoGeometrico::Tipo ObjetoGeometrico::getTipo() const {
	return this->tipo;
}

const String ObjetoGeometrico::getTipoString() const {
	switch (this->tipo) {
	case Tipo::CURVA_BEZIER:
		return "Bezier";
	case Tipo::CURVA_BSPLINE:
		return "B-Spline";
	case Tipo::PONTO:
		return "Ponto";
	case Tipo::RETA:
		return "Reta";
	case Tipo::WINDOW:
		return "Window";
	default:
		return "Polígono";
	}
}

const Ponto ObjetoGeometrico::getCentroGeometrico() const {
	QList<Ponto> pontos = this->getPontos();
	int numPontos = pontos.size();
	double x = 0;
	double y = 0;
	double z = 0;

	for (Ponto p : pontos) {
		x += p.getX();
		y += p.getY();
		z += p.getZ();
	}

	x = x / numPontos;
	y = y / numPontos;
	z = z / numPontos;

	return Ponto("CentroG-" + this->getNome(), x, y, z);
}

void ObjetoGeometrico::setCor(const QColor& cor) {
	this->cor = cor;
}

void ObjetoGeometrico::escalonar(const double sX, const double sY,
		const double sZ) {
	Ponto p = this->getCentroGeometrico();
	double xC = p.getX();
	double yC = p.getY();
	double zC = p.getZ();
	double matriz[4][4] = { { sX, 0, 0, 0 }, { 0, sY, 0, 0 }, { 0, 0, sZ, 0 }, {
			-xC * sX + xC, -yC * sY + yC, -zC * sZ + zC, 1 } };
	this->aplicarTransformacao(matriz);
}

void ObjetoGeometrico::transladar(const double sX, const double sY,
		const double sZ) {
	double matriz[4][4] = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, {
			sX, sY, sZ, 1 } };
	this->aplicarTransformacao(matriz);
}

void ObjetoGeometrico::rotacionarPorX(const Ponto& ponto, const double angulo) {
	double y = ponto.getY();
	double z = ponto.getZ();
	double angRad = angulo * M_PI / 180;
	double matriz[4][4] = { { 1, 0, 0, 0 },
							{ 0, cos(angRad), -sin(angRad), 0 },
							{ 0, sin(angRad), cos(angRad), 0 },
							{ 0, y - y * cos(angRad) - z * sin(angRad),
								z + y * sin(angRad)	- z * cos(angRad), 1 } };
	this->aplicarTransformacao(matriz);
}

void ObjetoGeometrico::rotacionarPorY(const Ponto& ponto, const double angulo) {
	double x = ponto.getX();
	double z = ponto.getZ();
	double angRad = angulo * M_PI / 180;
	double matriz[4][4] = { { cos(angRad), 0, sin(angRad), 0 },
							{ 0, 1, 0, 0 },
							{ -sin(angRad), 0, cos(angRad), 0 },
							{ x - x * cos(angRad) + z * sin(angRad),
								0, z - x * sin(angRad) - z * cos(angRad), 1 } };
	this->aplicarTransformacao(matriz);
}

void ObjetoGeometrico::rotacionarPorZ(const Ponto& ponto, const double angulo) {
	double x = ponto.getX();
	double y = ponto.getY();
	double angRad = angulo * M_PI / 180;
	double matriz[4][4] = { { cos(angRad), -sin(angRad), 0, 0 },
							{ sin(angRad), cos(angRad), 0, 0 },
							{ 0, 0, 1, 0 },
							{ x - x * cos(angRad) - y * sin(angRad),
								y + x * sin(angRad) - y * cos(angRad), 0, 1 } };
	this->aplicarTransformacao(matriz);
}

void ObjetoGeometrico::rotacionarPorEixo(const double angulo, const Reta& eixo) {
	QList<Ponto> pontos = eixo.getPontos();
	Ponto p1 = pontos.at(0);
	Ponto p2 = pontos.at(1);

	//definição das arestas
	double x = p2.getX() - p1.getX();
	double y = p2.getY() - p1.getY();
	double z = p2.getZ() - p1.getZ();

	//angulo com eixo X
	double tan = y / x;
	double anguloX = atan(tan);

	if (x < 0 && y < 0) { // 3º quadrante
		anguloX += M_PI;
	} else if (x < 0 && y > 0) { // 4º quadrante
		anguloX += -M_PI;
	}

	//angulo com eixo Z
	tan = y / z;
	double anguloZ = atan(tan);

	if (z < 0 && y < 0) { // 3º quadrante
		anguloX += M_PI;
	} else if (z < 0 && y > 0) { // 4º quadrante
		anguloX += -M_PI;
	}

	//passo a passo
	x = p1.getX();
	y = p1.getY();
	z = p1.getZ();

	this->transladar(-x, -y, -z);
	this->rotacionarPorX(p1, -anguloX);
	this->rotacionarPorZ(p1, -anguloZ);
	this->rotacionarPorY(p1, angulo);
	this->rotacionarPorZ(p1, anguloZ);
	this->rotacionarPorX(p1, anguloX);
	this->transladar(x, y, z);
}

void ObjetoGeometrico::aplicarTransformacao(const double matriz[4][4]) {
	QList<Ponto*> pontos = this->getPontosObjeto();

	for (int i = 0; i < pontos.size(); i++) {
		Ponto* p = pontos.at(i);
		double coordenadas[4] = { 0, 0, 0, 0 };

		for (int j = 0; j < 4; j++) {
			coordenadas[j] = p->getX() * matriz[0][j] + p->getY() * matriz[1][j]
					+ p->getZ() * matriz[2][j] + 1 * matriz[3][j]; // Coordenada Homogênea
		}

		p->setX(coordenadas[0]);
		p->setY(coordenadas[1]);
		p->setZ(coordenadas[2]);
	}
}

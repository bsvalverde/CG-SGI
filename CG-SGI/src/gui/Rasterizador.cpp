#include "gui/Rasterizador.h"

Rasterizador::Rasterizador(const unsigned int tamX, const unsigned int tamY) {
	this->tamX = tamX;
	this->tamY = tamY;
}

Rasterizador::~Rasterizador() {
}

QList<Poligono> Rasterizador::rasterizarObjeto(ObjetoGeometrico* const objeto) {
	this->triangulos.clear(); // TODO
	QList<Poligono> triangulos = this->triangularObjeto(objeto);
	this->adaptarTriangulos(triangulos);
	return this->triangulos;
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
					Poligono p("", novosPontos);
					triangulos.append(p);
					pontos.removeAt(i + 1);
				}
			}
		}
	}
	Poligono p("", pontos);
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
		Poligono t1("", novosPontos1);
		this->triangulos.append(t1);
		QList<Ponto> novosPontos2;
		novosPontos2.append(p2);
		novosPontos2.append(p3);
		novosPontos2.append(p4);
		Poligono t2("", novosPontos2);
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

QList<Pixel> Rasterizador::pixelarTriangulo(const Poligono triangulo) {
	QList<Ponto> pontos = triangulo.getPontos();
	Ponto p1 = pontos.at(0);
	//padroniza as posições dos pontos
	for (int i = 1; i < pontos.size(); i++) {
		Ponto p = pontos.at(i);
		if (p1.getY() < p.getY()) {
			p1 = p;
			pontos.removeAt(i);
		}
	}
	Ponto p2 = pontos.at(0);
	Ponto p3 = pontos.at(1);
	if (p2.getY() > p3.getY()) {
		Ponto temp = p2;
		p2 = p3;
		p3 = temp;
	}
	Ponto p4;
	if (p3.getY() == p1.getY()) {
		p4 = p3;
		p3 = p2;
		if (p4.getX() < p1.getX()) {
			Ponto temp = p1;
			p1 = p4;
			p4 = temp;
		}
	} else {
		p4 = p1;
		if (p3.getX() < p2.getX()) {
			Ponto temp = p2;
			p2 = p3;
			p3 = temp;
		}
	}

	//normaliza pontos para a viewport
	p1.transladar(1, 1, 0);
	p2.transladar(1, 1, 0);
	p3.transladar(1, 1, 0);
	p4.transladar(1, 1, 0);
	p1.escalonar(this->tamX, this->tamY, 0);
	p2.escalonar(this->tamX, this->tamY, 0);
	p3.escalonar(this->tamX, this->tamY, 0);
	p4.escalonar(this->tamX, this->tamY, 0);

	//cria pixels
	QList<Pixel> pixels;
	Reta esq("", p1, p2);
	Reta dir("", p3, p4);
	double mXEsq = esq.coeficienteAngular();
	//double mZEsq = esq.coeficienteAngularZ();
	double mXDir = dir.coeficienteAngular();
	//double mZDir = dir.coeficienteAngularZ();
	int inicial = this->tamY - (int) p1.getY();
	if (inicial == 0) {
		inicial++;
	}
	int final = (int) (this->tamY - p2.getY());
	if (final == 0) {
		final++;
	}
	for (int i = inicial; i <= final; i++) {
		double xEsq = p1.getX() + (i - p1.getY()) / mXEsq;
		double xDir = p4.getX() + (i - p4.getY()) / mXDir;
		for (int j = (int) xEsq; j <= (int) xDir; j++) {
			pixels.append(Pixel(j, i, 0/*z a determinar*/, triangulo.getCor()));
		}
	}
	return pixels;
}

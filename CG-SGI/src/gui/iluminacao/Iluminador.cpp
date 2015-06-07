#include "gui/iluminacao/Iluminador.h"

Iluminador::Iluminador(Viewport viewport) {
	this->viewport = viewport;
}

Iluminador::~Iluminador() {

}

void Iluminador::iluminarCena(const QList<ObjetoGeometrico*>& objetos) {
	this->transformarObjetos(objetos);
}

void Iluminador::transformarObjetos(const QList<ObjetoGeometrico*>& objetos) {
	for (int i = 0; i < objetos.size(); i++) {
		ObjetoGeometrico* objeto = objetos.at(i)->clonar();
		QList<Ponto> pontos = objeto->getPontos();
		while (pontos.size() > 2) {
			pontos = this->transformarNormal(pontos);
		}
	}
}

QList<Ponto> Iluminador::transformarNormal(QList<Ponto> pontos) {
	//calcula o ponto mais alto
	Ponto p1 = pontos.at(0);
	int posicao1 = 0;
	for (int i = 1; i < pontos.size(); i++) {
		Ponto p = pontos.at(i);
		if (p1.getY() < p.getY()) {
			p1 = p;
			posicao1 = i;
		}
	}
	//verifica se há algum ponto na mesma altura
	int pos = (posicao1 + 1) % pontos.size();
	int ant = (posicao1 - 1 + pontos.size()) % pontos.size();
	Ponto p2;
	int posicao2;
	bool igual;
	if (pontos.at(ant).getY() != p1.getY()) {
		if (pontos.at(pos).getY() != p1.getY()) {
			p2 = p1;
			posicao2 = posicao1;
			igual = true;
		} else {
			p2 = pontos.at(pos);
			posicao2 = pos;
			pos = (pos + 1) % pontos.size();
			igual = false;
		}
	} else {
		p2 = p1;
		posicao2 = posicao1;
		p1 = pontos.at(ant);
		posicao1 = ant;
		ant = (ant - 1 + pontos.size()) % pontos.size();
		igual = false;
	}
	//verifica qual dos vizinhos é mais alto
	Ponto p3;
	Ponto p4;
	if (ant == pos) {
		p3 = pontos.at(ant);
		p4 = p3;
	} else if (pontos.at(ant).getY() > pontos.at(pos).getY()) {
		p4 = pontos.at(ant);
		p3 = this->calcularInterseccao(p1, pontos.at(pos), p4);
	} else {
		p3 = pontos.at(pos);
		p4 = this->calcularInterseccao(p1, pontos.at(ant), p3);
	}

	//atualiza lista de pontos
	pontos.removeAt(posicao1);
	pontos.insert(posicao1, p4);
	if (!igual)
		pontos.removeAt(posicao2);

	//cria trapézio
	QList<Ponto> novosPontos;
	novosPontos.append(p1);
	novosPontos.append(p2);
	novosPontos.append(p3);
	novosPontos.append(p4);
	this->trapezios.append(Poligono(""));

	return pontos;
}

Ponto Iluminador::calcularInterseccao(Ponto p1, Ponto p2, Ponto p3) {
	double mX = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
	double mZ = (p1.getY() - p2.getY()) / (p1.getZ() - p2.getZ());
	double y = p3.getY();
	double x = p1.getX() + (y - p1.getY()) / mX;
	double z = p1.getZ() + (y - p1.getY()) / mZ;
	Ponto p4 = ("", x, y, z);
	return p4;
}

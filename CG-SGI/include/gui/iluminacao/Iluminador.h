#ifndef ILUMINADOR_H_
#define ILUMINADOR_H_

#include <QtCore/qlist.h>

#include "gui/Viewport.h"
#include "geometria/ObjetoGeometrico.h"
#include "geometria/Poligono.h"

class Iluminador {
public:
	/**
	 * Construtor.
	 */
	Iluminador(Viewport viewport);

	/**
	 * Destrutor.
	 */
	~Iluminador();

	/**
	 * Calcula iluminação e desenha na viewport.
	 * @param objetos objetos do DisplayFile já clipados.
	 */
	void iluminarCena(const QList<ObjetoGeometrico*>& objetos);

private:
	/**
	 * Transforma os objetos clipados em trapézios.
	 * @param objetos objetos a serem transformados.
	 */
	void transformarObjetos(const QList<ObjetoGeometrico*>& objetos);

	/**
	 * Cada um dos seguintes métodos é chamado conforme o tipo do objeto
	 */
	QList<Ponto> transformarNormal(QList<Ponto> pontos);
	void transformarObjeto3D(Objeto3D* obj);

	/*
	 *Calcula a projeção de p3 na reta p1, p2 por y
	 */
	Ponto calcularInterseccao(Ponto p1, Ponto p2, Ponto p3);

	Viewport viewport;
	QList<Poligono> trapezios;
};

#endif /* ILUMINADOR_H_ */

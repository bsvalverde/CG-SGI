#ifndef RASTERIZADOR_H_
#define RASTERIZADOR_H_

#include <QtCore/qlist.h>

#include "gui/Viewport.h"
#include "geometria/ObjetoGeometrico.h"
#include "geometria/Poligono.h"

class Rasterizador {
public:
	/**
	 * Construtor.
	 */
	Rasterizador(Viewport viewport);

	/**
	 * Destrutor.
	 */
	~Rasterizador();

	/**
	 * Calcula iluminação e desenha na viewport.
	 * @param objetos objetos do DisplayFile já clipados.
	 */
	void iluminarCena(const QList<ObjetoGeometrico*>& objetos);

private:
	/**
	 * Divide o objeto clipado em triângulos.
	 * @param objeto objeto a ser transformado.
	 */
	QList<Poligono> triangularObjeto(const ObjetoGeometrico* objeto);

	/**
	 * Verifica se o ponto p está dentro do polígono formado por pontos
	 * @param p ponto a verificar
	 * @param pontos pontos que formam o polígono
	 */
	bool estaDentro(Ponto p, QList<Ponto> pontos);

	/**
	 * Divide os triângulos em triângulos que tenham bordas com y constante.
	 * @param triangulos triângulos a serem transformados.
	 */
	void adaptarTriangulos(const QList<Poligono> triangulos);

	/*
	 *Calcula a projeção de p em y na reta r
	 *@param p ponto a ser projetado
	 *@param r reta onde o ponto deve estar
	 */
	Ponto calcularInterseccao(Ponto p, Reta r);

	Viewport viewport;
	QList<Poligono> triangulos;
};

#endif /* RASTERIZADOR_H_ */

#ifndef RASTERIZADOR_H_
#define RASTERIZADOR_H_

#include <QtCore/qlist.h>

#include "geometria/ObjetoGeometrico.h"
#include "geometria/Poligono.h"
#include "geometria/Reta.h"
#include "gui/Pixel.h"

class Rasterizador {

public:
	/**
	 * Construtor.
	 * @param tamX largura da viewport.
	 * @param tamY altura da viewport.
	 */
	Rasterizador(const unsigned int tamX, const unsigned int tamY);

	/**
	 * Destrutor.
	 */
	~Rasterizador();

	/**
	 * Rasterizar um objeto.
	 * @param objeto objeto a ser rasterizado.
	 * @return TODO
	 */
	QList<Poligono> rasterizarObjeto(ObjetoGeometrico* const objeto);

	QList<Pixel> pixelarTriangulo(const Poligono triangulo);

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

	unsigned int tamX;
	unsigned int tamY;
	QList<Poligono> triangulos;
};

#endif /* RASTERIZADOR_H_ */

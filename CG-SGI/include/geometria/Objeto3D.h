#ifndef OBJETO3D_H_
#define OBJETO3D_H_

#include <QtCore/qmap.h>

#include "geometria/Ponto.h"
#include "geometria/Faceta.h"

/*
 * Objeto tridimensional.
 */
class Objeto3D : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Objeto3D();

	/**
	 * Construtor.
	 * @param objeto3d objeto a ser copiado.
	 */
	Objeto3D(const Objeto3D& objeto3d);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param pontos pontos do objeto.
	 * @param arestas arestas do objeto.
	 */
	Objeto3D(const String& nome, const QList<Ponto*>& pontos,
			const QList<Faceta>& facetas);

	/**
	 * Destrutor.
	 */
	virtual ~Objeto3D();

	/**
	 * Operador de atribuição.
	 * @param objeto3D objeto a ser copiado.
	 * @return objeto3D copiado.
	 */
	Objeto3D& operator=(const Objeto3D& objeto3d);

	/**
	 * Clonar o objeto.
	 * @return cópia do objeto geométrico.
	 */
	ObjetoGeometrico* clonar() const;

	/**
	 * Obter os pontos do objeto.
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto> getPontos() const;

	/**
	 * Obter os pontos do objeto.
	 * @return lista de pontos.
	 */
	QList<Ponto*> getPontosObjeto();

	/**
	 * Obter as arestas do objeto.
	 * @return lista com a cópia das arestas.
	 */
	QList<Faceta> getFacetas() const;

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	const String toString() const;

private:
	QList<Ponto*> pontos;
	QList<Faceta> facetas;

};

#endif /* OBJETO3D_H_ */

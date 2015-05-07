#ifndef OBJETO3D_H_
#define OBJETO3D_H_

#include "geometria/Ponto.h"
#include "geometria/Reta.h"
#include "geometria/Poligono.h"

/*
 * Objeto3D
 */
class Objeto3D: public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Objeto3D();

	/**
	 * Construtor.
	 * @param objeto3D objeto a ser copiado.
	 */
	Objeto3D(const Objeto3D& objeto3d);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param pontos pontos do objeto3d.
	 * @param arestas arestas do objeto3d.
	 * @param faces faces do objeto3d.
	 * @param cor cor do objeto3D.
	 */
	Objeto3D(const String& nome, const QList<Ponto>& pontos,
			const QList<Reta>& arestas, const QList<Poligono>& faces,
			const QColor& cor = QColor(0, 0, 0));

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

	void setPontos(const QList<Ponto>& pontos);

	/**
	 * Obter as arestas do objeto.
	 * @return lista com a cópia das arestas.
	 */
	QList<Reta> getArestas() const;

	/**
	 * Obter as arestas do objeto.
	 * @return lista de arestas.
	 */
	QList<Reta*> getArestasObjeto();

	void setArestas(const QList<Reta>& arestas);

	/**
	 * Obter as faces do objeto.
	 * @return lista com a cópia das faces.
	 */
	QList<Poligono> getFaces() const;

	/**
	 * Obter as faces do objeto.
	 * @return lista de faces.
	 */
	QList<Poligono*> getFacesObjeto();

	void setFaces(const QList<Poligono>& faces);

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	const String toString() const;

private:
	QList<Ponto> pontos;
	QList<Reta> arestas;
	QList<Poligono> faces;

};

#endif /* OBJETO3D_H_ */

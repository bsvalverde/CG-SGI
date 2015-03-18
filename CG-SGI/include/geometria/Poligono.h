#ifndef POLIGONO_H_
#define POLIGONO_H_

#include "geometria/Ponto.h"

class Poligono : public ObjetoGeometrico {

public:
	Poligono(const String& nome, const QList<Ponto> pontos);
	virtual ~Poligono();
	QList<Ponto> getPontos();
	const String toString() const;

private:
	QList<Ponto> pontos;

};

#endif

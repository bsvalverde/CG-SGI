#ifndef PONTO_H_
#define PONTO_H_

#include "geometria/ObjetoGeometrico.h"

class Ponto : public ObjetoGeometrico {

public:
	Ponto();
	Ponto(const Ponto& ponto);
	Ponto(const String& nome, const double x, const double y, const double z);
	virtual ~Ponto();
	void operator=(const Ponto& ponto);
	double getX() const;
	double getY() const;
	double getZ() const;
	QList<Ponto> getPontos();
	const String toString() const;

protected:
	double coord_x;
	double coord_y;
	double coord_z;

};

#endif

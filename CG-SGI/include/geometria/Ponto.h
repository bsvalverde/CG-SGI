#ifndef PONTO_H_
#define PONTO_H_

#include "geometria/ObjetoGeometrico.h"
#include <sstream>
#include <QtCore/qstring.h>

typedef std::string String;

class Ponto : public ObjetoGeometrico {

public:
	Ponto();
	Ponto(const Ponto& ponto);
	Ponto(const String& nome, const int x, const int y, const int z);
	virtual ~Ponto();
	void operator=(const Ponto& ponto);
	int getX() const;
	int getY() const;
	int getZ() const;
	QList<Ponto> getPontos();
	const String toString() const;

protected:
	int coord_x;
	int coord_y;
	int coord_z;

};

#endif

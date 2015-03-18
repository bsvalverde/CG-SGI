#ifndef RETA_H_
#define RETA_H_

#include "geometria/Ponto.h"

class Reta : public ObjetoGeometrico {

public:
	Reta(const String& nome, const Ponto& inicial, const Ponto& final);
	virtual ~Reta();
	QList<Ponto> getPontos();
	const String toString() const;

protected:
	Ponto v_inicial;
	Ponto v_final;

};

#endif

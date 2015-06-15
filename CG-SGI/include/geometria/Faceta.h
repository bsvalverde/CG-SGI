#ifndef FACETA_H_
#define FACETA_H_

#include "geometria/Ponto.h"

class Faceta : public ObjetoGeometrico {

public:
	Faceta(const Faceta& faceta);
	Faceta(const QList<Ponto*>& pontos, const QColor& cor = QColor(0, 0, 0));
	virtual ~Faceta();
	ObjetoGeometrico& operator=(const ObjetoGeometrico& objeto);
	ObjetoGeometrico* clonar() const;
	QList<Ponto> getPontos() const;
	QList<Ponto*> getPontosObjeto();

private:
	QList<Ponto*> pontos;

};

#endif /* FACETA_H_ */

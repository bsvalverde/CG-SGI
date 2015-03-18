#ifndef WINDOW_H_
#define WINDOW_H_

#include "geometria/Ponto.h"

class Window : ObjetoGeometrico {

public:
	Window();
	Window(Ponto pInfEsq, Ponto pSupDir);
	virtual ~Window();
	void escalonar(double f);
	void transladar(double f);
	QList<Ponto> getPontos() const;
	const String toString() const;

private:
	Ponto *pontoInferiorEsquerdo;
	Ponto *pontoSuperiorDireito;

};

#endif /* WINDOW_H_ */

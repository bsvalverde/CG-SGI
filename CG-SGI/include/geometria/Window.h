#ifndef WINDOW_H_
#define WINDOW_H_

#include "geometria/ObjetoGeometrico.h"
#include "geometria/Ponto.h"

class Window : ObjetoGeometrico {

public:
	Window(Ponto pInfEsq, Ponto pSupDir);
	virtual ~Window();
	void escalonar(double f);
	void transladar(double f);
	QList<Ponto> getPontos() const;

private:
	Ponto pontoInferiorEsquerdo;
	Ponto pontoSuperiorDireito;

};

#endif /* WINDOW_H_ */

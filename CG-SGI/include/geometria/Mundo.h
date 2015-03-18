#ifndef MUNDO_H_
#define MUNDO_H_

#include "geometria/DisplayFile.h"
#include "geometria/Window.h"

class Mundo {

public:
	Mundo();
	virtual ~Mundo();
	void adicionarObjeto(const ObjetoGeometrico objeto);
	Window getWindow() const;
	QList<ObjetoGeometrico> getObjetos() const;

private:
	DisplayFile displayFile;
	Window window;

};

#endif /* MUNDO_H_ */

#ifndef SGIAPP_H_
#define SGIAPP_H_

#include <qt5/QtWidgets/qapplication.h>
#include <iostream>

#include "controle/ControladorUI.h"

/**
 * Sistema Gr�fico Interativo.
 */
class SGIApp : public QApplication {

public:
	/**
	 * Construtor.
	 * @param argc n�mero de argumentos.
	 * @param argv vetor de argumentos.
	 */
	SGIApp(int argc, char *argv[]);

	/**
	 * Destrutor.
	 */
	virtual ~SGIApp();

	/**
	 * Executar a aplica��o.
	 * @return inteiro indicando o retorno da execu��o.
	 */
	static int exec();

	void test();

};

#endif /* SGIAPP_H_ */

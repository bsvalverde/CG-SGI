#ifndef SGIAPP_H_
#define SGIAPP_H_

#include <qt5/QtWidgets/qapplication.h>

/**
 * Sistema Gráfico Interativo.
 */
class SGIApp : public QApplication {

public:
	/**
	 * Construtor.
	 * @param argc número de argumentos.
	 * @param argv vetor de argumentos.
	 */
	SGIApp(int argc, char *argv[]);

	/**
	 * Destrutor.
	 */
	virtual ~SGIApp();

	/**
	 * Executar a aplicação.
	 * @return inteiro indicando o retorno da execução.
	 */
	static int exec();

};

#endif /* SGIAPP_H_ */

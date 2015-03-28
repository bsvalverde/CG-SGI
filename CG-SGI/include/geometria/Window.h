#ifndef WINDOW_H_
#define WINDOW_H_

#include "geometria/DisplayFile.h"
#include "geometria/Ponto.h"

/**
 * Janela de visualização do mundo
 */
class Window : public ObjetoGeometrico {

public:
	/**
	 * Construtor.
	 */
	Window();

	/**
	 * Construtor.
	 * @param window objeto a ser copiado.
	 */
	Window(const Window& window);

	/**
	 * Construtor.
	 * @param pInfEsq ponto inferior esquerdo.
	 * @param pSupDir ponto superior direito.
	 */
	Window(const Ponto& pInfEsq, const Ponto& pSupDir);

	/**
	 * Destrutor.
	 */
	virtual ~Window();

	/**
	 * Operador de atribuição.
	 * @param window objeto a ser copiado.
	 * @return window copiada.
	 */
	Window& operator=(const Window& window);

	/**
	 * Obter os pontos do objeto.
	 * @return lista com a cópia dos pontos.
	 */
	QList<Ponto> getPontos() const;

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	const String toString() const;

	/**
	 * Obter o centro geométrico do objeto.
	 * @return o ponto correspondento ao centro.
	 */
	const Ponto getCentroGeometrico() const;

	double getAltura() const;
	double getLargura() const;

	void atualizarDisplayFile(const DisplayFile& displayFile);
	void atualizarObjeto(ObjetoGeometrico* obj);

	void removerObjeto(const String& nome);
	QList<ObjetoGeometrico*> getObjetos() const;

	void transladar(const double sX, const double sY, const double sZ);

protected:
	/**
	 * Obter os pontos do objeto.
	 * @return lista de pontos.
	 */
	QList<Ponto*> getPontosObjeto();
	double anguloViewUpVectorEixoY();
	double tamViewUpVector() const;

	Ponto centro;
	Ponto viewUpVector;
	DisplayFile displayFileNormalizado;

};

#endif /* WINDOW_H_ */

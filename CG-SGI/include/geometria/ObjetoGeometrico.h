#ifndef OBJETOGEOMETRICO_H_
#define OBJETOGEOMETRICO_H_

#include <QtCore/qlist.h>
#include <QtGui/qcolor.h>

#include <cmath>
#include <math.h>
#include <string>

typedef std::string String;

class Ponto;
class Reta;

/**
 * Objeto Geométrico.
 */
class ObjetoGeometrico {

public:
	/**
	 * Tipos de objetos geométricos
	 */
	enum Tipo {
		CURVA_BSPLINE,
		CURVA_BEZIER,
		SUPERFICIE_BSPLINE,
		SUPERFICIE_BEZIER,
		POLIGONO,
		PONTO,
		RETA,
		WINDOW,
		OBJETO3D,
		FACETA
	};

	/**
	 * Construtor.
	 */
	ObjetoGeometrico();

	/**
	 * Construtor.
	 * @param objeto objeto a ser copiado.
	 */
	ObjetoGeometrico(const ObjetoGeometrico& objeto);

	/**
	 * Construtor.
	 * @param nome nome do objeto.
	 * @param tipo tipo do objeto.
	 * @param cor cor do objeto.
	 */
	ObjetoGeometrico(const String& nome, const Tipo tipo, const QColor& cor =
			QColor(0, 0, 0));

	/**
	 * Destrutor.
	 */
	virtual ~ObjetoGeometrico();

	/**
	 * Operador de atribuição.
	 * @param objeto objeto a ser copiado.
	 * @return objeto geométrico copiado.
	 */
	ObjetoGeometrico& operator=(const ObjetoGeometrico& objeto);

	/**
	 * Clonar o objeto.
	 * @return cópia do objeto geométrico.
	 */
	virtual ObjetoGeometrico* clonar() const = 0;

	/**
	 * Obter os pontos do objeto.
	 * @return lista com a cópia dos pontos.
	 */
	virtual QList<Ponto> getPontos() const = 0;

	/**
	 * Obter os pontos do objeto.
	 * @return lista de pontos.
	 */
	virtual QList<Ponto*> getPontosObjeto() = 0;

	/**
	 * Converter o objeto em string.
	 * @return string representando o objeto.
	 */
	virtual const String toString() const;

	/**
	 * Obter o nome.
	 * @return nome do objeto.
	 */
	const String& getNome() const;

	/**
	 * Obter a cor do objeto.
	 * @return cor do objeto.
	 */
	const QColor& getCor() const;

	/**
	 * Obter o tipo.
	 * @return tipo do objeto.
	 */
	Tipo getTipo() const;

	/**
	 * Obter o tipo.
	 * @return tipo do objeto.
	 */
	const String getTipoString() const;

	/**
	 * Obter o centro geométrico do objeto.
	 * @return o ponto correspondento ao centro.
	 */
	virtual const Ponto getCentroGeometrico() const;

	/**
	 * Definir a cor do objeto.
	 * @param cor cor do objeto.
	 */
	void setCor(const QColor& cor);

	/**
	 * Operador de stream de saída.
	 * @param out stream de saída.
	 * @param o objeto geométrico.
	 * @return o stream de saída.
	 */
	friend std::ostream& operator<<(std::ostream& out,
			const ObjetoGeometrico& o) {
		return out << o.toString();
	}

	/**
	 * Escalonar o objeto.
	 * @param sX fator de escalonamento do eixo x.
	 * @param sY fator de escalonamento do eixo y.
	 * @param sZ fator de escalonamento do eixo z.
	 */
	virtual void escalonar(const double sX, const double sY, const double sZ);

	/**
	 * Transladar o objeto.
	 * @param sX fator de translação do eixo x.
	 * @param sY fator de translação do eixo y.
	 * @param sZ fator de translação do eixo z.
	 */
	virtual void transladar(const double sX, const double sY, const double sZ);

	/**
	 * Rotacionar pelo eixo X, em relação a um ponto específico.
	 * @param ponto ponto de rotação.
	 * @param angulo ângulo de rotação em graus.
	 */
	virtual void rotacionarPorX(const Ponto& ponto, const double angulo);

	/**
	 * Rotacionar pelo eixo Y em relação a um ponto específico.
	 * @param ponto ponto de rotação.
	 * @param angulo ângulo de rotação em graus.
	 */
	virtual void rotacionarPorY(const Ponto& ponto, const double angulo);

	/**
	 * Rotacionar pelo eixo Z em relação a um ponto específico.
	 * @param ponto ponto de rotação.
	 * @param angulo ângulo de rotação em graus.
	 */
	virtual void rotacionarPorZ(const Ponto& ponto, const double angulo);

	/**
	 * Rotacionar em relação ao eixo definido pelo usuário.
	 * @param angulo ângulo de rotação em graus.
	 */
	virtual void rotacionarPorEixo(const double angulo, const Reta& eixo);

	/**
	 * Aplicar uma transformação ao objeto.
	 * @param matriz matriz de transformação.
	 */
	virtual void aplicarTransformacao(const double matriz[4][4]);

protected:
	String nome;
	Tipo tipo;
	QColor cor;

};

#endif /* OBJETOGEOMETRICO_H_ */

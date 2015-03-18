#ifndef OBJETOGEOMETRICO_H_
#define OBJETOGEOMETRICO_H_

#include <QtCore/qlist.h>
#include <string>

typedef std::string String;

class Ponto;

/**
 * Objeto Geométrico.
 */
class ObjetoGeometrico {

public:
	/**
	 * Tipos de objetos geométricos
	 */
	enum Tipo {
		POLIGONO,
		PONTO,
		RETA,
		WINDOW
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
	 */
	ObjetoGeometrico(const String& nome, const Tipo tipo);

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
	 * Obter os pontos do objeto.
	 * @return lista de pontos.
	 */
	virtual QList<Ponto> getPontos() const;

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
	const Ponto getCentroGeometrico() const;

	/**
	 * Operador de stream de saída.
	 * @param out stream de saída.
	 * @param o objeto geométrico.
	 * @return o stream de saída.
	 */
	friend std::ostream& operator<<(std::ostream& out, const ObjetoGeometrico& o){
		return out << o.toString();
	}

protected:
	QList<Ponto> aplicarTransformacao(double matriz[3][3]);

protected:
	String nome;
	Tipo tipo;

};

#endif /* OBJETOGEOMETRICO_H_ */

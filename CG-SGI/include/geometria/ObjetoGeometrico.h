#ifndef OBJETOGEOMETRICO_H_
#define OBJETOGEOMETRICO_H_

#include <QtCore/qlist.h>
#include <string>

typedef std::string String;

class Ponto;

class ObjetoGeometrico {

public:
	ObjetoGeometrico();
	ObjetoGeometrico(const ObjetoGeometrico& objeto);
	ObjetoGeometrico(const String& nome);
	virtual ~ObjetoGeometrico();
	void operator=(const ObjetoGeometrico& objeto);
	const String& getNome() const;
	virtual QList<Ponto> getPontos();
	virtual const String toString() const;

	friend std::ostream& operator<<(std::ostream& out, const ObjetoGeometrico& o){
		return out << o.toString();
	}

protected:
	String nome;

};

#endif /* OBJETOGEOMETRICO_H_ */

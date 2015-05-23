#ifndef ARQUIVOOBJ_H_
#define ARQUIVOOBJ_H_

#include <sstream>
#include <istream>

#include <QtCore/qmap.h>
#include <QtGui/qcolor.h>

#include "geometria/Cena.h"
#include "geometria/Objeto3D.h"
#include "geometria/ObjetoGeometrico.h"
#include "geometria/Ponto.h"
#include "geometria/Poligono.h"
#include "geometria/Reta.h"
#include "geometria/Window.h"
#include "persistencia/Arquivo.h"
#include "persistencia/ArquivoMTL.h"

/**
 * Arquivo OBJ (Wavefront).
 */
class ArquivoOBJ : public Arquivo {

public:
	static const String BASIC_MAN;
	static const String CRISTO_REDENTOR;
	static const String DINO_MECH;
	static const String SUB_ZERO;

	/**
	 * Construtor.
	 * @param nome nome completo do arquivo.
	 */
	ArquivoOBJ(const String& nome);

	/**
	 * Destrutor.
	 */
	virtual ~ArquivoOBJ();

	/**
	 * Carregar o arquivo.
	 * @throws ExcecaoArquivoInvalido caso o arquivo seja inválido.
	 * @throws ExcecaoLeituraArquivo caso não seja possível ler o arquivo.
	 */
	void carregar() throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo);

	/**
	 * Gravar o arquivo.
	 * @throws ExcecaoEscritaArquivo caso não seja possível escrever no arquivo.
	 */
	void gravar() const throw(ExcecaoEscritaArquivo);

	/**
	 * Definir objetos do arquivo.
	 * @param objetos objetos do arquivo.
	 */
	void setObjetos(const QList<ObjetoGeometrico*>& objetos);

	/**
	 * Obter a cena carregada do arquivo.
	 * @return cena do arquivo.
	 */
	Cena* getCena() const;

protected:
	/**
	 * Remover todos os objetos do buffer do arquivo.
	 */
	void removerObjetos();

	/**
	 * Converter um texto para um ponto válido.
	 * @return o ponto criado ou uma referência nula caso não seja possível criar um ponto.
	 */
	Ponto* stringToPonto(const String& nome, const String& str) const;

	/**
	 * Limpar a lista de pontos.
	 * @param pontos lista a ser limpada.
	 */
	void limpar(QList<Ponto*> pontos) const;

	QList<ObjetoGeometrico*> objetos;
	Window* window;

};

#endif /* ARQUIVOOBJ_H_ */

#ifndef CONTROLADORPERSISTENCIA_H_
#define CONTROLADORPERSISTENCIA_H_

#include "persistencia/ArquivoOBJ.h"

/**
 * Controlador de Persistência.
 */
class ControladorPersistencia {

public:
	/**
	 * Construtor.
	 */
	ControladorPersistencia();

	/**
	 * Destrutor.
	 */
	virtual ~ControladorPersistencia();

	/**
	 * Exportar uma cena.
	 * @param arquivo nome completo do arquivo para o qual a cena será exportada.
	 * @param objetos lista de objetos da cena.
	 * @throws ExcecaoEscritaArquivo caso não seja possível exportar a cena para o arquivo.
	 */
	void exportarCena(const String& arquivo, const QList<ObjetoGeometrico*>& objetos) const
			throw(ExcecaoEscritaArquivo);

	/**
	 * Importar uma cena.
	 * @param arquivo nome completo do arquivo do qual a cena será importada.
	 * @return objetos da cena.
	 * @throws ExcecaoArquivoInvalido caso o arquivo seja inválido.
	 * @throws ExcecaoLeituraArquivo caso não seja possível ler a cena do arquivo.
	 */
	QList<ObjetoGeometrico*> importarCena(const String& arquivo) const
			throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo);

};

#endif /* CONTROLADORPERSISTENCIA_H_ */

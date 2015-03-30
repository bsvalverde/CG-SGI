#include "controle/ControladorPersistencia.h"

ControladorPersistencia::ControladorPersistencia() {}

ControladorPersistencia::~ControladorPersistencia() {}

void ControladorPersistencia::exportarCena(const String& arquivo, const QList<ObjetoGeometrico*>& objetos) const
		throw(ExcecaoEscritaArquivo) {
	ArquivoOBJ arquivoObj(arquivo);
	arquivoObj.setObjetos(objetos);
	arquivoObj.gravar();
}

QList<ObjetoGeometrico*> ControladorPersistencia::importarCena(const String& arquivo) const
		throw(ExcecaoArquivoInvalido, ExcecaoLeituraArquivo) {
	ArquivoOBJ arquivoObj(arquivo);
	arquivoObj.carregar();
	return arquivoObj.getObjetos();
}

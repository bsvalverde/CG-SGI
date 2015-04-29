#include "geometria/projecao/ProjetorParalelo.h"
#include "geometria/ObjetoGeometrico.h"
#include "geometria/Window.h"

ProjetorParalelo::ProjetorParalelo(Window* const window) :
		Projetor(Projetor::PARALELA_ORTOGONAL, window) {
}

ProjetorParalelo::~ProjetorParalelo() {
}

void ProjetorParalelo::projetarObjeto(ObjetoGeometrico* const objeto) const {

}

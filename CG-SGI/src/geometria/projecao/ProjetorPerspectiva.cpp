#include "geometria/projecao/ProjetorPerspectiva.h"
#include "geometria/ObjetoGeometrico.h"
#include "geometria/Window.h"

ProjetorPerspectiva::ProjetorPerspectiva(Window* const window) :
		Projetor(Projetor::PERSPECTIVA, window) {
}

ProjetorPerspectiva::~ProjetorPerspectiva() {
}

void ProjetorPerspectiva::projetarObjeto(ObjetoGeometrico* const objeto) const {

}

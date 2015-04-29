#include "controle/ControladorMundo.h"

ControladorMundo::ControladorMundo() {}

ControladorMundo::~ControladorMundo() {}

void ControladorMundo::navegarNoMundo(const Mundo::Direcao direcao, const double fator) {
	this->mundo.navegar(direcao, fator);
}

void ControladorMundo::aplicarZoomNoMundo(const double fator) {
	this->mundo.aplicarZoom(fator);
}

void ControladorMundo::rotacionarVisualizacao(const double angulo) {
	this->mundo.rotacionarVisualizacao(angulo);
}

void ControladorMundo::reiniciarVisualizacao(){
	this->mundo.reiniciarVisualizacao();
}

void ControladorMundo::setProjetorVisualizacao(const Projetor::TipoProjecao& tipoProjecao) {
	this->mundo.setProjetorVisualizacao(tipoProjecao);
}

QList<ObjetoGeometrico*> ControladorMundo::getObjetosReais() const {
	return this->mundo.getObjetosReais();
}

QList<ObjetoGeometrico*> ControladorMundo::getObjetosNormalizados() const {
	return this->mundo.getObjetosNormalizados();
}

void ControladorMundo::removerObjetosMundo() {
	this->mundo.removerObjetos();
}

void ControladorMundo::atualizarObjetos(const QList<ObjetoGeometrico*>& objetos) {
	this->mundo.removerObjetos();

	for(ObjetoGeometrico* obj : objetos)
		this->mundo.inserirObjeto(*obj);
}

void ControladorMundo::inserirObjeto(const String& nome, const QList<Ponto>& pontos, ObjetoGeometrico::Tipo tipo, const QColor& cor) {
	Ponto p = pontos.at(0);

	switch(tipo) {
		case ObjetoGeometrico::CURVA_BEZIER:
			this->mundo.inserirObjeto(CurvaBezier(nome, pontos.at(0), pontos.at(1),
													pontos.at(2), pontos.at(3), cor));
			break;
		case ObjetoGeometrico::CURVA_BSPLINE:
			this->mundo.inserirObjeto(CurvaBSpline(nome, pontos, cor));
			break;
		case ObjetoGeometrico::POLIGONO:
			this->mundo.inserirObjeto(Poligono(nome, pontos, cor));
			break;
		case ObjetoGeometrico::PONTO:
			this->mundo.inserirObjeto(Ponto(nome, p.getX(), p.getY(), p.getZ(), cor));
			break;
		case ObjetoGeometrico::RETA:
			this->mundo.inserirObjeto(Reta(nome, pontos.at(0), pontos.at(1), cor));
			break;
		default:
			break;
	}
}

void ControladorMundo::removerObjeto(const String& nome) {
	this->mundo.removerObjeto(nome);
}

bool ControladorMundo::contemObjeto(const String& nome) {
	return this->mundo.contemObjeto(nome);
}

void ControladorMundo::escalonarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.escalonarObjeto(obj, sX, sY, sZ);
}

void ControladorMundo::transladarObjeto(const String& nome, const double sX, const double sY, const double sZ) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.transladarObjeto(obj, sX, sY, sZ);
}

void ControladorMundo::rotacionarObjetoPorPonto(const String& nome, const Ponto& ponto, const double angulo) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.rotacionarObjetoPorPonto(obj, ponto, angulo, Mundo::EIXO_X); // TODO
}

void ControladorMundo::rotacionarObjetoPeloCentro(const String& nome, const double angulo) {
	ObjetoGeometrico* obj = this->mundo.getObjeto(nome);
	this->mundo.rotacionarObjetoPeloCentro(obj, angulo, Mundo::EIXO_X); // TODO
}

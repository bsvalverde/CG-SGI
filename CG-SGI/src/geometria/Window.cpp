#include "geometria/Window.h"

Window::Window() : ObjetoGeometrico("Window", Tipo::WINDOW) {
	this->centro = Ponto("centro", 0, 0, 0);
	this->centroProjecao = Ponto("centroProjecao", 0, 0, -120);
	this->viewUpVector = Ponto("viewUpVector", 0, 138.75, 0);
	this->viewRightVector = Ponto("viewRightVector", 0, 118.75, 0);
	this->vpnVector = Ponto("vpnVector", 0, 0, 120);
	this->projetor = 0;
	this->setTipoProjecao(Projetor::PERSPECTIVA);
}

Window::Window(const Window& window) : ObjetoGeometrico(window) {
	this->centro = window.centro;
	this->centroProjecao = window.centroProjecao;
	this->viewUpVector = window.viewUpVector;
	this->viewRightVector = window.viewRightVector;
	this->vpnVector = window.vpnVector;
	this->displayFileNormalizado = window.displayFileNormalizado;
	this->projetor = 0;
	this->setTipoProjecao(window.projetor->getTipo());
}

Window::Window(const Ponto& centro, const double largura, const double altura) : ObjetoGeometrico("Window", Tipo::WINDOW) {
	this->centro = centro;
	this->centroProjecao = Ponto("viewRightVector", 0, 0, -120);
	this->viewUpVector = Ponto("viewUpVector", 0, altura/2, 0);
	this->viewRightVector = Ponto("viewRightVector", 0, largura/2, 0);
	this->vpnVector = Ponto("viewRightVector", 0, 0, 120);
	this->projetor = 0;
	this->setTipoProjecao(Projetor::PERSPECTIVA);
}

Window::~Window() {
	if(this->projetor)
		delete this->projetor;
}

Window& Window::operator=(const Window& window) {
	this->ObjetoGeometrico::operator =(window);
	this->centro = window.centro;
	this->centroProjecao = window.centroProjecao;
	this->viewUpVector = window.viewUpVector;
	this->viewRightVector = window.viewRightVector;
	this->vpnVector = window.vpnVector;
	this->displayFileNormalizado = window.displayFileNormalizado;
	this->projetor = 0;
	this->setTipoProjecao(window.projetor->getTipo());
	return *this;
}

ObjetoGeometrico* Window::clonar() const {
	return new Window(*this);
}

QList<Ponto> Window::getPontos() const {
	QList<Ponto> pontos;
	pontos.insert(0, this->centro);
	pontos.insert(1, this->viewUpVector);
	pontos.insert(2, this->viewRightVector);
	pontos.insert(3, this->vpnVector);
	pontos.insert(4, this->centroProjecao);
	return pontos;
}

const String Window::toString() const {
	return this->nome + "[" + this->centro.toString() +
				", " + this->viewUpVector.toString() +
				", " + this->viewRightVector.toString() +
				", " + this->vpnVector.toString() +
				", " + this->centroProjecao.toString() + "]";
}

const Ponto Window::getCentroGeometrico() const {
	return this->centro;
}

const double Window::getLargura() const {
	return this->getTamanhoViewRightVector() * 2;
}

const double Window::getAltura() const {
	return this->getTamanhoViewUpVector() * 2;
}

Ponto Window::getVpnVector() const {
	return this->vpnVector;
}

Ponto Window::getCentroProjecao() const {
	return this->centroProjecao;
}

void Window::atualizarDisplayFile(const DisplayFile& displayFile) {
	this->displayFileNormalizado = displayFile;
	int tam = this->displayFileNormalizado.getTamanho();

	for(int i = 0; i < tam; i++)
		this->atualizarObjeto(this->displayFileNormalizado.getObjeto(i));
}

void Window::atualizarObjeto(ObjetoGeometrico* const obj) {
	double angulo = this->anguloViewUpVectorEixoY();
	double tamY = this->getTamanhoViewUpVector();
	double tamX = this->getTamanhoViewRightVector();
	double matriz[4][4] = {{cos(-angulo)/tamX, -sin(-angulo)/tamY, 0, 0},
							{sin(-angulo)/tamX, cos(-angulo)/tamY, 0, 0},
							{0, 0, 1, 0},
							{0, 0, 0, 1}};

	if(!this->displayFileNormalizado.contem(obj->getNome())) {
		this->displayFileNormalizado.inserirObjeto(*obj);
	}

	ObjetoGeometrico* objeto = this->displayFileNormalizado.getObjeto(obj->getNome());
	this->projetor->projetarObjeto(objeto);
	objeto->aplicarTransformacao(matriz);
}

void Window::removerObjeto(const String& nome) {
	this->displayFileNormalizado.removerObjeto(nome);
}

double Window::anguloViewUpVectorEixoY() const {
	double x = this->viewUpVector.getX() - this->centro.getX();
	double y = this->viewUpVector.getY() - this->centro.getY();
	double tan = x / y;
	double angulo = atan(tan);

	if(y < 0 && x < 0) { // 3º quadrante
		angulo += M_PI;
	} else if(y < 0 && x > 0) { // 4º quadrante
		angulo += -M_PI;
	}

	return angulo;
}

double Window::getTamanhoViewUpVector() const {
	double x = this->viewUpVector.getX() - this->centro.getX();
	double y = this->viewUpVector.getY() - this->centro.getY();
	double z = this->viewUpVector.getZ() - this->centro.getZ();
	double hip = sqrt(pow(x, 2)+pow(z, 2));
	return sqrt(pow(hip, 2)+pow(y, 2));
}

double Window::getTamanhoViewRightVector() const {
	double x = this->viewRightVector.getX() - this->centro.getX();
	double y = this->viewRightVector.getY() - this->centro.getY();
	double z = this->viewRightVector.getZ() - this->centro.getZ();
	double hip = sqrt(pow(x, 2)+pow(z, 2));
	return sqrt(pow(hip, 2)+pow(y, 2));
}

QList<ObjetoGeometrico*> Window::getObjetos() const {
	return this->displayFileNormalizado.getObjetos();
}

void Window::removerObjetos() {
	this->displayFileNormalizado.removerObjetos();
}

void Window::setTipoProjecao(const Projetor::TipoProjecao& tipoProjecao) {
	if(this->projetor)
		delete this->projetor;

	switch(tipoProjecao) {
		case Projetor::PARALELA_ORTOGONAL:
			this->projetor = new ProjetorParalelo(this);
			break;
		case Projetor::PERSPECTIVA:
			this->projetor = new ProjetorPerspectiva(this);
			break;
	}
}

QList<Ponto*> Window::getPontosObjeto() {
	QList<Ponto*> pontos;
	pontos.insert(0, &this->centro);
	pontos.insert(1, &this->viewUpVector);
	pontos.insert(2, &this->viewRightVector);
	pontos.insert(3, &this->vpnVector);
	pontos.insert(4, &this->centroProjecao);
	return pontos;
}

void Window::transladar(const double sX, const double sY, const double sZ) {
	double anguloY = this->anguloViewUpVectorEixoY();
	double anguloX = anguloY + M_PI/2;

	double matriz[4][4] = { { 1, 0, 0, 0 },
							{ 0, 1, 0, 0 },
							{ 0, 0, 1, 0 },
							{ sX*sin(anguloX) + sY*sin(anguloY), sX*cos(anguloX) + sY*cos(anguloY), sZ, 1 } };
	this->aplicarTransformacao(matriz);
}

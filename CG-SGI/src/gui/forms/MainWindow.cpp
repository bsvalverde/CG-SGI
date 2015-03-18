#include "gui/forms/MainWindow.h"
#include "geometria/Poligono.h"
#include "geometria/Reta.h"

MainWindow::MainWindow(ControladorUI* controladorUI, QDialog* parent,
						Qt::WindowFlags flags) : DefaultWindow(controladorUI, parent, flags) {
	this->setupUi(this);
	this->moveToCenter();
	this->connectSignalsAndSlots();
	this->zoomControl->setValue(50);
    this->viewportWidth = 510;
    this->viewportHeight = 475;
}

void MainWindow::updateObjects(Window& window, QList<ObjetoGeometrico> objects) {
	QGraphicsView* g = this->graphicsView;
	QGraphicsScene* scene = g->scene();
	QList<ObjetoGeometrico> objs = this->viewportTransformation(window, objects);

	if(scene)
		delete scene;

	scene = new QGraphicsScene(0, 0, this->viewportWidth - 4,
								this->viewportHeight - 6, this->graphicsView);

	for(int i = 0; i < objs.size(); i++) {
		QList<Ponto> pontos = objs.at(i).getPontos();

		if(pontos.size() > 1) {
			Ponto ant = pontos.at(0);

			for(int i = 1; i < pontos.size(); i++) {
				scene->addLine(ant.getX(), ant.getY(), pontos.at(i).getX(), pontos.at(i).getY());
			}
		} else {
			Ponto p1 = pontos.at(0);
			scene->addEllipse(p1.getX(), p1.getY(), 1, 1, Qt::SolidLine, Qt::SolidPattern);
		}
	}

	this->graphicsView->setScene(scene);
	this->graphicsView->repaint();

}

QList<ObjetoGeometrico> MainWindow::viewportTransformation(Window& window,
										QList<ObjetoGeometrico> objects) {
	QList<ObjetoGeometrico> newObjects;
	QList<Ponto> windowPoints = window.getPontos();
	double xwMin = windowPoints.at(0).getX();
	double xwMax = windowPoints.at(1).getX();
	double ywMin = windowPoints.at(0).getY();
	double ywMax = windowPoints.at(1).getY();

	for(int i = 0; i < objects.size(); i++) {
		ObjetoGeometrico obj = objects.at(i);
		QList<Ponto> points = obj.getPontos();
		QList<Ponto> newPoints;

		switch(obj.getTipo()) {
			case ObjetoGeometrico::PONTO:
				obj = this->pointTransformation(points.at(0), xwMin, xwMax, ywMin, ywMax);
				newObjects.insert(i, obj);
				break;
			case ObjetoGeometrico::RETA:
				obj = Reta(obj.getNome(),
						this->pointTransformation(points.at(0), xwMin, xwMax, ywMin, ywMax),
						this->pointTransformation(points.at(1), xwMin, xwMax, ywMin, ywMax));
				newObjects.insert(i, obj);
				break;
			case ObjetoGeometrico::POLIGONO:
				for(int j = 0; j < points.size(); i++) {
					newPoints.insert(j, this->pointTransformation(points.at(j), xwMin, xwMax, ywMin, ywMax));
				}
				obj = Poligono(obj.getNome(), newPoints);
				newObjects.insert(i, obj);
				break;
			default:
				break;
		}
	}

	return newObjects;
}

Ponto MainWindow::pointTransformation(Ponto point, double xwMin, double xwMax, double ywMin, double ywMax) {
	double xp = (point.getX() - xwMin) / (xwMax - xwMin) * this->viewportWidth;
	double yp = (1 - (point.getY() - ywMin) / (ywMax - ywMin)) * this->viewportHeight;
	Ponto newPoint(point.getNome(), xp, yp, 1);
	return newPoint;
}

void MainWindow::connectSignalsAndSlots() {
/*	QObject::connect(btnZoomIn, SIGNAL(pressed()), this, SLOT(btnZoomInPressed()));
	QObject::connect(btnZoomOut, SIGNAL(pressed()), this, SLOT(btnZoomOutPressed()));
	QObject::connect(zoomControl, SIGNAL(valueChanged(int)), this, SLOT(zoomControlValueChanged(int)));
	QObject::connect(btnInsertObject, SIGNAL(clicked()), this, SLOT(btnInsertObjectClicked()));
	QObject::connect(btnRemoveObject, SIGNAL(clicked()), this, SLOT(btnRemoveObjectClicked()));
	QObject::connect(btnUp, SIGNAL(clicked()), this, SLOT(btnNavigationUpPressed()));
	QObject::connect(btnLeft, SIGNAL(clicked()), this, SLOT(btnNavigationLeftPressed()));
	QObject::connect(btnCenter, SIGNAL(clicked()), this, SLOT(btnNavigationCenterPressed()));
	QObject::connect(btnRight, SIGNAL(clicked()), this, SLOT(btnNavigationRightPressed()));
	QObject::connect(btnDown, SIGNAL(clicked()), this, SLOT(btnNavigationDownPressed()));
	*/
}

void MainWindow::btnZoomInPressed() {
	int position = this->zoomControl->value();
	this->zoomControl->setValue(position + 5);

	QList<ObjetoGeometrico> list;
	Ponto p1("", 0, 0, 0);
	Ponto p2("", 510, 475, 0);
	Window w(p1, p2);
	this->updateObjects(w, list);
}

void MainWindow::btnZoomOutPressed() {
	int position = this->zoomControl->value();
	this->zoomControl->setValue(position - 5);
}

void MainWindow::zoomControlValueChanged(int currentValue) {

}

void MainWindow::btnInsertObjectClicked() {
	this->controladorUI->exibirObjectInsertionWindow();
}

void MainWindow::btnRemoveObjectClicked() {

}

void MainWindow::btnNavigationUpPressed() {

}

void MainWindow::btnNavigationLeftPressed() {

}

void MainWindow::btnNavigationCenterPressed() {

}

void MainWindow::btnNavigationRightPressed() {

}

void MainWindow::btnNavigationDownPressed() {

}


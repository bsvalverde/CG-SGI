#ifndef PIXEL_H_
#define PIXEL_H_

#include <QtGui/qcolor.h>
#include "geometria/Ponto.h"

class Pixel {

public:
	Pixel();
	Pixel(const unsigned int x, const unsigned int y, const double z,
			const QColor& cor, Ponto normal);
	virtual ~Pixel();

	unsigned int getX() const;
	unsigned int getY() const;
	double getZ() const;
	QColor getCor() const;
	Ponto getNormal() const;
	void setCor(QColor novaCor);

private:
	unsigned int x;
	unsigned int y;
	double z;
	QColor cor;
	Ponto normal;

};

#endif /* PIXEL_H_ */

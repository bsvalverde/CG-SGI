#ifndef PIXEL_H_
#define PIXEL_H_

#include <QtGui/qcolor.h>

class Pixel {

public:
	Pixel(const unsigned int x, const unsigned int y, const unsigned int z, const QColor& cor);
	virtual ~Pixel();

	unsigned int getX() const;
	unsigned int getY() const;
	unsigned int getZ() const;
	QColor getCor() const;

private:
	unsigned int x;
	unsigned int y;
	unsigned int z;
	QColor cor;

};

#endif /* PIXEL_H_ */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "form.h"
#include "figure.h"

class Rectangle : public Figure, public Form
{
public:
	Rectangle(const Point & tl, const Point & br, color::colorList cl);
	void printInfo();
};

#endif // RECTANGLE_H

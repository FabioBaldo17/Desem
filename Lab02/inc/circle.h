#ifndef CIRCLE_H
#define CIRCLE_H

#include "form.h"
#include "figure.h"

class Circle : public Figure, public Form
{
public:
	Circle(const Point & tl, const Point & br, color::colorList cl);
	void printInfo();
};

#endif // CIRCLE_H

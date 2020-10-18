#ifndef LINE_H
#define LINE_H

#include "form.h"
#include "figure.h"

class Line : public Figure, public Form
{
public:
	Line(const Point & tl, const Point & br, color::colorList cl);
	void printInfo();
};

#endif // LINE_H

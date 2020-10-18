#include <stdlib.h>
#include <iostream>
#include <string>
#include "point.h"

using namespace std;

Point::Point(uint32_t x, uint32_t y)
 : _x(x),
   _y(y)
{
}

uint32_t Point::x() const
{
    return _x;
}

void Point::setX(uint32_t value)
{
    _x = value;
}

uint32_t Point::y() const
{
    return _y;
}

void Point::setY(uint32_t value)
{
    _y = value;
}

void Point::printInfo() const
{
	cout << "Poin in x = " << x() << ", y = " << y() << endl;
}

string Point::toString() const
{
    char buffer[32];
    sprintf(buffer,"(%d,%d)",x(),y());
    return string(buffer);
}



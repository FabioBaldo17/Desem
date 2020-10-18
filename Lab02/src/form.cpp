#include "form.h"

string color::toString(colorList color)
{
	switch (color)
	{
	case blue:
		return "blue";
		break;
	case purple:
		return "purple";
		break;
	case yellow:
		return "yellow";
		break;
	}
	return "unknown color";
}

color::colorList color::getColor(uint32_t firstLetter)
{
	switch (firstLetter)
	{
	case 'b':
		return blue;
		break;
	case 'p':
		return purple;
		break;
	case 'y':
		return yellow;
		break;
	}
	return blue; // Default color
}

Form::Form(const Point & tl, const Point & br, color::colorList cl)
 : _topLeft(tl),
   _bottonRight(br),
   _color(cl)
{
}

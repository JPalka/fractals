#include "colorrange.h"

double ColorRange::getRange()
{
	return _range;
}

ColorRange::ColorRange ( double range, RGB color ) : _range ( range ), _color ( color ) {

}

bool ColorRange::operator<(ColorRange &rhs)
{
	return this->_range < rhs._range;
}

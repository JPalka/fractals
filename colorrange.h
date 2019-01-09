#ifndef COLORRANGE_H
#define COLORRANGE_H

#include "rgb.h"

//TODO: ENKAPSULACJA
class ColorRange
{

	public:

		double _range{0}; // Zakres max iteracji (0, 1)
		RGB _color;
		int _pixelCount{0}; // ilość pixeli w tym zakresie

		double getRange();
		ColorRange ( double range, RGB color );
		bool operator< ( ColorRange &rhs );
};

#endif // COLORRANGE_H

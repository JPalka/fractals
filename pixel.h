#ifndef PIXEL_H
#define PIXEL_H

#include "rgb.h"

class Pixel {
	public:
		RGB _color; //kolor pixela. TODO: zmienić na jakąś bazową klase COLOR* i dać ew możliwość różnych schematów kolorów
		int _iterations; // ilosc iteracji algorytmu na tym pixelu TODO: dostosować to pod inne fraktale
		void setColor ( const RGB &color ) {
			_color = color;
		}
		Pixel ( const RGB &color = RGB (0, 0, 0) ) : _color ( color ) {

		};
};

#endif // PIXEL_H

#ifndef COLORSCHEME_H
#define COLORSCHEME_H

#include <vector>
#include "pixel.h"

// Schemat kolorowania pixeli. moze być histogram, gładszy histogram, whatever.
class ColorScheme {
	public:
		virtual void color ( int width, int height, std::vector<Pixel> &pixels ) = 0;
};


#endif // COLORSCHEME_H

#ifndef COLORSCHEME_H
#define COLORSCHEME_H

#include <vector>
#include "pixel.h"
#include "colorrange.h"
#include <iostream>

// Schemat kolorowania pixeli. moze być histogram, gładszy histogram, whatever.
class ColorScheme {
	public:
		virtual void color ( int width, int height, std::vector<Pixel> &pixels ) = 0;
		virtual ~ColorScheme () {
			std::cout << "Colorscheme destructor\n";
		}
		virtual ColorScheme *clone () = 0;
		virtual void removeColorRange ( double range ) { range+= 1; }
		virtual void addColorRange ( ColorRange colorRange ) { colorRange.getRange (); }
};


#endif // COLORSCHEME_H

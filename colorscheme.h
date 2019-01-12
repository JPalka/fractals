#ifndef COLORSCHEME_H
#define COLORSCHEME_H

#include <vector>
#include "pixel.h"
#include "colorrange.h"
#include <iostream>
#include <iomanip>

// Schemat kolorowania pixeli. moze być histogram, gładszy histogram, whatever.
class ColorScheme {
	public:
		virtual void colorPixel ( Pixel &pixel ) = 0;
		virtual ~ColorScheme () {
//			std::cout << "Colorscheme destructor\n";
		}
		virtual ColorScheme *clone () = 0;
		virtual void init ( std::vector<Pixel> &pixels ) = 0;
		virtual void removeColorRange ( double range ) { range+= 1; }
		virtual void addColorRange ( ColorRange colorRange ) { colorRange.getRange (); }
		virtual void setMaxIterations ( int maxIterations ) { maxIterations += 1; }
		virtual void printProgress ( double percentage ) {
			std::cout << "\r";
			std::cout.fill (0);
			std::cout.width (5);
			std::cout << std::left << std::setprecision (3) << percentage << "%" << std::flush;
		}
};

#endif // COLORSCHEME_H

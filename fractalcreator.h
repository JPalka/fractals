#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <memory>
#include <cstdint>
#include <math.h>
#include <vector>

#include "zoomlist.h"
#include "bitmap.h"
#include "mandelbrot.h"
#include "tricorn.h"
#include "zoom.h"
#include "rgb.h"
#include "fractal.h"

class FractalCreator
{
	private:
		int _width{0};
		int _height{0};
		std::unique_ptr<EscapeFractal> _fractalType { nullptr };
		ZoomList _zoomList;
		std::unique_ptr<int[]> _histogram { nullptr };
		std::unique_ptr<int[]> _fractal { nullptr };
		Bitmap _bitmap;
		int _totalIterations {0};
		std::vector<int> _ranges;
		std::vector<RGB> _colors;
		std::vector<int> _rangeTotals;
		bool _gotFirstRange {false};

		void calculateIteration ();
		void countIterations ();
		void drawFractal ();
		void writeBitmap ( std::string filename );
	public:
		int getRange ( int iterations ) const;
		FractalCreator ( int width, int height, EscapeFractal *fractalType );
		void addZoom ( const Zoom &zoom );
		void run ( std::string filename );
		void addRange ( double rangeEnd, const RGB &rgb );
		void calculateRangeTotals ();
};

#endif // FRACTALCREATOR_H

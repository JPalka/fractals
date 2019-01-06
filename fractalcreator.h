#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <memory>
#include <cstdint>
#include <math.h>

#include "zoomlist.h"
#include "bitmap.h"
#include "mandelbrot.h"
#include "zoom.h"
#include "rgb.h"

class FractalCreator
{
	private:
		int _width{0};
		int _height{0};
		ZoomList _zoomList;
		std::unique_ptr<int[]> _histogram { nullptr };
		std::unique_ptr<int[]> _fractal { nullptr };
		Bitmap _bitmap;
		int _totalIterations{0};
		void calculateIteration ();
		void countIterations ();
		void drawFractal ();
		void writeBitmap ( std::string filename );
	public:
		FractalCreator ( int width, int height );
		void addZoom ( const Zoom &zoom );
		void run ( std::string filename );
};

#endif // FRACTALCREATOR_H

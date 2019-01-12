#ifndef MANDELBROT_H
#define MANDELBROT_H
#include "fractal.h"

class Mandelbrot : public Fractal {
	public:
		int getIterations ( double x, double y ) override;
		void calculatePixelData ( Pixel &pixel ) override;
		Mandelbrot(int maxIterations, ColorScheme &coloringMethod );
};

#endif // MANDELBROT_H

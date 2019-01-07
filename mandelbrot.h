#ifndef MANDELBROT_H
#define MANDELBROT_H
#include "escapefractal.h"

class Mandelbrot : public EscapeFractal {
	public:
		int getIterations ( double x, double y );
		Mandelbrot( int maxIterations );

};

#endif // MANDELBROT_H

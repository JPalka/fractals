#include "mandelbrot.h"
#include <complex>
#include <memory>

Mandelbrot::Mandelbrot ( int maxIterations, ColorScheme *coloringMethod ) {
	_maxIterations = maxIterations;
	_coloringMethod = std::unique_ptr<ColorScheme> ( coloringMethod );
//	_coloringMethod = std::unique_ptr<ColorScheme> ( new Histogram ( maxIterations, RGB ( 255, 0, 0 ) ) );
}

int Mandelbrot::getIterations ( double x, double y ) {
	std::complex<double> z = 0;
	std::complex<double> c ( x, y );
	int iterations {0};
	while ( iterations < _maxIterations ) {
		z = z * z + c;
		if ( abs( z ) > 2 ) {
			break;
		}
		iterations++;
	}
	return iterations;
}

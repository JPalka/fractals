#include "mandelbrot.h"
#include <complex>

Mandelbrot::Mandelbrot ( int maxIterations = 1000 ) {
	_maxIterations = maxIterations;
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

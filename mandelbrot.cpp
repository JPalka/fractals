#include "mandelbrot.h"
#include <complex>
#include <memory>

Mandelbrot::Mandelbrot ( int maxIterations, ColorScheme &coloringMethod ) {
	_maxIterations = maxIterations;
	_coloringMethod = std::unique_ptr<ColorScheme> ( coloringMethod.clone () );
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

void Mandelbrot::calculatePixelData ( Pixel &pixel ) {
	std::complex<double> z = 0;
	std::complex<double> c ( pixel._scaledX, pixel._scaledY );
	int iterations {0};
	while ( iterations < _maxIterations ) {
		z = z * z + c;
		if ( abs( z ) > 2 ) {
			break;
		}
		iterations++;
	}
	pixel._iterations = iterations;
	pixel._z = z; // wartość funkcji fraktala po policzeniu iteracji
}

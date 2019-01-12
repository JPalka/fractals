#include "julia.h"
#include <math.h>
#include <complex>
#include <memory>

Julia::Julia ( int maxIterations, ColorScheme &coloringMethod ) {
	_maxIterations = maxIterations;
	_coloringMethod = std::unique_ptr<ColorScheme> ( coloringMethod.clone() );
}

int Julia::getIterations ( double x, double y ) {
	std::complex<double> z ( x, y );
	std::complex<double> c ( -0.162, 1.04 );
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


void Julia::calculatePixelData ( Pixel &pixel ) {
	std::complex<double> z ( pixel._scaledX, pixel._scaledY );
	std::complex<double> c ( -0.162, 1.04 );
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



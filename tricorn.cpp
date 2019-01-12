#include "tricorn.h"
#include <math.h>
#include <complex>

Tricorn::Tricorn ( int maxIterations, ColorScheme &coloringMethod )  {
	_maxIterations = maxIterations;
	_coloringMethod = std::unique_ptr<ColorScheme> ( coloringMethod.clone() );
}

int Tricorn::getIterations ( double x, double y ) {
	std::complex<double> z = 0;
	std::complex<double> c ( x, y );
	int iterations {0};
	while ( iterations < _maxIterations ) {
		z = std::conj ( z ) * std::conj ( z ) + c;
		if ( abs( z ) > 2 ) {
			break;
		}
		iterations++;
	}
	return iterations;
}

void Tricorn::calculatePixelData ( Pixel &pixel ) {
	std::complex<double> z = 0;
	std::complex<double> c ( pixel._scaledX, pixel._scaledY );
	int iterations {0};
	while ( iterations < _maxIterations ) {
		z = std::conj ( z ) * std::conj ( z ) + c;
		if ( abs( z ) > 2 ) {
			break;
		}
		iterations++;
	}
	pixel._iterations = iterations;
	pixel._z = z;
}

#include "julia.h"
#include <math.h>
#include <complex>


Julia::Julia ( int maxIterations, ColorScheme *coloringMethod ) {
	_maxIterations = maxIterations;
	_coloringMethod = std::unique_ptr<ColorScheme> ( coloringMethod );
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



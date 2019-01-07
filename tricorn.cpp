#include "tricorn.h"
#include <math.h>
#include <complex>

Tricorn::Tricorn ( int maxIterations )  {
	_maxIterations = maxIterations;
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

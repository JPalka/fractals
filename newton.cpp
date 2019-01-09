#include "newton.h"

#include <vector>

Newton::Newton ( int maxIterations ) {
	_maxIterations = maxIterations;
	_coloringMethod = std::unique_ptr<ColorScheme> ( new Histogram ( maxIterations, RGB ( 0, 255, 0 ) ) );
}

int Newton::getIterations ( double x, double y ) {
	std::complex<double> z ( x, y );
	std::vector<std::complex<double>> roots;
	roots.push_back ( std::complex<double> (1, 0));
	roots.push_back ( std::complex<double> ( -0.5, sqrt(3)/2 ) );
	roots.push_back ( std::complex<double> ( -0.5, -sqrt(3)/2 ) );

	for ( int i = 0; i < _maxIterations; i ++ ) {
		z -= baseFunction ( z ) / derivativeFunction ( z );
		double tolerance = 0.000001;
		for ( uint j = 0; j < roots.size (); j++ ) {
			std::complex<double> difference = z - roots[j];
//			if ( abs ( difference.real () ) < tolerance && abs ( difference.imag () ) < tolerance ) {
//				return i;
//			}
			if ( abs ( difference ) < tolerance && abs ( difference ) < tolerance ) {
				return i;
			}
		}
	}
	return 0; //Jak nie ma rozwiazania to chuj, zero.
}

// z^3 - 1
std::complex<double> Newton::baseFunction(std::complex<double> z) {
	return z * z * z - std::complex<double> ( 1, 0 );
}

// 3*z^2
std::complex<double> Newton::derivativeFunction(std::complex<double> z) {
	return 3.0 * ( z * z );
}

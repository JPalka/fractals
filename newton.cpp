#include "newton.h"

#include <vector>

Newton::Newton ( int maxIterations, ColorScheme &coloringMethod ) {
	_maxIterations = maxIterations;
	_coloringMethod = std::unique_ptr<ColorScheme> ( coloringMethod.clone () );
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

void Newton::calculatePixelData ( Pixel &pixel ) {
	std::complex<double> z ( pixel._scaledX, pixel._scaledY );
	std::vector<std::complex<double>> roots;
	roots.push_back ( std::complex<double> (1, 0));
	roots.push_back ( std::complex<double> ( -0.5, sqrt(3)/2 ) );
	roots.push_back ( std::complex<double> ( -0.5, -sqrt(3)/2 ) );

	for ( int i = 0; i < _maxIterations; i ++ ) {
		z -= baseFunction ( z ) / derivativeFunction ( z );
		double tolerance = 0.000001;
		for ( uint j = 0; j < roots.size (); j++ ) {
			std::complex<double> difference = z - roots[j];
			if ( abs ( difference ) < tolerance && abs ( difference ) < tolerance ) {
				pixel._iterations = i;
				pixel._z = z;
				return;
			}
		}
	}
	// Jak nie ma rozwiązań to zero
	pixel._iterations = 0;
}


// z^3 - 1
std::complex<double> Newton::baseFunction(std::complex<double> z) {
	return z * z * z - std::complex<double> ( 1, 0 );
}

// 3*z^2
std::complex<double> Newton::derivativeFunction(std::complex<double> z) {
	return 3.0 * ( z * z );
}

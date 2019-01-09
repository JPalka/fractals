#ifndef NEWTON_H
#define NEWTON_H

#include "escapefractal.h"
#include <complex>

class Newton : public EscapeFractal {
		std::complex<double> baseFunction ( std::complex<double> z );
		std::complex<double> derivativeFunction ( std::complex<double> z );
	public:
		int getIterations ( double x, double y ) override;
		Newton ( int maxIterations, ColorScheme *coloringMethod );
};

#endif // NEWTON_H

#ifndef JULIA_H
#define JULIA_H
#include "fractal.h"

class Julia : public Fractal {
	public:
		Julia (int maxIterations, ColorScheme &coloringMethod );
		int getIterations ( double x, double y );
};

#endif // JULIA_H

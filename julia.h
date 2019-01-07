#ifndef JULIA_H
#define JULIA_H
#include "escapefractal.h"

class Julia : public EscapeFractal {
	public:
		Julia ( int maxIterations );
		int getIterations ( double x, double y );
};

#endif // JULIA_H

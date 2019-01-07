#ifndef TRICORN_H
#define TRICORN_H
#include "escapefractal.h"

class Tricorn : public EscapeFractal {
	public:
		Tricorn ( int maxIterations );
		int getIterations(double x, double y);
};

#endif // TRICORN_H

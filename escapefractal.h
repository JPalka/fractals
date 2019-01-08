#ifndef ESCAPEFRACTAL_H
#define ESCAPEFRACTAL_H

#include "fractal.h"

class EscapeFractal : public Fractal {
	public:
		int _maxIterations;
		virtual int getIterations ( double x, double y ) = 0;
		virtual void calculateFractal () override;
		virtual ~EscapeFractal () {}
};

#endif // ESCAPEFRACTAL_H

#ifndef TRICORN_H
#define TRICORN_H
#include "fractal.h"

class Tricorn : public Fractal {
	public:
		Tricorn (int maxIterations , ColorScheme &coloringMethod);
		void calculatePixelData ( Pixel &pixel ) override;
		int getIterations(double x, double y);
};

#endif // TRICORN_H

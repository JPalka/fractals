#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <memory>
#include <vector>
#include "colorscheme.h"
#include "pixel.h"
#include "rgb.h"
#include "colorrange.h"

class Histogram : public ColorScheme {
	std::unique_ptr<int[]> _histogram;
	int _maxIterations{0};
	RGB _color;
	void fillHistogram ( std::vector<Pixel> &pixels );
	public:
	virtual void colorPixel ( Pixel &pixel ) override;
	virtual void init ( std::vector<Pixel> &pixels ) override;
	void setColor ( RGB color );
	Histogram ( uint maxIterations , RGB color );
	Histogram ( Histogram & source );
	void setMaxIterations ( int maxIterations ) override;
	~Histogram ();
	Histogram *clone () override;
	int countTotalIterations ();
};

#endif // HISTOGRAM_H

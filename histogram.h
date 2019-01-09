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
	void fillHistogram (  int width, int height, std::vector<Pixel> pixels );
	public:
	void setColor ( RGB color );
	Histogram (uint maxIterations , RGB color);
	void color ( int width, int height, std::vector<Pixel> &pixels ) override;
	int countTotalIterations ();
};

#endif // HISTOGRAM_H

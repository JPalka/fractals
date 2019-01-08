#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <memory>
#include <vector>
#include "colorscheme.h"
#include "pixel.h"

class Histogram : public ColorScheme {
	std::unique_ptr<int[]> _histogram;
	void fillHistogram (int width, int height, std::vector<Pixel> pixels);
	public:
	Histogram ( uint maxIterations );
	void color ( int width, int height, std::vector<Pixel> pixels ) override;
};

#endif // HISTOGRAM_H

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
	std::vector<ColorRange> _colorRanges; //Ranges of colors. Range is defined as fraction of total iterations
	int _maxIterations{0};
	void fillHistogram (int width, int height, std::vector<Pixel> pixels);
	public:
	Histogram ( uint maxIterations );
	void color (int width, int height, std::vector<Pixel> &pixels ) override;
	void addColorRange (ColorRange colorRange );
	int countTotalIterations ();
	protected:
	void calculateRangeTotals ();
	private:
	std::vector<ColorRange>::iterator getRange( Pixel &pixel );
};

#endif // HISTOGRAM_H

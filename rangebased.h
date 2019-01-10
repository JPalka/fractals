#ifndef RANGEBASED_H
#define RANGEBASED_H

#include <memory>
#include <vector>
#include "colorscheme.h"
#include "pixel.h"
#include "rgb.h"
#include "colorrange.h"

class RangeBased : public ColorScheme {
		std::unique_ptr<int[]> _histogram;
		std::vector<ColorRange> _colorRanges; //Ranges of colors. Range is defined as fraction of total iterations
		int _maxIterations{0};
		void fillHistogram (  int width, int height, std::vector<Pixel> pixels );
	public:
		RangeBased ( uint maxIterations );
		RangeBased ( RangeBased &source );
		void color ( int width, int height, std::vector<Pixel> &pixels ) override;
		void addColorRange ( ColorRange colorRange );
		int countTotalIterations ();
		ColorScheme *clone ();
	protected:
		void calculateRangeTotals ();
		std::vector<ColorRange>::iterator getRange( Pixel &pixel );
};

#endif // RANGEBASED_H

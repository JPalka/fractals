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
		void calculateRangeTotals ();
		std::vector<ColorRange>::iterator getRange( Pixel &pixel );
		void resetHistogram();
		void resetColorRanges();
	public:
		RangeBased ( uint maxIterations );
		RangeBased ( RangeBased &source );
		void color ( int width, int height, std::vector<Pixel> &pixels ) override;
		void addColorRange ( ColorRange colorRange ) override;
		void removeColorRange ( double range ) override;
		int countTotalIterations ();
		void setMaxIterations ( int maxIterations ) override;
		ColorScheme *clone ();
};

#endif // RANGEBASED_H

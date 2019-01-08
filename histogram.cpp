#include "histogram.h"
#include "assert.h"

void Histogram::fillHistogram ( int width, int height, std::vector<Pixel> pixels ) {
	for ( Pixel pixel: pixels ) {
		_histogram[pixel._iterations]++;
	}
}

Histogram::Histogram ( uint maxIterations ) : _histogram ( new int[maxIterations]{0} ) {
	assert ( _histogram[1] == 0 );
}

void Histogram::color ( int width, int height, std::vector<Pixel> pixels ) {
	fillHistogram ( width, height, pixels );

}

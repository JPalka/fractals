#include "histogram.h"
#include "assert.h"

#include <iostream>
#include <algorithm>
#include <math.h>

void Histogram::fillHistogram ( int width, int height, std::vector<Pixel> pixels ) {
	width = height;
	height = width; //Usunąć to pózniej, dałem tylko żeby kompilator mordy nie darł
	for ( Pixel pixel: pixels ) {
		_histogram[pixel._iterations]++;
	}
	std::cout << width << "\n";
}

Histogram::Histogram ( uint maxIterations ) : _histogram ( new int[maxIterations + 1]{0} )
, _maxIterations ( maxIterations ) {
	addColorRange ( ColorRange ( 0.0, RGB ( 0, 0, 255 ) ) );
	addColorRange ( ColorRange ( 0.05, RGB ( 255, 99, 71 ) ) );
	addColorRange ( ColorRange ( 0.08, RGB ( 255, 215, 0 ) ) );
	addColorRange ( ColorRange ( 1.0, RGB ( 255, 255, 255 ) ) );
	//	fractalCreator.addRange ( 0.0, RGB ( 0, 0, 255 ) );
	//	fractalCreator.addRange ( 0.05, RGB ( 255, 99, 71 ) );
	//	fractalCreator.addRange ( 0.08, RGB ( 255, 215, 0 ) );
	//	fractalCreator.addRange ( 1.0, RGB ( 255, 255, 255 ) );
	assert ( _histogram[1] == 0 );
}

void Histogram::color ( int width, int height, std::vector<Pixel> &pixels ) {
	fillHistogram ( width, height, pixels );
//	int totalIterations = countTotalIterations ();
	calculateRangeTotals ();
//	testRanges (width, height, pixels);
	for ( int i = 0; i < width; i++ ) {
		for ( int j = 0; j < height; j++ ) {
			int iterations = pixels[j * width + i]._iterations;
			std::vector<ColorRange>::iterator range = getRange ( pixels[j * width + i] );
			RGB startColor = range->_color; //startowy kolor to kolor określony w zakresie w którym jest pixel
			RGB endColor = ( range + 1 )->_color; //końcowy kolor to kolor określony w zakresie zaraz po tym w którym jest pixel
			RGB colorDiff = endColor - startColor;

			std::uint8_t red{0};
			std::uint8_t green{0};
			std::uint8_t blue{0};
			if ( iterations != _maxIterations ) {
				int totalPixels = 0;
				for ( int iter = range->getRange () * _maxIterations; iter <= iterations; iter++ ) {
					totalPixels += _histogram[iter];
				}
				red = startColor._r + colorDiff._r * (double) totalPixels / range->_pixelCount;
				green = startColor._g + colorDiff._g * (double) totalPixels / range->_pixelCount;
				blue = startColor._b + colorDiff._b * (double) totalPixels / range->_pixelCount;
			}

			RGB color = RGB ( red, green, blue );
			pixels[j * width + i].setColor ( color );

			//			_bitmap.setPixel ( i, j, red, green, blue);
		}
	}

}
int Histogram::countTotalIterations ( ) {
	int total = 0;
	for ( int i = 0; i < _maxIterations; i++ ) {
		total += _histogram[i];
	}
	return total;
}

void Histogram::addColorRange ( ColorRange colorRange ) {
	_colorRanges.push_back ( colorRange );
	std::sort ( _colorRanges.begin (), _colorRanges.end () );
}
//1000 * 0,5 = 500

// Get iterator to coloring range a specific pixel is in
std::vector<ColorRange>::iterator Histogram::getRange ( Pixel &pixel ) {
	for ( auto it = _colorRanges.begin (); it < _colorRanges.end (); it++ ) {
		double rangeMaxIteration = (it+1)->getRange () * _maxIterations;
		if ( pixel._iterations <= rangeMaxIteration ) {
			return it;
		}
	}
	throw "Pixel doesnt fit into any range. UNACCEPTABLE";
}
void Histogram::testRanges ( int width, int height, std::vector<Pixel> &pixels ) {
	//test histogram
	int totalPixels = 0;
	for ( int i = 1; i <= _maxIterations; i++ ) {
		totalPixels += _histogram[i];
	}
	assert ( totalPixels == pixels.size () );


	for ( int x = 0; x < width; x++ ) {
		for ( int y = 0; y < height; y++ ) {
			std::cout << getRange ( pixels[y * width + 1] )->getRange ()<< "\n"
			<< getRange ( pixels[y * width + 1] )->_pixelCount;
		}
	}
	std::cout << std::endl;
}

// Oblicza ile pixeli jest w zakresach kolorów
void Histogram::calculateRangeTotals ( ) {
	auto rangeIterator = _colorRanges.begin ();
	for ( int i = 0; i <= _maxIterations; i++ ) {
		int pixels = _histogram[i];
		if ( i > ( rangeIterator + 1 )->getRange () * _maxIterations ) {
			rangeIterator++;
		}
		rangeIterator->_pixelCount += pixels;
	}
}




#include "histogram.h"
#include "assert.h"

#include <iostream>
#include <algorithm>
#include <math.h>

Histogram::Histogram ( uint maxIterations, RGB color ) : _histogram ( new int[maxIterations + 1]{0} )
, _maxIterations ( maxIterations )
, _color ( color ) {
}

Histogram::Histogram ( Histogram &source ) {
//	std::cout << "Histogram copy constructor";
	_color = source._color;
	_maxIterations = source._maxIterations;
	_histogram = std::unique_ptr<int[]> ( new int[_maxIterations + 1]{0} );
}

void Histogram::setMaxIterations ( int maxIterations ) {
	_maxIterations = maxIterations;
	_histogram = std::unique_ptr<int[]> ( new int[maxIterations+1]{0} );
}

Histogram::~Histogram () {
//	std::cout << "Histogram destructor\n";
}

void Histogram::setColor( RGB color ) {
	_color = color;
	std::cout << "Set color\n";
}

void Histogram::fillHistogram ( int width, int height, std::vector<Pixel> pixels ) {
	width = height;
	height = width; //Usunąć to pózniej, dałem tylko żeby kompilator mordy nie darł
	for ( Pixel pixel: pixels ) {
		_histogram[pixel._iterations]++;
	}
	std::cout << "Filled histogram with iterations" << "\n";
}

void Histogram::color ( int width, int height, std::vector<Pixel> &pixels ) {
	fillHistogram ( width, height, pixels );
	int total = countTotalIterations ();
	int calculatedProgress = 0;
	int totalProgress = width * height;
	for ( int i = 0; i < width; i++ ) {
		for ( int j = 0; j < height; j++ ) {
			int iterations = pixels[j * width + i]._iterations;
			double red{0};
			double green{0};
			double blue{0};
			if ( iterations != _maxIterations ) {
				double hue = 0;
				for ( int iter = 0; iter < iterations; iter++ ) {
					hue += _histogram[iter];
				}
				hue /= total;
				red = _color._r * hue;
				green = _color._g * hue;
				blue = _color._b * hue;
			}
			RGB color = RGB ( red, green, blue );
			pixels[j * width + i].setColor ( color );
			calculatedProgress++;
			if ( calculatedProgress % ( ( width * height ) / 100 ) == 0 || calculatedProgress == total ) {
				ColorScheme::printProgress ( ( (double)calculatedProgress / totalProgress ) * 100 );
			}
		}
	}
	std::cout << " - done\n";
}

Histogram *Histogram::clone()
{
	return new Histogram ( *this );
}

int Histogram::countTotalIterations ( ) {
	int total = 0;
	for ( int i = 0; i < _maxIterations; i++ ) {
		total += _histogram[i];
	}
	return total;
}


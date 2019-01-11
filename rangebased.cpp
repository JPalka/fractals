#include "rangebased.h"
#include "assert.h"

#include <iostream>
#include <algorithm>
#include <math.h>

void RangeBased::fillHistogram ( int width, int height, std::vector<Pixel> pixels ) {
	width = height;
	height = width; //Usunąć to pózniej, dałem tylko żeby kompilator mordy nie darł
	for ( Pixel pixel: pixels ) {
		_histogram[pixel._iterations]++;
	}
}

RangeBased::RangeBased ( uint maxIterations ) : _histogram ( new int[maxIterations + 1]{0} )
, _maxIterations ( maxIterations ) {
	addColorRange ( ColorRange ( 0.0, RGB ( 0, 0, 255 ) ) );
	addColorRange ( ColorRange ( 0.05, RGB ( 255, 99, 71 ) ) );
	addColorRange ( ColorRange ( 0.08, RGB ( 255, 215, 0 ) ) );
	addColorRange ( ColorRange ( 1.0, RGB ( 255, 255, 255 ) ) );
}

RangeBased::RangeBased ( RangeBased &source ) {
//	std::cout << "RangeBased copy constructor";
	_maxIterations = source._maxIterations;
	_histogram = std::unique_ptr<int[]> ( new int[_maxIterations + 1]{0} ); //Póki co nie kopiuje histogramu
	_colorRanges = source._colorRanges;
}
/* Ten rodzaj ustawiania kolorów zmienia kolory w zależności od max iteracji gdyżpo zmiana max iteracji zmienia
 * zakresy kolorów podane jako % max iteracji. ColorRange ( 0.5, RGB() ) przy maxIterations=1000 wychodzi 500
 * a przy maxIterations=10000 już 5000. Zmienia sie przez to ilość pixeli w zakresach a ta jest używana w
 * obliczania koloru. Fix?
 * */
void RangeBased::color ( int width, int height, std::vector<Pixel> &pixels ) {
	resetHistogram ();
	fillHistogram ( width, height, pixels );
	calculateRangeTotals ();
	// DEBUG. Printuje zakresy pixeli
	for ( auto range: _colorRanges ) {
		std::cout << range._range << " " << range._pixelCount << " " << range._color._r << "\\" << range._color._g << "\\" << range._color._b << std::endl;
	}
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
			if ( iterations == 50 ) {
//				color._r = 255; color._g = 255; color._b = 255;
			}
			pixels[j * width + i].setColor ( color );
		}
	}

}
int RangeBased::countTotalIterations ( ) {
	int total = 0;
	for ( int i = 0; i < _maxIterations; i++ ) {
		total += _histogram[i];
	}
	return total;
}

void RangeBased::setMaxIterations ( int maxIterations ) {
	_maxIterations = maxIterations;
	_histogram = std::unique_ptr<int[]> ( new int[maxIterations+1] );
	resetHistogram ();
}

ColorScheme *RangeBased::clone () {
	return new RangeBased ( *this );
}

void RangeBased::resetHistogram () {
	//Zeruje histogram
	for ( int d = 0; d < _maxIterations; d++ ) {
		_histogram[d] = 0;
	}
}

void RangeBased::addColorRange ( ColorRange colorRange ) {
	//Zeruje ilość pixeli w każdym zakresie. Te mogą sie nawarstwiać jeśli kolorowano pixele między zmianami
	for ( uint d = 0; d < _colorRanges.size (); d++ ) {
		_colorRanges[d]._pixelCount = 0;
	}
	//Szuka takiego samego zakresu jaki chce sie dodać, usuwa go i dodaje nowy. TODO: zrobić to mniej kulawo
	for ( auto it = _colorRanges.begin (); it < _colorRanges.end (); it++ ) {
		if ( it->getRange () == colorRange.getRange () ) {
			_colorRanges.erase ( it );
			break; // jak juz znaleziono cos do usuniecia to sio.
		}
	}
	_colorRanges.push_back ( colorRange );
	std::sort ( _colorRanges.begin (), _colorRanges.end () );
	_colorRanges.shrink_to_fit ();
}

void RangeBased::removeColorRange ( double range ) {
	if ( range == 0 || range == 1 ) { //Nie ma usuwania pierwszego i ostatniego zakresu i już.
		return;
	}
	for ( auto it = _colorRanges.begin (); it < _colorRanges.end (); it++ ) {
		if ( it->getRange () == range ) {
			_colorRanges.erase ( it );
		}
	}
}

// Zwraca iterator do zakresu w którym znajduje sie pixel.
// jak pixel nie lezy w zadnym zakresie (jest na max iteracjach) to zwraca pierwszy zakres
std::vector<ColorRange>::iterator RangeBased::getRange ( Pixel &pixel ) {
	std::vector<ColorRange>::iterator range = _colorRanges.begin ();
	for ( auto it = _colorRanges.begin (); it < _colorRanges.end (); it++ ) {
		double rangeMaxIteration = (it)->getRange () * _maxIterations;
		if ( rangeMaxIteration > pixel._iterations ) {
			break;
		}
		range = it;
	}
	return range;
//	return _colorRanges.end (); // Zwraca end iterator jak pixel nie jest w żadnym zakresie
	//TODO: poprawić tak żeby Piksel zawsze był w jakimś zakresie
//	throw "Pixel doesnt fit into any range. UNACCEPTABLE";
}

// Oblicza ile pixeli jest w zakresach kolorów
void RangeBased::calculateRangeTotals ( ) {
	auto rangeIterator = _colorRanges.begin ();
	for ( int i = 0; i <= _maxIterations; i++ ) {
		int pixels = _histogram[i];
		if ( i >= ( rangeIterator + 1 )->getRange () * _maxIterations ) {
			rangeIterator++;
		}
		rangeIterator->_pixelCount += pixels;
	}
}

#include "fractalcreator.h"
#include "mandelbrot.h"
#include <iostream>

// TODO: Make Fractal creator create various fractals and remove madelbrot include

FractalCreator::FractalCreator ( int width, int height ) :
_width ( width ), _height ( height )
,	_zoomList ( ZoomList ( width, height ) )
, _histogram ( new int[Mandelbrot::MAX_ITERATIONS]{0} )
,	_fractal ( new int[width * height]{0} )
, _bitmap ( Bitmap ( width, height ) ) {
	this->addZoom ( Zoom( width / 2, height / 2, 4.0 / width ) );
}

void FractalCreator::run ( std::string filename ) {
	this->calculateIteration ();
	this->countIterations ();
	this->drawFractal ();
	this->writeBitmap ( filename );
}

void FractalCreator::addZoom ( const Zoom &zoom ) {
	_zoomList.add ( zoom );
}

void FractalCreator::calculateIteration ( ) {
	for ( int i = 0; i < _width; i++ ) {
		for ( int j = 0; j < _height; j++ ) {
			std::pair <double, double> coords = _zoomList.doZoom (i, j);
			int iterations = Mandelbrot::getIterations ( coords.first, coords.second );
			_fractal[j * _width + i] = iterations;
			if ( iterations != Mandelbrot::MAX_ITERATIONS ) {
				_histogram[iterations]++;
			}
//			std::uint8_t color = static_cast<std::uint8_t> ( 256 * static_cast<double> ( iterations ) / Mandelbrot::MAX_ITERATIONS );

//			color = color * color * color;

//			bitmap.setPixel ( i, j, 0, color, 0);
//			if ( color < min ) {
//				min = color;
//			}
//			if ( color > max ) {
//				max = color;
//			}
		}
	}
}

void FractalCreator::drawFractal ( ) {
	RGB startColor (0, 0, 20);
	RGB endColor ( 255, 128, 74 );
	RGB colorDiff = endColor - startColor;

	for ( int i = 0; i < _width; i++ ) {
		for ( int j = 0; j < _height; j++ ) {
			std::uint8_t red{0};
			std::uint8_t green{0};
			std::uint8_t blue{0};
			int iterations = _fractal[j * _width + i];
			if ( iterations != Mandelbrot::MAX_ITERATIONS ) {
//			std::uint8_t color = static_cast<std::uint8_t> ( 256 * static_cast<double> ( iterations ) / Mandelbrot::MAX_ITERATIONS );
				double hue = 0;
				for ( int i = 0; i <= iterations; i++ ) {
					hue += static_cast<double> ( _histogram[i] ) / _totalIterations;
				}

				red = startColor._r + colorDiff._r * hue;
				green = startColor._g + colorDiff._g * hue;
				blue = startColor._b + colorDiff._b * hue;
				// Less glowy
				// green = pow ( 255, hue );
				// More glowy fancy look
				// green = hue * 255;
			}
//			std::cout << red << "/" << green << "/" << blue << " ";
			_bitmap.setPixel ( i, j, red, green, blue);
//			if ( color < min ) {
//				min = color;
//			}
//			if ( color > max ) {
//				max = color;
//			}
		}
	}
}

void FractalCreator::writeBitmap ( std::string filename ) {
	_bitmap.write ( filename );
}

void FractalCreator::countIterations () {
	// Counting total iterations. needed for coloring pixels.
	for ( int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++ ) {
		_totalIterations += _histogram[i];
	}
}



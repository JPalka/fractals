#include "fractal.h"

#include <iostream>

Fractal::Fractal () : _width ( 600 )
, _height ( 600 )
,	_fractal ( _width * _height, Pixel( RGB (0, 0, 0) ) )
, _outputFile ( Bitmap ( _width, _height ) ) {
	_zoomList.add ( Zoom ( _width / 2, _height / 2, 4.0 / _width ) );
}

void Fractal::addZoom ( Zoom zoom ) {
	_zoomList.add ( zoom );
}

void Fractal::colorFractal()
{
//	int i = 0;
	_coloringMethod->color ( _width, _height, _fractal );
	std::cout << "Finished coloring fractal\n";
}

void Fractal::save()
{
	_outputFile.write ( _fractalName + ".bmp", _fractal );
}

//Zmiana rozmiarów obrazu wymusza stworzenie od nowa wektora pikseli i listy zoomów
void Fractal::setDimensions ( int width, int height ) {
	_width = width;
	_height = height;
	_fractal = std::vector<Pixel>( _width * _height, Pixel() );
	_zoomList = ZoomList( width, height);
	_zoomList.add ( Zoom ( _width / 2, _height / 2, 4.0 / _width ) );
	_outputFile.setDimensions ( _width, _height );
}


void Fractal::calculateFractal () {
	for ( uint x = 0; x < _width; x++ ) {
		for ( uint y = 0; y < _height; y++ ) {
			std::pair <double, double> coords = _zoomList.doZoom (x, y);
			int iterations = this->getIterations ( coords.first, coords.second );
			_fractal[y * _width + x]._iterations = iterations;
		}
	}
	std::cout << "Calculated fractal\n";
}

void Fractal::setMaxIterations ( int iterations ) {
	_maxIterations = iterations;
}

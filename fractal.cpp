#include "fractal.h"

Fractal::Fractal () : _width ( 600 )
, _height ( 600 )
,	_fractal ( _width * _height, Pixel() )
, _outputFile ( Bitmap ( _width, _height ) ) {
	_zoomList.add ( Zoom ( _width / 2, _height / 2, 4.0 / _width ) );
}

void Fractal::addZoom ( Zoom zoom ) {
	_zoomList.add ( zoom );
}

void Fractal::colorFractal()
{
	_coloringMethod->color ( _width, _height, _fractal );
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

#include "fractal.h"

Fractal::Fractal ( ) : _width ( 600 )
, _height ( 600 )
,	_fractal ( _width * _height, Pixel() )
, _outputFile ( Bitmap ( _width, _height ) ) {

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

}

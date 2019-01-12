#include "fractal.h"

#include <iostream>

Fractal::Fractal () : _width ( 600 )
, _height ( 600 )
,	_fractal ( _width * _height, Pixel( RGB (0, 0, 0) ) )
, _outputFile ( Bitmap ( _width, _height ) ) {
	_zoomList.add ( Zoom ( _width / 2, _height / 2, 4.0 / _width ) );
}

void Fractal::printMessage( std::string message ) {
	std::cout << message << std::endl;
}

void Fractal::addZoom ( Zoom zoom ) {
	_zoomList.add ( zoom );
}

ColorScheme &Fractal::getColorScheme ( ) {
	return *_coloringMethod;
}

void Fractal::colorFractal() {
//	int i = 0;
	std::cout << "Coloring fractal...\n";
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
	_zoomList = ZoomList( width, height );
	_zoomList.add ( Zoom ( _width / 2, _height / 2, 4.0 / _width ) );
	_outputFile.setDimensions ( _width, _height );
}
//Przeskalowuje koordynaty pixela do zakresu (-1,1)
void Fractal::scalePixelCoordinates ( Pixel &pixel, int x, int y ) {
	std::pair <double, double> scaledCoords = _zoomList.doZoom (x, y);
	pixel._scaledX = scaledCoords.first;
	pixel._scaledY = scaledCoords.second;
}

void Fractal::calculateFractal () {
	std::cout << "Calculating fractal..." << std::endl;
	int total = _width * _height;
	int calculated = 0;
	for ( uint x = 0; x < _width; x++ ) {
		for ( uint y = 0; y < _height; y++ ) {
//			std::pair <double, double> coords = _zoomList.doZoom (x, y);
//			int iterations = this->getIterations ( coords.first, coords.second );
//			_fractal[y * _width + x]._iterations = iterations;
			scalePixelCoordinates ( _fractal[y * _width + x], x, y );
			calculatePixelData ( _fractal[y * _width + x] );
			calculated++;
			if ( calculated % ( ( _width * _height ) / 100 ) == 0 || calculated == total ) {
				std::cout << "\r";
				std::cout.fill (0);
				std::cout.width (5);
				std::cout << std::left << std::setprecision (3) << ( (double)calculated / total ) * 100 << "%" << std::flush;
			}
		}
	}
	std::cout.width ();
	std::cout << " - done\n";
}

void Fractal::setMaxIterations ( int iterations ) {
	_maxIterations = iterations;
	_coloringMethod->setMaxIterations ( iterations );
	std::cout << _fractalName << ": " << "Max iterations set to " << iterations << std::endl;
}

void Fractal::setColorScheme ( ColorScheme &colorScheme ) {
	_coloringMethod.release ();
	_coloringMethod = std::unique_ptr<ColorScheme> ( colorScheme.clone () );
	std::cout << _fractalName << ": " << "Coloring method set.";
}

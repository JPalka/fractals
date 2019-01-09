#include "escapefractal.h"

void EscapeFractal::calculateFractal () {
	for ( uint x = 0; x < _width; x++ ) {
		for ( uint y = 0; y < _height; y++ ) {
			std::pair <double, double> coords = _zoomList.doZoom (x, y);
			int iterations = this->getIterations ( coords.first, coords.second );
//			int i = 0;
			_fractal[y * _width + x]._iterations = iterations;

//			if ( iterations != _fractalType->_maxIterations ) {
//				_histogram[iterations]++;
//			}
		}
	}
}

void EscapeFractal::setMaxIterations ( int iterations ) {
	_maxIterations = iterations;
}

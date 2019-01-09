#include <iostream>
#include <vector>

#include "zoomlist.h"
#include "fractalcreator.h"
#include "fractal.h"
#include "newton.h"
#include "histogram.h"

using namespace std;

int main ( int argc, char *argv[] ) {
//	const int WIDTH = 800;
//	const int HEIGHT = 600;
//	int maxIterations = 1000;
	string name {"image.bmp"};
	if ( argc == 2 ) {
		name = argv[1];
	}

//	Fractal *fractal = new Newton ( 10000 );
//	fractal->setDimensions ( 800, 600 );
////	fractal->addZoom ( Zoom ( 400, 300, 0.5 ) );
////	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
//	fractal->calculateFractal ();
//	fractal->colorFractal ();
//	fractal->_fractalName = "Newton1000";
//	fractal->save ();
//	delete fractal;

//	Fractal *fractal = new Mandelbrot ( 1000 );
//	fractal->setDimensions ( 800, 600 );
//	fractal->addZoom ( Zoom ( 295, 202, 0.1 ) );
//	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
//	fractal->calculateFractal ();
//	fractal->colorFractal ();
//	fractal->_fractalName = "MandelbrotRangeTest1000";
//	fractal->save ();
//	delete fractal;

	std::unique_ptr<Histogram> coloring ( new Histogram ( 1000, RGB ( 0, 0, 255 ) ) );

	Fractal *fractal2 = new Mandelbrot( 1000, coloring.get () );
	fractal2->setDimensions ( 800, 600 );
	fractal2->addZoom ( Zoom ( 295, 202, 0.1 ) );
	fractal2->addZoom ( Zoom ( 312, 304, 0.1 ) );
	fractal2->calculateFractal ();
	fractal2->colorFractal ();
	fractal2->_fractalName = "MandelbrotHistoBlue";
	fractal2->save ();
	delete fractal2;

	return 0;
}

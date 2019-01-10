#include <iostream>
#include <vector>

#include "zoomlist.h"
#include "fractal.h"
#include "newton.h"
#include "histogram.h"
#include "mandelbrot.h"
#include "rangebased.h"

using namespace std;

int main ( int argc, char *argv[] ) {
//	const int WIDTH = 800;
//	const int HEIGHT = 600;
//	int maxIterations = 1000;
	string name {"image.bmp"};
	if ( argc == 2 ) {
		name = argv[1];
	}
//	std::unique_ptr<ColorScheme> coloring ( new Histogram ( 1000, RGB ( 0, 0, 255 ) ) );
	Histogram hist ( 1000, RGB ( 255, 255, 255 ) );
	RangeBased range ( 1000 );
	Histogram histBlue ( 1000, RGB ( 0, 0, 255 ) );
//	Fractal *fractal = new Newton ( 1000, coloring.get () );
//	fractal->setDimensions ( 800, 600 );
////	fractal->addZoom ( Zoom ( 400, 300, 0.5 ) );
////	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
//	fractal->calculateFractal ();
//	fractal->colorFractal ();
//	fractal->_fractalName = "NewtonTest";
//	fractal->save ();
	Fractal *fractal = new Mandelbrot ( 1000, hist );
	fractal->setDimensions ( 800, 600 );
	fractal->addZoom ( Zoom ( 295, 202, 0.1 ) );
	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
	fractal->calculateFractal ();
	fractal->colorFractal ();
	fractal->_fractalName = "MandelbrotTestWhite";
	fractal->save ();
	std::cout << "Saved first frac\n";

	fractal->setColorScheme ( range );
	std::cout << "changed color scheme\n";
	fractal->colorFractal ();
	fractal->_fractalName = "MandelbrotTestRange";
	fractal->save ();
	std::cout << "saved second frac\n";
//	delete fractal;

//	fractal = new Julia ( 1000, coloring.get () );
//	fractal->setDimensions ( 800, 600 );
////	fractal->addZoom ( Zoom ( 295, 202, 0.1 ) );
////	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
//	fractal->calculateFractal ();
//	fractal->colorFractal ();
//	fractal->_fractalName = "JuliaTest";
//	fractal->save ();
////	delete fractal;


//	fractal = new Tricorn ( 1000, coloring.get () );
//	fractal->setDimensions ( 800, 600 );
////	fractal->addZoom ( Zoom ( 295, 202, 0.1 ) );
////	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
//	fractal->calculateFractal ();
//	fractal->colorFractal ();
//	fractal->_fractalName = "TricornTest";
//	fractal->save ();

	delete fractal;
	return 0;
}

#include <iostream>
#include <vector>
#include <chrono>

#include "zoomlist.h"
#include "fractal.h"
#include "newton.h"
#include "histogram.h"
#include "mandelbrot.h"
#include "rangebased.h"

using namespace std;
using namespace std::chrono;
int main ( ) {
//	std::unique_ptr<ColorScheme> coloring ( new Histogram ( 1000, RGB ( 0, 0, 255 ) ) );
//	Histogram hist ( 1000, RGB ( 255, 255, 255 ) );
//	Histogram histBlue ( 1000, RGB ( 0, 0, 255 ) );
//	Fractal *fractal = new Newton ( 1000, coloring.get () );
//	fractal->setDimensions ( 800, 600 );
////	fractal->addZoom ( Zoom ( 400, 300, 0.5 ) );
////	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
//	fractal->calculateFractal ();
//	fractal->colorFractal ();
//	fractal->_fractalName = "NewtonTest";
//	fractal->save ();
	RangeBased range ( 100 );
	Histogram hist ( 1000, RGB ( 100, 255, 0 ) );
	Fractal *fractal = new Mandelbrot ( 1000, hist );
//	fractal->getColorScheme().removeColorRange ( 0.05 );
//	fractal->getColorScheme().addColorRange ( ColorRange ( 0.05, RGB ( 100, 100, 100 ) ) );
	fractal->setDimensions ( 800, 600 );
	fractal->addZoom ( Zoom ( 295, 202, 0.1 ) );
	fractal->addZoom ( Zoom ( 312, 304, 0.1 ) );
	auto start = high_resolution_clock::now();
	fractal->calculateFractal ();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	cout << "Calculated fractal in " << duration.count() << " seconds.\n";
	start = high_resolution_clock::now ();
	fractal->colorFractal ();
	stop = high_resolution_clock::now ();
	duration = duration_cast<seconds>(stop - start);
	cout << "Colored fractal in " << duration.count() << " seconds.\n";
	fractal->_fractalName = "TEST10000";
	fractal->save ();
	std::cout << "Saved " << fractal->_fractalName << "\n";
//	fractal->_fractalName = "TEST2000";
////	fractal->setColorScheme ( range );
//	fractal->setMaxIterations ( 2000 );
//	fractal->calculateFractal ();
//	fractal->colorFractal ();
//	fractal->save ();
//	std::cout << "Saved " << fractal->_fractalName << "\n";

//	fractal->setColorScheme ( range );
//	std::cout << "changed color scheme\n";
//	fractal->colorFractal ();
//	fractal->_fractalName = "MandelbrotTestRange";
//	fractal->save ();
//	std::cout << "saved second frac\n";
//	delete fractal;
	delete fractal;
	return 0;
}

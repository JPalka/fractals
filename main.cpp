#include <iostream>
#include <vector>
#include <chrono>

#include "zoomlist.h"
#include "fractal.h"
#include "newton.h"
#include "julia.h"
#include "tricorn.h"
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
	Histogram hist ( 5000, RGB ( 100, 255, 0 ) );
	RangeBased range ( 5000 );
//	Fractal *fractal = new Mandelbrot ( 5000, hist );
	Fractal *fractalArray[4];
	fractalArray[0] = new Mandelbrot ( 5000, hist );
	fractalArray[1] = new Julia ( 5000, hist );
	fractalArray[2] = new Newton ( 5000, hist );
	fractalArray[3] = new Tricorn ( 5000, hist );
	fractalArray[0]->_fractalName = "Mandelbrot5000";
	fractalArray[1]->_fractalName = "Julia5000";
	fractalArray[2]->_fractalName = "Newton5000";
	fractalArray[3]->_fractalName = "Tricorn5000";

	for ( int i = 0; i < 4; i++ ) {
		fractalArray[i]->setDimensions ( 800, 600 );
		auto start = high_resolution_clock::now();
		fractalArray[i]->calculateFractal ();
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<seconds>(stop - start);
		cout << "Calculated fractal in " << duration.count() << " seconds.\n";
		start = high_resolution_clock::now ();
		fractalArray[i]->colorFractal ();
		stop = high_resolution_clock::now ();
		duration = duration_cast<seconds>(stop - start);
		cout << "Colored fractal in " << duration.count() << " seconds.\n";
		fractalArray[i]->save ();
		std::cout << "Saved " << fractalArray[i]->_fractalName << "\n";
	}
	fractalArray[0]->_fractalName = "Mandelbrot5000RangeBased";
	fractalArray[1]->_fractalName = "Julia5000RangeBased";
	fractalArray[2]->_fractalName = "Newton5000RangeBased";
	fractalArray[3]->_fractalName = "Tricorn5000RangeBased";
	for ( int i = 0; i < 4; i++ ) {
		fractalArray[i]->setColorScheme ( range );
		auto start = high_resolution_clock::now ();
		fractalArray[i]->colorFractal ();
		auto stop = high_resolution_clock::now ();
		auto duration = duration_cast<seconds>(stop - start);
		cout << "Colored fractal in " << duration.count() << " seconds.\n";
		fractalArray[i]->save ();
		std::cout << "Saved " << fractalArray[i]->_fractalName << "\n";
	}
	// cleanup
	for ( int v = 0; v < 4; v++ ) {
		delete fractalArray[v];
	}
	return 0;
}

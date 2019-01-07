#include <iostream>
#include <vector>

#include "zoomlist.h"
#include "fractalcreator.h"

using namespace std;

int main ( int argc, char *argv[] ) {
	const int WIDTH = 800;
	const int HEIGHT = 600;
	string name {"image.bmp"};
	if ( argc == 2 ) {
		name = argv[1];
	}
	FractalCreator fractalCreator ( WIDTH, HEIGHT );
	fractalCreator.addRange ( 0.0, RGB ( 0, 0, 0 ) );
	fractalCreator.addRange ( 0.3, RGB ( 255, 0, 0 ) );
	fractalCreator.addRange ( 0.5, RGB ( 0, 255, 0 ) );
	fractalCreator.addRange ( 1.0, RGB ( 255, 255, 255 ) );

	cout << fractalCreator.getRange ( 310 );

	fractalCreator.addZoom ( Zoom( 295, 202, 0.1 ) );
	fractalCreator.addZoom ( Zoom( 312, 304, 0.1 ) ); // Cool

	fractalCreator.run ( name );
//	Validating histogram. Total count of pixels in histogram must be equal to total count of pixels.
//	int pixelCount {0};
//	for ( size_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++ ) {
//		pixelCount += histogram[i];
//	}
//	cout << "Pixel count is " << pixelCount << " and it should be: " << WIDTH * HEIGHT << endl;

	return 0;
}

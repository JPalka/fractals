#include <iostream>

#include "zoomlist.h"
#include "fractalcreator.h"
#include <vector>

using namespace std;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;

	FractalCreator fractalCreator ( WIDTH, HEIGHT );
	fractalCreator.addZoom ( Zoom( 295, HEIGHT - 202, 0.1 ) );
	fractalCreator.addZoom ( Zoom( 312, HEIGHT - 304, 0.1 ) ); // Cool

	fractalCreator.calculateIteration ();
	fractalCreator.countIterations ();
	fractalCreator.drawFractal ();
	fractalCreator.writeBitmap ( "test.bmp" );

//	Validating histogram. Total count of pixels in histogram must be equal to total count of pixels.
//	int pixelCount {0};
//	for ( size_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++ ) {
//		pixelCount += histogram[i];
//	}
//	cout << "Pixel count is " << pixelCount << " and it should be: " << WIDTH * HEIGHT << endl;

	return 0;
}

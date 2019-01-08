#include <iostream>
#include <vector>

#include "zoomlist.h"
#include "fractalcreator.h"
#include "fractal.h"

using namespace std;

int main ( int argc, char *argv[] ) {
	const int WIDTH = 800;
	const int HEIGHT = 600;
	int maxIterations = 1000;
	string name {"image.bmp"};
	if ( argc == 2 ) {
		name = argv[1];
	}

	Fractal *fractal = new Mandelbrot ( 1000 );
	fractal->addZoom ( Zoom ( 200, 200, 0.3 ) );
	fractal->calculateFractal ();

//	FractalCreator fractalCreator ( WIDTH, HEIGHT, new Julia ( maxIterations ) );
//	fractalCreator.addRange ( 0.0, RGB ( 0, 0, 255 ) );
//	fractalCreator.addRange ( 0.05, RGB ( 255, 99, 71 ) );
//	fractalCreator.addRange ( 0.08, RGB ( 255, 215, 0 ) );
//	fractalCreator.addRange ( 1.0, RGB ( 255, 255, 255 ) );

//	fractalCreator.addZoom ( Zoom( 400, 300, 0.3 ) );
////	fractalCreator.addZoom ( Zoom( 295, 202, 0.1 ) ); // 2 dobre zoomy z mandelbrot
////	fractalCreator.addZoom ( Zoom( 312, 304, 0.1 ) ); // Cool

//	fractalCreator.run ( name );

	return 0;
}

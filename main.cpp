#include <iostream>
#include <cstdint>

#include "bitmap.h"
#include "mandelbrot.h"

using namespace std;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 99999999;
	double max = -99999999;

//	bitmap.setPixel ( WIDTH / 2, HEIGHT / 2, 255, 255, 255 );
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double xFractal = ( i - WIDTH / 2 ) * ( 2.0 / WIDTH );
			double yFractal = ( j - HEIGHT / 2 ) * ( 2.0 / HEIGHT );

			int iterations = Mandelbrot::getIterations ( xFractal, yFractal );
			std::uint8_t red = static_cast<std::uint8_t> ( 256 * static_cast<double> ( iterations ) / Mandelbrot::MAX_ITERATIONS );
			bitmap.setPixel ( i, j, red, red, red);
			if ( red < min ) {
				min = red;
			}
			if ( red > max ) {
				max = red;
			}
		}
	}
	cout << min << ", " << max << endl;
	if ( !bitmap.write ("image.bmp") ) {
		cout << "Cant write to file" << endl;
	}
	else {
		cout << "Wrote to file." << endl;
	}


	return 0;
}

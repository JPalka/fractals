#include <iostream>
#include <cstdint>
#include <memory>
#include "bitmap.h"
#include "mandelbrot.h"
#include <vector>

using namespace std;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);


	double min = 99999999;
	double max = -99999999;

	std::unique_ptr<int[]> histogram ( new int[Mandelbrot::MAX_ITERATIONS]{0} ); // Too small for last element to fit. last element is count of pixels that exceed max iterations.
	std::unique_ptr<int[]> fractal ( new int[WIDTH * HEIGHT]{0} );
//	std::vector<int> fractal ( WIDTH * HEIGHT, 0 );
//	std::vector<int> histogram ( Mandelbrot::MAX_ITERATIONS, 0 );
//	bitmap.setPixel ( WIDTH / 2, HEIGHT / 2, 255, 255, 255 );
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			double xFractal = ( i - WIDTH / 2 - 200) * ( 2.0 / HEIGHT );
			double yFractal = ( j - HEIGHT / 2 ) * ( 2.0 / HEIGHT );
			int iterations = Mandelbrot::getIterations ( xFractal, yFractal );
			fractal[j * WIDTH + i] = iterations;
			if ( iterations != Mandelbrot::MAX_ITERATIONS ) {
				histogram[iterations]++;
			}
//			std::uint8_t color = static_cast<std::uint8_t> ( 256 * static_cast<double> ( iterations ) / Mandelbrot::MAX_ITERATIONS );

//			color = color * color * color;

//			bitmap.setPixel ( i, j, 0, color, 0);
//			if ( color < min ) {
//				min = color;
//			}
//			if ( color > max ) {
//				max = color;
//			}
		}
	}
	int total = 0;
	// Counting total iterations
	for ( int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++ ) {
		total += histogram[i];
	}
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			int iterations = fractal[j * WIDTH + i];

			std::uint8_t color = static_cast<std::uint8_t> ( 256 * static_cast<double> ( iterations ) / Mandelbrot::MAX_ITERATIONS );
			double hue = 0;
			for ( int i = 0; i <= iterations; i++ ) {
				hue += static_cast<double> ( histogram[i] ) / total;
			}
			std::uint8_t red{0};
			std::uint8_t green{0};
			std::uint8_t blue{0};

			green = hue * 255;

			bitmap.setPixel ( i, j, red, green, blue);
			if ( color < min ) {
				min = color;
			}
			if ( color > max ) {
				max = color;
			}
		}
	}

	cout << min << ", " << max << endl;
	if ( !bitmap.write ("image.bmp") ) {
		cout << "Can not write to file" << endl;
	}
	else {
		cout << "Wrote to file." << endl;
	}


//	Validating histogram. Total count of pixels in histogram must be equal to total count of pixels.
//	int pixelCount {0};
//	for ( size_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++ ) {
//		pixelCount += histogram[i];
//	}
//	cout << "Pixel count is " << pixelCount << " and it should be: " << WIDTH * HEIGHT << endl;

	return 0;
}

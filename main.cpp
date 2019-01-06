#include <iostream>

#include "bitmap.h"

using namespace std;

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);

//	bitmap.setPixel ( WIDTH / 2, HEIGHT / 2, 255, 255, 255 );
	for ( int i = 0; i < WIDTH; i++ ) {
		for ( int j = 0; j < HEIGHT; j++ ) {
			bitmap.setPixel ( i, j, 255, 0, 0);
		}
	}

	if ( !bitmap.write ("image.bmp") ) {
		cout << "Cant write to file" << endl;
	}
	else {
		cout << "Wrote to file." << endl;
	}


	return 0;
}

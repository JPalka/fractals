#include <iostream>

#include "bitmap.h"

using namespace std;

int main()
{
	Bitmap bitmap(800, 600);
	if ( !bitmap.write ("czorne.bmp") ) {
		cout << "Cant write to file" << endl;
	}
	else {
		cout << "Wrote to file." << endl;
	}

	return 0;
}

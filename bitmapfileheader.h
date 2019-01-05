#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H
#include <cstdint>

struct BitmapFileHeader {
	char header[2]{'B', 'M'};
	int fileSize;
};


#endif // BITMAPFILEHEADER_H

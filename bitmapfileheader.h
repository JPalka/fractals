#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H
#include <cstdint>

#pragma pack(2)
struct BitmapFileHeader {
	char header[2]{'B', 'M'};
	std::int32_t fileSize; //File size
	std::int32_t reserved{0};
	std::int32_t dataOffset; //How long into the file data begins
};


#endif // BITMAPFILEHEADER_H

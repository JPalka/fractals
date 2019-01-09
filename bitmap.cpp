#include <fstream>
#include <iostream>
#include "bitmap.h"
#include "bitmapinfoheader.h"
#include "bitmapfileheader.h"
#include "pixel.h"

Bitmap::Bitmap ( int width, int height ) : _width(width), _height(height)
, _pPixels(new std::uint8_t[width*height*3]{0}) {

} //Specify "new" behaviour to throw exceptions

void Bitmap::setDimensions ( int width, int height ) {
	_width = width;
	_height = height;
	// Trzeba od nowa tablice pikseli bitmapy stworzyć;
	_pPixels = std::unique_ptr<std::uint8_t[]> ( new std::uint8_t[_width * _height * 3] );
}


// TODO: poprawić to tak żeby działało z różnymi rodzajami zapisywania kolorów
void Bitmap::convertPixels ( std::vector<Pixel> &input ) {
	uint position = 0;
	for ( Pixel &pixel: input ) {
		_pPixels[position] = pixel._color._b;
		position++;
		_pPixels[position] = pixel._color._g;
		position++;
		_pPixels[position] = pixel._color._r;
		position++;
	}
}

bool Bitmap::write ( std::string filename, std::vector<Pixel> &pixels ) {

	convertPixels ( pixels );

	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	fileHeader.fileSize = sizeof ( BitmapFileHeader ) + sizeof ( BitmapInfoHeader ) + _width * _height * 3;
	fileHeader.dataOffset = sizeof ( BitmapFileHeader ) + sizeof ( BitmapInfoHeader );
	infoHeader.width = _width;
	infoHeader.height = _height;
	std::ofstream file;
	file.open ( filename, std::ios::out|std::ios::binary );
	if ( !file ) {
		throw "wysrało sie";
		std::cout << "Cannot create/open file";
		return false;
	}
	file.write ( reinterpret_cast<char *> ( &fileHeader ), sizeof ( fileHeader ) );
	file.write ( reinterpret_cast<char *> ( &infoHeader ), sizeof ( infoHeader ) );
	file.write ( reinterpret_cast<char *> ( _pPixels.get () ), _width * _height * 3 );
	file.close ();
	if ( !file ) {
		std::cout << "Cannot close/write to file";
		return false;
	}
	return true;
}

void Bitmap::setPixel ( int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue ) {
	std::uint8_t *pPixel = _pPixels.get ();
	pPixel += ( y * 3 ) * _width + x * 3;
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red; //Reverse because Bitmap is little endian format
}

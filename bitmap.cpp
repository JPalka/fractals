#include <fstream>
#include <iostream>
#include "bitmap.h"
#include "bitmapinfoheader.h"
#include "bitmapfileheader.h"


Bitmap::Bitmap ( int width, int height ) : _width(width), _height(height), _pPixels(new std::uint8_t[width*height*3]{0}) {

} //Specify "new" behaviour to throw exceptions

bool Bitmap::write ( std::string filename ) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	fileHeader.fileSize = sizeof ( BitmapFileHeader ) + sizeof ( BitmapInfoHeader ) + _width * _height * 3;
	fileHeader.dataOffset = sizeof ( BitmapFileHeader ) + sizeof ( BitmapInfoHeader );
	infoHeader.width = _width;
	infoHeader.height = _height;
	std::ofstream file;
	file.open ( filename, std::ios::out|std::ios::binary );
	if ( !file ) {
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

}

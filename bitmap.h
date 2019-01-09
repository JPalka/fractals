#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>
#include <vector>

#include "pixel.h"

class Bitmap {
	private:
		int _width{0};
		int _height{0};
		std::string _fileName;
		std::unique_ptr<std::uint8_t[]> _pPixels{nullptr}; // Pixele w formacie bitmapy
		// Konwertuje tablice Pixeli na format bitmapy
		void convertPixels (std::vector<Pixel> &input );
	public:
		Bitmap ( int width = 600, int height = 600 );
		bool write (std::string filename , std::vector<Pixel> &pixels);
		void setPixel ( int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue );
		void setDimensions ( int width, int height );
};

#endif // BITMAP_H

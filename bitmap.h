#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

class Bitmap {
	private:
		int _width{0};
		int _height{0};
		std::unique_ptr<std::uint8_t[]> _pPixels{nullptr};
	public:
		Bitmap ( int width, int height );
		bool write ( std::string filename );
		void setPixel ( int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue );
};

#endif // BITMAP_H

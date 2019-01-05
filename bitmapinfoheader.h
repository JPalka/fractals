#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H
#include <cstdint>

#pragma pack(2)
struct BitmapInfoHeader {
	std::int32_t headerSize{40};
	std::int32_t width{0};
	std::int32_t height{0};
	std::int16_t planes{1};
	std::int16_t bitsPerPixel{24};
	std::int32_t compression{0};
	std::int32_t dataSize{0};
	std::int32_t horizontalResolution{2400};
	std::int32_t verticalResolution{2400};
	std::int32_t colors{0};
	std::int32_t importantColors{0};
};

#endif // BITMAPINFOHEADER_H

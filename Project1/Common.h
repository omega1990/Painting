#pragma once
#include <memory>
#include <vector>

typedef unsigned int uint;

static const uint MAX_WIDTH = 1900;
static const uint MAX_HEIGHT = 1200;

static const uint NUMBER_OF_THREADS = 6;


class Pixel;
class PhotoObject;

using PixelMatrix = std::vector<std::vector<Pixel>>;
using PixelMatrix_s = std::shared_ptr<std::vector<std::vector<Pixel>>>;

class PhotoObject
{
public:
	PhotoObject()
	{

	}

	PhotoObject(uint aHeight, uint aWidth, PixelMatrix_s aPixelMatrix)
	{
		height = aHeight;
		width = aWidth;
		pixels = aPixelMatrix;
	}

	uint height;
	uint width;
	PixelMatrix_s pixels;

};

class Pixel
{
public:
	Pixel(unsigned int aX, unsigned int aY, unsigned char aR, unsigned char aG, unsigned char aB)
		: x(aX)
		, y(aY)
		, R(aR)
		, G(aG)
		, B(aB)
	{

	}

	unsigned int x;
	unsigned int y;
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

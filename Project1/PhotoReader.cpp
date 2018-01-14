#include "PhotoReader.h"



PhotoReader::PhotoReader()
{	
}

PhotoReader::~PhotoReader()
{
}

std::shared_ptr<PhotoObject>
PhotoReader::ReadBMP(
	char* filename)
{
	FILE* f;
	fopen_s(&f, filename, "rb");

	if (f == NULL)
	{
		throw "Argument Exception";
	}

	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	const unsigned int width = *(int*)&info[18];
	const unsigned int height = *(int*)&info[22];

	const int row_padded = (width * 3 + 3) & (~3);
	unsigned char* data = new unsigned char[row_padded];
	unsigned char tmp;

	PixelMatrix pixels;

	for (unsigned int i = 0; i < height; i++)
	{
		fread(data, sizeof(unsigned char), row_padded, f);
		std::vector<Pixel> row;
		for (unsigned int j = 0; j < row_padded; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;		

			unsigned int x = int(j / 3);
			Pixel pixel(i, x, data[j], data[j + 1], data[j + 2]);
			row.push_back(pixel);
		}
		
		pixels.insert(pixels.begin(), row);		
	}

	PhotoObject photo(height, width, std::make_shared <PixelMatrix>(pixels));

	fclose(f);
	delete data;

	return std::make_shared<PhotoObject>(photo);
}

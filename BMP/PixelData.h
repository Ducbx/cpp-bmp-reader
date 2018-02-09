#pragma once

#include "RGB.h"

class PixelData
{
private:
	int width;
	int height;
	my::RGB** pixelMatrix;
public:
	PixelData();
	~PixelData();
	void parseRawData(char* rawData, int width, int height, wchar_t depth);
	my::RGB** getPixelMatrix();
};


#include "PixelData.h"

#include<iostream>

using namespace std;

PixelData::PixelData()
{
}

void PixelData::parseRawData(char* rawData, int width, int height, wchar_t depth)
{

	pixelMatrix = new my::RGB*[height];
	for (int i = 0; i < height; i++) {
		pixelMatrix[i] = new my::RGB[width];
	}

	int padding = 4 - ((width * 3) % 4);
	int offset = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			pixelMatrix[height - i - 1][j].b = (unsigned char)rawData[offset + 0];
			pixelMatrix[height - i - 1][j].g = (unsigned char)rawData[offset + 1];
			pixelMatrix[height - i - 1][j].r = (unsigned char)rawData[offset + 2];

			offset += 3;

		}

		offset += padding;

	}

}


PixelData::~PixelData()
{

	for (int i = 0; i < height; i++) {
		delete pixelMatrix[i];
	}
	delete[] pixelMatrix;

}

my::RGB** PixelData::getPixelMatrix() {
	return pixelMatrix;
}

#include "BMP.h"

#include<fstream>
#include "FileHeader.h"
#include "ImageHeader.h"
#include "PixelData.h"

BMP::BMP()
{
}


BMP::~BMP()
{
}

bool BMP::load(string filename)
{

	// open file
	ifstream input(filename, ios::binary);

	// check if valid BMP file
	char BM[2];
	input.read(BM, 2);
	if (!(BM[0] == 'B' && BM[1] == 'M')) {
		input.close();
		return false;
	}
	input.seekg(0, ios::beg);

	// read headers
	input.read(rawFileHeader, FILE_HEADER_SIZE);
	input.read(rawImageHeader, IMAGE_HEADER_SIZE);

	// parse headers
	fileHeader = FileHeader(rawFileHeader);
	imageHeader = ImageHeader(rawImageHeader);

	// crete raw pixel data buffer
	input.seekg(0, ios::end);
	int endPosition = input.tellg();
	int pixelDataSize = endPosition - fileHeader.getBfOffBits() + 1;
	char* rawPixelData = new char[pixelDataSize];

	// read raw pixel data
	// skip headers
	input.seekg(fileHeader.getBfOffBits(), ios::beg);
	input.read(rawPixelData, pixelDataSize);

	// parse pixel data
	pixelData.parseRawData(rawPixelData, imageHeader.getBiWidth(), imageHeader.getBiHeight(), imageHeader.getBiBitCount());

	// memory
	delete rawPixelData;

	// close file
	input.close();

	return true;

}

void BMP::save(string filename) {

	ofstream output(filename, ios::binary);

	my::RGB** pixelMatrix = pixelData.getPixelMatrix();
	int width = imageHeader.getBiWidth();
	int height = imageHeader.getBiHeight();
	char zero = 0;

	// headers
	for (int i = 0; i < FILE_HEADER_SIZE; i++) {
		output << rawFileHeader[i];
	}
	for (int i = 0; i < IMAGE_HEADER_SIZE; i++) {
		output << rawImageHeader[i];
	}

	// offset
	int offsetSize = fileHeader.getBfOffBits() - (FILE_HEADER_SIZE + IMAGE_HEADER_SIZE);
	for (int i = 0; i < offsetSize; i++) {
		output << zero;
	}

	// pixels
	int padding = 0;
	if ((width * 3) % 4 != 0) {
		padding = 4 - ((width * 3) % 4);
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			output << pixelMatrix[height - i - 1][j].b << pixelMatrix[height - i - 1][j].g << pixelMatrix[height - i - 1][j].r;
		}
		for (int j = 0; j < padding; j++) {
			output << zero;
		}
	}

	output.close();

}

FileHeader* BMP::getFileHeader() {
	return &fileHeader;
}

ImageHeader* BMP::getImageHeader() {
	return &imageHeader;
}

PixelData* BMP::getPixelData() {
	return &pixelData;
}

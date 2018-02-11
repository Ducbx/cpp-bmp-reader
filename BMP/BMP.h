#pragma once

#include<iostream>
#include "FileHeader.h"
#include "ImageHeader.h"
#include "PixelData.h"

using namespace std;

const int FILE_HEADER_SIZE = 14;
const int IMAGE_HEADER_SIZE = 40;

class BMP
{
private:
	FileHeader fileHeader;
	ImageHeader imageHeader;
	PixelData pixelData;
	char rawFileHeader[FILE_HEADER_SIZE];
	char rawImageHeader[IMAGE_HEADER_SIZE];
	char* rawOffsetBytes;
public:
	BMP();
	~BMP();
	bool load(string filename);
	FileHeader* getFileHeader();
	ImageHeader* getImageHeader();
	PixelData* getPixelData();
	void save(string filename);
};


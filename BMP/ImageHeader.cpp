#include "ImageHeader.h"

#include<iostream>

using namespace std;

ImageHeader::ImageHeader()
{
}

ImageHeader::ImageHeader(char* rawData)
{

	biSize = *(int*)(&rawData[0]);
	biWidth = *(int*)(&rawData[4]);
	biHeight = *(int*)(&rawData[8]);
	biPlanes = *(wchar_t*)(&rawData[12]);
	biBitCount = *(wchar_t*)(&rawData[14]);
	biCompression = *(int*)(&rawData[16]);
	biSizeImage = *(int*)(&rawData[20]);
	biXPelsPerMeter = *(int*)(&rawData[24]);
	biYPelsPerMeter = *(int*)(&rawData[28]);
	biClrUsed = *(int*)(&rawData[32]);
	biClrImportant = *(int*)(&rawData[36]);

}


ImageHeader::~ImageHeader()
{
}

void ImageHeader::print() {

	cout << "IMAGE HEADER" << endl;
	cout << "=====================================" << endl;
	cout << "biSize : " << biSize << endl;
	cout << "biWidth : " << biWidth << endl;
	cout << "biHeight : " << biHeight << endl;
	cout << "biPlanes : " << biPlanes << endl;
	cout << "biBitCount : " << biBitCount << endl;
	cout << "biCompression : " << biCompression << endl;
	cout << "biSizeImage : " << biSizeImage << endl;
	cout << "biXPelsPerMeter : " << biXPelsPerMeter << endl;
	cout << "biYPelsPerMeter : " << biYPelsPerMeter << endl;
	cout << "biClrUsed : " << biClrUsed << endl;
	cout << "biClrImportant : " << biClrImportant << endl;
	cout << "=====================================" << endl;

}

int ImageHeader::getBiWidth() {
	return biWidth;
}

int ImageHeader::getBiHeight(){
	return biHeight;
}

wchar_t ImageHeader::getBiBitCount() {
	return biBitCount;
}

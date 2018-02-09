#pragma once
class ImageHeader
{
private:
	int biSize;
	int biWidth;
	int biHeight;
	wchar_t biPlanes;
	wchar_t biBitCount;
	int biCompression;
	int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	int biClrUsed;
	int biClrImportant;
public:
	ImageHeader();
	ImageHeader(char* rawData);
	~ImageHeader();
	void print();
	int getBiWidth();
	int getBiHeight();
	wchar_t getBiBitCount();
};


#pragma once

class FileHeader
{

private:
	char bfType[3];
	int bfSize;
	wchar_t bfReserved1;
	wchar_t bfReserved2;
	int bfOffBits;

public:
	FileHeader();
	FileHeader(char* rawData);
	~FileHeader();
	void print();
	int getBfOffBits();
};


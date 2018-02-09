#include "FileHeader.h"

#include<iostream>
#include<cstdio>

using namespace std;

FileHeader::FileHeader()
{
}

FileHeader::FileHeader(char* rawData)
{

	bfType[0] = rawData[0];
	bfType[1] = rawData[1];
	bfType[2] = '\0';
	bfSize = *(int*)(&rawData[2]);
	bfReserved1 = *(wchar_t*)(&rawData[6]);
	bfReserved2 = *(wchar_t*)(&rawData[8]);
	bfOffBits = *(int*)(&rawData[10]);

}


FileHeader::~FileHeader()
{
}

void FileHeader::print() {

	cout << "FILE HEADER" << endl;
	cout << "=====================================" << endl;
	cout << "bfType : " << bfType << endl;
	cout << "bfSize : " << bfSize << endl;
	cout << "bfReserved1 : " << bfReserved1 << endl;
	cout << "bfReserved2 : " << bfReserved2 << endl;
	cout << "bfOffBits : " << bfOffBits << endl;
	cout << "=====================================" << endl;

}

int FileHeader::getBfOffBits() {
	return bfOffBits;
}

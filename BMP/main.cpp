#include<iostream>
#include "BMP.h"
#include<Windows.h>

using namespace std;

void displayImage(BMP* image) {

	// get some useful data
	FileHeader* fileHeader = image->getFileHeader();
	ImageHeader* imageHeader = image->getImageHeader();
	PixelData* pixelData = image->getPixelData();

	int width = imageHeader->getBiWidth();
	int height = imageHeader->getBiHeight();
	my::RGB** pixelMatrix = pixelData->getPixelMatrix();

	// log some data
	fileHeader->print();
	imageHeader->print();

	// create window
	HDC dc;
	HWND window = ::CreateWindowA("STATIC", "BMP Image Displayer", WS_VISIBLE, 0, 0, width, height, NULL, NULL, NULL, NULL);
	dc = GetDC(window);

	// draw pixels
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			SetPixel(dc, i, j, RGB(pixelMatrix[j][i].r, pixelMatrix[j][i].g, pixelMatrix[j][i].b));
		}
	}

}

int main() {

	cout << "CPP BMP READER" << endl;

	// create BMP object
	BMP bmp;

	// read BMP image from file
	bool loaded = true;
	loaded = bmp.load("E:\\bmp\\hamburger.bmp");

	// check if file loaded successfully
	if (!loaded) {
		cout << "NOT BMP" << endl;
		cin.get();
		return -1;
	}

	// display the image
	displayImage(&bmp);

	// copy image
	bmp.save("E:\\bmp\\copy.bmp");

	// finish program
	cin.get();

	return 0;

}
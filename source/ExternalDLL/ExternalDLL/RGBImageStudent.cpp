#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	pixels = new RGB[1];
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) :RGBImageStudent(other.getWidth(), other.getHeight()) {
	for(int x = 0; x<getWidth(); x++) {
		for(int y = 0; y<getWidth(); y++) {
			setPixel(x, y, other.getPixel(x,y) );
		}
	}
	//TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixels = new RGB[width*height];
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	//TODO: delete allocated objects
	delete[] pixels;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] pixels;
	pixels = new RGB[width*height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	set(other.getWidth(), other.getHeight());
	
	for(int x = 0; x<getWidth(); x++) {
		for(int y = 0; y<getWidth(); y++) {
			setPixel(x, y, other.getPixel(x, y));
		}
	}
}

int RGBImageStudent::posToInt(int x, int y) const {
	return (getWidth()*y)+x;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	setPixel(posToInt(x,y),pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixels[i] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return getPixel(posToInt(x, y));
}

RGB RGBImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return pixels[i];
}

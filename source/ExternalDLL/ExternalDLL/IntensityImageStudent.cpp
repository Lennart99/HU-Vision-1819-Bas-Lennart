#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
	pixels = new Intensity[1];
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other):IntensityImageStudent(other.getWidth(), other.getHeight()) {
	for(int x = 0; x<getWidth(); x++) {
		for(int y = 0; y<getWidth(); y++) {
			setPixel(x, y, other.getPixel(x, y));
		}
	}
	//TODO: Create a copy from the other object
}


IntensityImageStudent::IntensityImageStudent(const int width, const int height): IntensityImage(width, height) {
	pixels = new Intensity[width*height];
	//TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
	//TODO: delete allocated objects
	delete[] pixels;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] pixels;
	pixels = new Intensity[width*height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	set(other.getWidth(), other.getHeight());

	for(int x = 0; x<getWidth(); x++) {
		for(int y = 0; y<getWidth(); y++) {
			setPixel(x, y, other.getPixel(x, y));
		}
	}
}

int IntensityImageStudent::posToInt(int x, int y) const {
	return (getWidth()*y)+x;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	setPixel(posToInt(x, y), pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
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

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return getPixel(posToInt(x, y));
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return pixels[i];
}

#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include "ImageFactory.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	// TODO replace with ImageFactory::newIn...
	auto ptr = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	for (int w = 0; w < image.getWidth(); w++) {
		for (int h = 0; h < image.getHeight(); h++) {
			auto c = image.getPixel(w, h);
			//Intensity i = (c.r / 3) + (c.g / 3) + (c.b / 3);
			Intensity i = (c.r + c.g + c.b)/3;
			ptr->setPixel(w, h, i);
		}
	}
	return ptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}

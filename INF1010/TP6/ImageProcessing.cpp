/********************************************************************************/
/*                                                                              */
/*  INF-1010 Lab 6 :                                                            */
/*  Interface Graphique et Exception                                      	  	*/
/*                                                                              */
/********************************************************************************/

#include "ImageProcessing.h"


inline int Truncate(int value) {
	int res = (value < 0) ? 0 : value;
	return (res > 255) ? 255 : res;
}

int ImageProcessing::intensity(
	int offset,
	const QImage &image,
	QImage &image_out)
{
	image_out = image;
	int red_mean = 0, green_mean = 0, blue_mean =0; 
	for (int i = 0; i <image.width(); ++i)
	{
		for (int j = 0; j < image.height(); ++j)
		{
			QRgb pixel = image.pixel(i, j);
			int red = qRed(pixel)  + offset;
			int green = qGreen(pixel)  + offset;
			int blue = qBlue(pixel)  + offset;
			pixel = qRgb(Truncate(red), Truncate(green), Truncate(blue));

			red_mean+=red;
			green_mean+=green;
			blue_mean+=blue;

			image_out.setPixel(i, j, pixel);
		}
	}

	if( (float(red_mean + green_mean + blue_mean)/float(3*image.width()*image.height()) > 220.0f) )
		return 1;

	else if( (float(red_mean + green_mean + blue_mean)/float(3*image.width()*image.height()) < 20.0f) )
		return -1;
	
	else
		return 0;
}

int ImageProcessing::contrast(
	int contrast,
	const QImage &image,
	QImage &image_out)
{
	image_out = image;

	if(contrast > 128)  
		return 1;

	else if(contrast < -128)  
		return -1;

	float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
	for (int i = 0; i < image.width(); ++i)
	{
		for (int j = 0; j < image.height(); ++j)
		{
			QRgb pixel = image.pixel(i, j);
			int red = qRed(pixel);
			int green = qGreen(pixel);
			int blue = qBlue(pixel);

			red = Truncate(int(factor*(red - 128)) + 128);
			green = Truncate(int(factor*(green - 128)) + 128);
			blue = Truncate(int(factor*(blue - 128)) + 128);

			pixel = qRgb(red, green, blue);
			image_out.setPixel(i, j, pixel);
		}
	}

	return 0;
}


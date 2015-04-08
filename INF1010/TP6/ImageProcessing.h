/********************************************************************************/
/*                                                                              */
/*  INF-1010 Lab 6 :                                                            */
/*  Interface Graphique et Exception                                      	  	*/
/*                                                                              */
/********************************************************************************/

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QtGui>

class ImageProcessing
{
	public:
		ImageProcessing() {};

		~ImageProcessing() {};

		// Ajoute l'offset à l'intensité de l'image
		// Si l'intensté moyenne de l'image traitée est trop basse, retourne -1
		// Si l'intensté moyenne de l'image traitée est trop haute, retourne 1
		// Si l'intensté moyenne de l'image traitée est correcte, retourne 0
		int intensity(int offset, const QImage &image, QImage &image_out);

		// Change le contraste de l'image
		// Si l'intensté moyenne de l'image traitée est trop basse, retourne -1
		// Si l'intensté moyenne de l'image traitée est trop haute, retourne 1
		// Si l'intensté moyenne de l'image traitée est correcte, retourne 0
		int contrast(int offset, const QImage &image, QImage &image_out);
};

#endif // IMAGE_PROCESSING_H

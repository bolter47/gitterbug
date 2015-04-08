/********************************************************************************/
/*                                                                              */
/*  INF-1010 Lab 6 :                                                            */
/*  Interface Graphique et Exception                                      	  	*/
/*                                                                              */
/********************************************************************************/

#include "ImageException.h"


ImageBaseException::ImageBaseException(const char * message) 
{
	
	this->msg = string(message);
}

const char * ImageBaseException::what() const throw()
{
	
	return this->msg.c_str();
}

void ImageBaseException::showAlert() const {
	QMessageBox messageBox;
	messageBox.critical(0,"Error", this->msg.c_str());
	messageBox.setFixedSize(500,200);
}

ImageLoadingException::ImageLoadingException(const char * message) : ImageBaseException(message) {

}

ImageProcessingException::ImageProcessingException(const char * message) : ImageBaseException(message) {

}

void ImageProcessingException::resetSlider(QSlider *slider) {
	int value = slider->value();
	// Si la valeur du slider est > 0, on lui retire 70
	// Sinon, on lui ajoute 70
	value = (value > 0)?(value - 70):value+70;
	slider->setValue(value);

	// On affiche le mesage
	this->showAlert();
}

NoImageException::NoImageException(const char * message) : ImageBaseException(message) {

}

void NoImageException::reset(QSlider *slider, QLabel *label, QComboBox *comboBox) {
	slider->setValue(0.0);
	label->clear();
	comboBox->setCurrentIndex(0);
}

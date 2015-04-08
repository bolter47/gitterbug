/********************************************************************************/
/*                                                                              */
/*  INF-1010 Lab 6 :                                                            */
/*  Interface Graphique et Exception                                      	  	*/
/*                                                                              */
/********************************************************************************/


#ifndef IMAGE_EXCEPTION_H
#define IMAGE_EXCEPTION_H

#include <exception> 
#include <QtGui>
using namespace std;

class ImageBaseException : public exception
{
	public:
		// Constuit une exception 
		ImageBaseException(const char * message);

		virtual ~ImageBaseException() throw() {};

		// Permet de récupérer la string avec l'exception
		// A appeler dans un catch
		virtual const char * what() const throw();
		
		// Affiche une pop-up d'erreur
		// A appeler dans un catch
		virtual void showAlert() const;


	protected:
		string msg;
};

class ImageLoadingException : public ImageBaseException
{
	public:
		// Constuit une exception
		ImageLoadingException(const char * message);

		virtual ~ImageLoadingException() throw() {};
};


class ImageProcessingException : public ImageBaseException
{
	public:
		// Constuit une exception
		ImageProcessingException(const char * message);

		virtual ~ImageProcessingException() throw() {};

		// Met à jour la position du slider
		// Ajoute ou retore un offset de 70
		void resetSlider(QSlider *slider); 
};

class NoImageException : public ImageBaseException
{
	public:
		// Constuit une exception
		// Paramètre par défaut pour le message car l'exception n'affiche rien.
		// Elle ne fait que réinitialiser les élements de l'interface
		NoImageException(const char * message = "");

		virtual ~NoImageException() throw() {};

		// Remet le slider à zéro, efface le contenu du label et force le combobox à l'index 0
		void reset(QSlider *slider, QLabel *label, QComboBox *comboBox); 
};


#endif // IMAGE_EXCEPTION_H

/********************************************************************************/
/*                                                                              */
/*  INF-1010 Lab 6 :                                                            */
/*  Interface Graphique et Exception                                      	  	*/
/*                                                                              */
/********************************************************************************/

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>
#include <iostream> 
#include "ImageProcessing.h"
#include "ImageException.h"
using namespace std;


class MainWindow : public QMainWindow
{
	Q_OBJECT
 
	public:
		// Ne pas changer. Constructeur
		MainWindow();

		// Ne pas changer. Destructeur
		~MainWindow() {};

	private:
		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
		// Vous devez mettre le range du slider entre -255 et 255
		// Au départ, le slider doit être initilisé à 0
		void setSliderRange();

		// Ne pas changer. Construit l'interface
		void setUI();
		
		// Ne pas changer. Construit le menu
		void setMenu();

		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!	
		// Vous devez établir les connections entre les elements de l'interface et les méthodes slots.
		// 1. L'action 'open_action' doit être connectée au slot 'load()' en utlisant le signal 'triggered()'
		// 2. La combobox 'process_combobox_' doit être connectée au slot 'processImage()'. Le signal est emit quand l'utlisateur change d'index
		// 3. Le slider 'slider_' doit être connecté au slot 'processImage()'. Le signal est emit quand l'utlisateur change la valeur du slider
		// 4. Le bouton 'empty_button' doit être connecté au slot 'empty()'. Le signal est emis lorsque l'utilisateur clique sur le button
		// 5. Le QListWidget 'list_paths_' doit être connecté au slot 'setImage(QListWidgetItem*)'. Le signal est emis lorsque l'utilisateur clique sur un des elements de la liste
		void setConnection();
	
		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
		// Vous devez verifier si l'image est valide, c'est à dire si elle n'est pas nulle, cf. la classe QImage
		// Il se peut qu'un fichier soit corrompu...
		// Si c'est le cas, cette fonction doit envoyer une exception de type 'ImageLoadingException'
		void checkImageValid(const QImage &image) const;
		
		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
		// Vous devez verifier si l'image est déjà présente dans la liste, cf. QList
		// Si c'est le cas, cette fonction doit envoyer une exception de type 'ImageLoadingException' 
		void checkImageAlreadyLoaded(const QImage &image) const;
		
		// Ne pas changer. Ajoute les images à la liste
		void addImages();

		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
		// Vous devez vérifier si le retour de la méthode 'intensity(...)' de la classe 'ImageProcessing' est valide (== 0).
		// Si ce n'est pas le cas, vous devez générer une exception de type 'ImageProcessingException'
		// Si l'intensité moyenne de l'image traitée est trop haute, alors 'intensity(...)' retourne 1
		// A l,inverse, si l'intensité moyenne est trop basse, la méthode retourne -1
		// Enfin, la méthode retourne 0 si l'intensité moyenne est correcte 
		void processImageIntensity(); 
		
		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
		// Vous devez vérifier si le retour de la méthode 'contraste(...)' de la classe 'ImageProcessing' est valide (== 0).
		// Si ce n'est pas le cas, vous devez générer une exception de type 'ImageProcessingException'
		// Si l'intensité moyenne de l'image traitée est trop haute, alors 'contraste(...)' retourne 1
		// A l,inverse, si l'intensité moyenne est trop basse, la méthode retourne -1
		// Enfin, la méthode retourne 0 si l'intensité moyenne est correcte 
		void processImageContrast();
		
		// Ne pas changer. Traite l'image courrante et update l'affichage
		void processImageAccordingToCombobox();


	public slots:
		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
		// Vous devez gérer les exceptions de type 'ImageLoadingException' générées lors de l'ouverture des images
		// cf. méthodes addImages(), checkImageValid() et checkImageAlreadyLoaded()
		// Si une exception est générée, il faut alors faire appel à la méthode showAlert() de 'ImageLoadingException' pour l'afficher
		void load();
		
		// Ne pas changer. Vide la liste d'images et de paths
		void empty();
		
		// Ne pas changer. Affiche l'image à l'index index
		void setImage(int);
		
		// Ne pas changer. Affiche l'image à l'index de l'element de list_paths_ 
		// Surcharge de 'setImage(int index)'
		void setImage(QListWidgetItem *);

		// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
		// Vous devez gérer les exceptions de type 'ImageProcessingException' générées lors du traitement des images, cf. méthodes processImageIntensity(), processImageContrast()
		// Si une exception est générée, il faut alors faire appel à la méthode resetSlider(...) de 'ImageProcessingException' pour remettre le slider à zero.
		// Il faut aussi gérer l'exception 'NoImageException' générée par la méthode 'processImageAccordingToCombobox()'.
		// Cette exception est générée si on essaie de traiter une image alors que la liste d'image est vide.
	// Le cas échéant, il faudra ne plus afficher l'image traitée, remettre le slider et le combobox à zero en faisant appel à 'reset(...) de 'NoImageException
		// Enfin, si aucune exception n'est levée, 'image_process_label_->setPixmap(QPixmap::fromImage(image_process_));' met à jour l'affichage du résultat du traitement
		void processImage();



	private:
		ImageProcessing process_;		// Pour le traitement des images
		
		int index_;						// Index de l'image courrante 
		
		int range_;						// Range des sliders, entre -255 et 255
		
		QSize image_label_size;			// Taille de l'affichage de l'image
		
		QAction *open_action_;			// Action du menu pour ouvrir les fichiers
		
		QAction *exit_action_;			// Action du menu pour sortir de l'application

		QList<QImage> images_list_;		// Liste des images loadées
		
		QImage image_process_;			// Image résultat du traitement de l'image courrante

		QLabel *image_label_;			// QLabel contenant l'image courante de la liste 'images_list_'
		
		QLabel *image_process_label_;	// QLabel contenant l'image traitée
		
		QComboBox *process_combobox_;	// Combobox permettant de changer l'opération sur l'image
		
		QSlider * slider_; 				// Le slider utlisé pour le traitement
		
		QPushButton *empty_button_;		// Button pour vider la liste d'image et de paths
		
		QListWidget *list_paths_; 		// Widget contenant la liste des paths des images et qui les affiche.
		                                // Il permet également de changer l'image courrante en cliquant sur un de ses elements
};

#endif // MAIN_WINDOW_H

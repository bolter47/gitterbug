#include "tp4.hpp"

#include "Point.hpp"
#include "Ligne.hpp"
#include "Rectangle.hpp"
#include "Polygone.hpp"
#include "Ellipse.hpp"
#include "Cercle.hpp"
#include "Texte.hpp"
#include "Couleurs.h"

/* Fonction à appeler à la fin de faireDessin */
void ecrireFrame(const Canevas* c);


Cercle* nouveauCercle(Coord centre, unsigned int rayon, unsigned int couleur) {
	Cercle* nouveau = new Cercle(cnetre, rayon, couleur);
	return nouveau; // A modifier
}

void faireDessin(Forme** formes, unsigned int n) {
	Canevas canevas(LARGEUR_CANEVAS, HAUTEUR_CANEVAS, COULEUR_CANEVAS);
	for (unsigned int i = 0; i < n; i++)
		canevas.dessinerForme(formes[i]);
		
	ecrireFrame(&canevas);
}


void desallouerForme(Forme* forme) {

}

void Canevas::dessinerForme(Forme *forme)
{
	forme -> dessiner(this);
}

void Canevas::assignerPixel(int x, int y, unsigned int couleur)
{

}

void Canevas::assignerPixel(Coord coord, unsigned int couleur)
{
	assignerPixel(coord.x, coord.y, couleur);
}

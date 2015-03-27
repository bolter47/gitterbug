#include "tp4.hpp"

#include "Point.hpp"
#include "Ligne.hpp"
#include "Rectangle.hpp"
#include "Polygone.hpp"
#include "Ellipse.hpp"
#include "Cercle.hpp"
#include "Texte.hpp"
#include "Couleurs.h"
#include <iostream>

/* Fonction à appeler à la fin de faireDessin */
void ecrireFrame(const Canevas* c);


/*Cercle* nouveauCercle(Coord centre, unsigned int rayon, unsigned int couleur) {
	Cercle* nouveau = new Cercle(centre, rayon, couleur); // dont forget to explicitly call the constructor in assemble + the new operator
	return nouveau; // A modifier
}*/

/*void faireDessin(Forme** formes, unsigned int n) {
	Canevas canevas(LARGEUR_CANEVAS, HAUTEUR_CANEVAS, COULEUR_CANEVAS);
	for (unsigned int i = 0; i < n; i++)
	{
		canevas.dessinerForme(formes[i]);
	}

	ecrireFrame(&canevas);
}*/


/*void desallouerForme(Forme* forme) {
	delete forme; // dont forget to explicitly call the destructor in assembly
}*/

/*void Canevas::dessinerForme(Forme *forme)
{
	forme->dessiner(this);
}*/

/*void Canevas::assignerPixel(int x, int y, unsigned int couleur)
{
	if(x > 0 && x < (int)this->_w && y > 0 && y < (int)this->_h)
	{
		this->_canevas[y * this->_w + x] = couleur;
	}
}*/

/*void Canevas::assignerPixel(Coord coord, unsigned int couleur)
{
	assignerPixel(coord.x, coord.y, couleur);
}*/

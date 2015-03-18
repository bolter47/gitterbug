#include "Panier.h"

/*************************************************
 * Contient les implémentations de méthodes publiques
 * de la classe Panier qui n'utilisent pas le template
 * **********************************************/
Panier::Panier(unsigned int id):id_(id){}

unsigned int Panier::getID() const{
	return id_;
}

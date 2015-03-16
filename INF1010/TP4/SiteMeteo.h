#ifndef	SITE_METEO_H
#define SITE_METEO_H

#include "Afficheur.h"
#include <vector>
#include <iostream>

using namespace std;

enum Langue
{
	FRANCAIS,
	ANGLAIS
};


class SiteMeteo
{
public:
	SiteMeteo();


	// Manip d'afficheage
	void ajouterAfficheur(Afficheur* afficheur);
	void retirerAfficheur(Afficheur* afficheur);

	void afficherSite();

	// get/set Langue
	Langue getLangue() const;
	void setLangue(Langue langue);


private:
	vector<Afficheur*> afficheurs_;

	Langue langue_;
};


#endif

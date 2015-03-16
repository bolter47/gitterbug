#ifndef AFFICHEURMETEOSTATISTIQUES_H
#define AFFICHEURMETEOSTATISTIQUES_H

#include "Afficheur.h"
#include "Connection.h"
#include "Meteo.h"
#include <iostream>

class AfficheurMeteoStatistiques: public Afficheur, Connection{
	public:
	AfficheurMeteoStatistiques();
	~AfficheurMeteoStatistiques();
	
	// Redef methodes d'afficheage
	void afficherFrancais() const;
	void afficherAnglais() 	const;
	
	// Autres redef d'Afficheur
	string getTypeAfficheur() 		const;
	
	//Redefs de Connection
	void mettreAJourConnection(BaseDeDonnees* donnees);
	
	//DRY
	void statistiquesMoyennes(float tempMoyenneAnnuelle, float vitesseVentsMoyenAnnuelle, float visibiliteMoyenneAnnuelle) const;
	
	private:
	// Archives meteos precedents par composition
	Meteo* donneesDerniereAnnee_ [365];
	unsigned int nbDonnees_;
	float tempMoyenneAnnuelle_,vitesseVentsMoyenAnnuelle_,visibiliteMoyenneAnnuelle_;
};

#endif

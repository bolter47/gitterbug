#ifndef AFFICHEURMETEOSTATISTIQUES_H
#define AFFICHEURMETEOSTATISTIQUES_H

#include "Afficheur.h"
#include "Connection.h"

class AfficheurMeteoStatistiques: Afficheur, Connection{
	public:
	
	// Redef methodes d'afficheage
	void afficherFrancais() const;
	void afficherAnglais() 	const;
	
	// Autres redef d'Afficheur
	string getTypeAfficheur() 		const;
	
	//Redefs de Connection
	void mettreAJourConnection(BaseDeDonnees* donnees);
	
	
	private:
	
	// Archives meteos precedents par composition
	Meteo donneesDerniereAnnee_* [365];
	int nbDonnees_;
	

}

#endif

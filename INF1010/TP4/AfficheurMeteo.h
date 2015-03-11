#ifndef AFFICHEURMETEO_H
#define AFFICHEURMETEO_H

#include "Afficheur.h"
#include "Connection.h"

class AfficheurMeteo: Afficheur, Connection{
	public:
	
	// Redef methodes d'afficheage
	void afficherFrancais() const;
	void afficherAnglais() 	const;
	
	// Autres redef d'Afficheur
	string getTypeAfficheur() 		const;
	
	//Redefs de Connection
	void mettreAJourConnection(BaseDeDonnees* donnees);
	
	
	private:
	
	// Base de donnees source
	Meteo donnees_;
	

}

#endif

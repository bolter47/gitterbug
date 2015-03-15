#include "AfficheurMeteo.h"

// Redef methodes d'afficheage
	void AfficheurMeteo::afficherFrancais() const{
		// TODO Entête du cout
		cout << "----------------------------"
		<< getTypeAfficheur()
		<< "----------------------------" << endl
		// Corps du cout
		<< "Temperature courante: " << donnees_.getTemperature() << " degres Celsius" << endl
		<< "Vitesse du vent: " << donnees_.getVent() << " km/h" << endl
		<< "Visibilite: " << donnees_.getVisibilite() << " km" << endl;
	}
	
	void AfficheurMeteo::afficherAnglais() const{
		// TODO Entête du cout
		cout << "----------------------------"
		<< getTypeAfficheur()
		<< "----------------------------" << endl
		// Corps du cout
		<< "Current temperature: " << donnees_.getTemperature() << " degrees Celsius" << endl
		<< "Wind speed: " << donnees_.getVent() << " km/h" << endl
		<< "Visibility: " << donnees_.getVisibilite() << " km" << endl;		
	}
	
	// Autres redef d'Afficheur
	string AfficheurMeteo::getTypeAfficheur() const{
		return typeid(AfficheurMeteo).name();
	}
	
	//Redefs de Connection
	void mettreAJourConnection(BaseDeDonnees* donnees){
		
	}

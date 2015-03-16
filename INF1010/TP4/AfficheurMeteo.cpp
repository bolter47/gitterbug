#include "Afficheur.h"
#include "Connection.h"
#include "Meteo.h"
#include "AfficheurMeteo.h"

void AfficheurMeteo :: afficherFrancais()		const{
	cout << "Temperature courante: " << donnees_.getTemperature() << " degres Celsius" << endl
		 << "Vitesse du vent: " << donnees_.getVent() << " km/h" << endl
		 << "Visibilite: " << donnees_.getVisibilite() << " km" << endl;
}

void AfficheurMeteo :: afficherAnglais()		const{
	cout << "Current temperature: " << donnees_.getTemperature() << " degres Celsius" << endl
		 << "Wind speed: " << donnees_.getVent() << " km/h" << endl
		 << "Visibility: " << donnees_.getVisibilite() << " km" << endl;
}

string AfficheurMeteo :: getTypeAfficheur()		const{
	cout << "-----------------------------------------Afficheur Meteo--------------------------------------------" << endl;
	return typeid(AfficheurMeteo).name();
}

void AfficheurMeteo::mettreAJourConnection(BaseDeDonnees* donnees){
	donnees_ = *donnees;
}

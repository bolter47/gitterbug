#include "Afficheur.h"
#include "Connection.h"
#include "Meteo.h"
#include "AfficheurMeteoStatistiques.h"

AfficheurMeteoStatistiques :: AfficheurMeteoStatistiques():
nbDonnees_(0)
{
}

void AfficheurMeteoStatistiques :: afficherFrancais() const {
	float temp = 0, vents = 0, visibilite = 0;
	statistiquesMoyennes(temp, vents, visibilite);
	cout << "Temperature moyenne: " << temp << " degres Celsius" << endl
		 << "Vent moyen: " << vents << " km/h" << endl
		 << "Visibilite moyenne: " << visibilite << " km" << endl;
}

void AfficheurMeteoStatistiques :: afficherAnglais() const {
	float temp = 0, vents = 0, visibilite = 0;
	statistiquesMoyennes(temp, vents, visibilite);
	cout << "Average temperature: " << temp<< " degres Celsius" << endl
		 << "Average wind: " << vents << " km/h" << endl
		 << "Average visibility: " << visibilite << " km" << endl;
}

string AfficheurMeteoStatistiques :: getTypeAfficheur() const{
	//cout << "-----------------------------------------Afficheur Statistiques Meteo--------------------------------------------" << endl;
	return typeid(AfficheurMeteoStatistiques).name();
}

void AfficheurMeteoStatistiques :: mettreAJourConnection(BaseDeDonnees* donnees) {
	if(nbDonnees_>=365){
		for(unsigned i=0;i < nbDonnees_-1;i++){
			donneesDerniereAnnee_[i] = donneesDerniereAnnee_[i+1];
			nbDonnees_ = nbDonnees_-1;
		}
	}
	donneesDerniereAnnee_[nbDonnees_-1] = donnees;
	nbDonnees_ ++;
}

void AfficheurMeteoStatistiques::statistiquesMoyennes(float tempMoyenneAnnuelle, float vitesseVentsMoyenAnnuelle, float visibiliteMoyenneAnnuelle) const{
	for(unsigned i=0;i<nbDonnees_;i++){
		tempMoyenneAnnuelle += donneesDerniereAnnee_[i] -> getTemperature();
		vitesseVentsMoyenAnnuelle += donneesDerniereAnnee_[i] -> getVent();
		visibiliteMoyenneAnnuelle += donneesDerniereAnnee_[i] -> getVisibilite();
	}
	tempMoyenneAnnuelle = tempMoyenneAnnuelle/nbDonnees_;
	vitesseVentsMoyenAnnuelle = vitesseVentsMoyenAnnuelle/nbDonnees_;
	visibiliteMoyenneAnnuelle = visibiliteMoyenneAnnuelle/nbDonnees_;
}

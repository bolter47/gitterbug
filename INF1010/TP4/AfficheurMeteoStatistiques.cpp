#include "Afficheur.h"
#include "Connection.h"
#include "Meteo.h"
#include "AfficheurMeteoStatistiques.h"

AfficheurMeteoStatistiques :: AfficheurMeteoStatistiques():
nbDonnees_(0)
{
}

void AfficheurMeteoStatistiques :: afficherFrancais() const {
	statistiquesMoyennes();
	cout << "Temperature moyenne: " << tempMoyenneAnnuelle << " degres Celsius" << endl
		 << "Vent moyen: " << vitesseVentsMoyenAnnuelle << " km/h" << endl
		 << "Visibilite moyenne: " << visibiliteMoyenneAnnuelle << " km" << endl;
}

void AfficheurMeteoStatistiques :: afficherAnglais() const {
	statistiquesMoyennes();
	cout << "Average temperature: " << tempMoyenneAnnuelle << " degres Celsius" << endl
		 << "Average wind: " << vitesseVentsMoyenAnnuelle << " km/h" << endl
		 << "Average visibility: " << visibiliteMoyenneAnnuelle << " km" << endl;
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

void AfficheurMeteoStatistiques::statistiquesMoyennes(){
	double tempMoyenneAnnuelle, vitesseVentsMoyenAnnuelle, visibiliteMoyenneAnnuelle;
	for(unsigned i=0;i<nbDonnees_;i++){
		tempMoyenneAnnuelle += donneesDerniereAnnee_[i].getTemperature();
		vitesseVentsMoyenAnnuelle += donneesDerniereAnnee_[i].getVent();
		visibiliteMoyenneAnnuelle += donneesDerniereAnnee_[i].getVisibilite();
	}
	tempMoyenneAnnuelle = tempMoyenneAnnuelle/nbDonnees_;
	vitesseVentsMoyenAnnuelle = vitesseVentsMoyenAnnuelle/nbDonnees_;
	visibiliteMoyenneAnnuelle = visibiliteMoyenneAnnuelle/nbDonnees_
}

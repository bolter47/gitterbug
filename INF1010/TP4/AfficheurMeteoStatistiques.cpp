#include <Afficheur.h>
#include <Connection.h>
#include <Meteo.h>

AfficheurMeteoStatistiques :: AfficheurMeteoStatistiques():
donneesDerniereAnnee_*[(0)],
nbDonnees_(0)
{
}

void AfficheurMeteoStatistiques :: afficherFrancais() const {
	double tempMoyenneAnnuelleF, vitesseVentsMoyenAnnuelleF, visibiliteMoyenneAnnuelleF;
	for(int i=0;i<nbDonnees_;i++){
		tempMoyenneAnnuelleF += donneesDerniereAnnee_[i].getTemperature();
		vitesseVentsMoyenAnnuelleF += donneesDerniereAnnee_[i].getVent();
		visibiliteMoyenneAnnuelleF += donneesDerniereAnnee_[i].getVisibilite();
	}
	tempMoyenneAnnuelleF = tempMoyenneAnnuelleF/nbDonnees_;
	vitesseVentsMoyenAnnuelleF = vitesseVentsMoyenAnnuelleF/nbDonnees_;
	visibiliteMoyenneAnnuelleF = visibiliteMoyenneAnnuelleF/nbDonnees_
	
	cout << "Temperature moyenne: " << tempMoyenneAnnuelleF << " degres Celsius" << endl
		 << "Vent moyen: " << vitesseVentsMoyenAnnuelleF << " km/h" << endl
		 << "Visibilite moyenne: " << visibiliteMoyenneAnnuelleF << " km" << endl;
}

void AfficheurMeteoStatistiques :: afficherAnglais() const {
	double tempMoyenneAnnuelleA, vitesseVentsMoyenAnnuelleA, visibiliteMoyenneAnnuelleA;
	for(int i=0;i<nbDonnees_;i++){
		tempMoyenneAnnuelleA += donneesDerniereAnnee_[i].getTemperature();
		vitesseVentsMoyenAnnuelleA += donneesDerniereAnnee_[i].getVent();
		visibiliteMoyenneAnnuelleA += donneesDerniereAnnee_[i].getVisibilite();
	}
	tempMoyenneAnnuelleA = tempMoyenneAnnuelleF/nbDonnees_;
	vitesseVentsMoyenAnnuelleA = vitesseVentsMoyenAnnuelleF/nbDonnees_;
	visibiliteMoyenneAnnuelleA = visibiliteMoyenneAnnuelleF/nbDonnees_
	
	cout << "Average temperature: " << tempMoyenneAnnuelleA << " degres Celsius" << endl
		 << "Average wind: " << vitesseVentsMoyenAnnuelleA << " km/h" << endl
		 << "Average visibility: " << visibiliteMoyenneAnnuelleA << " km" << endl;
}

string AfficheurMeteoStatistiques :: getTypeAfficheur() const{
	cout << "-----------------------------------------Afficheur Statistiques Meteo--------------------------------------------" << endl;
	return typeid(AfficheurMeteoStatistiques).name();
}

void AfficheurMeteoStatistiques :: mettreAJourConnection(BaseDeDonnees* donnees) {
	if(nbDonnees_>=365){
		for(int i=0;i < nbDonnees_-1;i++){
			donneesDerniereAnnee_[i] = donneesDerniereAnnee_[i+1];
			nbDonnees_ = nbDonnees_-1;
		}
	}
	donneesDerniereAnnee_[nbDonnees_-1] = &donnees;
	nbDonnees_ ++;
}
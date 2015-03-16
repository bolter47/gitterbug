#include "AfficheurDateHeure.h"

// Redef methodes d'afficheage
	void AfficheurDateHeure::afficherFrancais() const{
		// TODO Entête du cout
		cout << "----------------------------"
		<< getTypeAfficheur()
		<< "----------------------------" << endl
		// Corps du cout
		<< JOUR_STRING_FR[dateHeure_.getJourSemaine()] << " le " <<  dateHeure_getJourMois << " " << MOIS_STRING_FR[dateHeure_.getMois()]
		<< " " dateHeure_.getAnnee() << ", " << dateHeure_.getHeure() << " " << dateHeure_.getMinute << " " << dateHeure_.getSeconde();
	}
	
	void AfficheurDateHeure::afficherAnglais() const{
		// TODO Entête du cout
		cout << "----------------------------"
		cout << "----------------------------"
		<< getTypeAfficheur()
		<< "----------------------------" << endl
		// Corps du cout
		<< JOUR_STRING_EN[dateHeure_.getJourSemaine()] << " " <<  dateHeure_getJourMois << " " << MOIS_STRING_EN[dateHeure_.getMois()]
		<< " " dateHeure_.getAnnee() << ", " << dateHeure_.getHeure() << " " << dateHeure_.getMinute << " " << dateHeure_.getSeconde();		
	}
	
	// Autres redef d'Afficheur
string AfficheurDateHeure::getTypeAfficheur() const{
		return typeid(AfficheurDateHeure).name();
	}
	
	//Redefs de Connection
void AfficheurDateHeure::mettreAJourConnection(BaseDeDonnees* donnees){
	}



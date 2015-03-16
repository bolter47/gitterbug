#include "Sitemeteo.h"


SteMeteo::SiteMeteo(){}

void SiteMeteo::ajouterAfficheur(Afficheur* afficheur){
	afficheurs_.push_back(afficheur);
}

void SiteMeteo::retirerAfficheur(Afficheur* afficheur){
	for (unsigned i = 0; afficheurs_.sise(); i++){
		if(afficheurs_[i] == afficheur) afficheurs_.erase(i);
	}
}


void SiteMeteo::afficherSite(){
	for (unsigned i = 0; afficheurs_.sise(); i++){
		// TODO Entête du cout
		cout << "----------------------------"
		cout << "----------------------------"
		<< afficheurs_ -> getTypeAfficheur()
		<< "----------------------------" << endl
		afficheurs_ -> Afficheur();
	}
}


Langue SiteMeteo::getLangue() const {
	return langue_;
}

void SiteMeteo::setLangue(Langue langue){
	langue_ = langue;
}


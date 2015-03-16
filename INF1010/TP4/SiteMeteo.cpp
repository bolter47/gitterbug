#include "SiteMeteo.h"


SiteMeteo::SiteMeteo(){}

void SiteMeteo::ajouterAfficheur(Afficheur* afficheur){
	afficheurs_.push_back(afficheur);
}

void SiteMeteo::retirerAfficheur(Afficheur* afficheur){
	for (unsigned i = 0; afficheurs_.size(); i++)
		if(afficheurs_[i] == afficheur){
			vector<Afficheur*>::iterator it = afficheurs_.begin();
			it += i;
			afficheurs_.erase(it);
		}
}


void SiteMeteo::afficherSite(){
	for (unsigned i = 0; afficheurs_.size(); i++){
		// TODO Entête du cout
		cout << "----------------------------"
		<< afficheurs_[i] -> getTypeAfficheur()
		<< "----------------------------" << endl;
		if (langue_ == FRANCAIS)
			afficheurs_[i] -> afficherFrancais();
		else
			afficheurs_[i] -> afficherAnglais();
	}
}


Langue SiteMeteo::getLangue() const {
	return langue_;
}

void SiteMeteo::setLangue(Langue langue){
	langue_ = langue;
}


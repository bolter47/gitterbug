#include "Ecole.h"


//constructeurs
Ecole::Ecole() : nom_(""), adresse_(""), nombreSections_(0){};
Ecole::Ecole(const string& nom, const string& adresse) : nom_(nom), adresse_(adresse), nombreSections_(0){};

//destructeur
Ecole::~Ecole(){
}

// Les accesseurs
string Ecole::getNom() const{ return nom_; };
string Ecole::getAdresse() const{ return adresse_; };
unsigned int Ecole::getNombreSection() const{ return nombreSections_; };

// Les mutateurs
void Ecole::setNom(const string& nom){ nom_ = nom; };
void Ecole::setAdresse(const string& adresse){ adresse_ = adresse; };

bool Ecole::ajouterSection(Section* section){
	if (nombreSections_ == MAX_SECTIONS)
		return false;

	for (unsigned i = 0; i < nombreSections_; i++){
		if (sections_[i] -> getLocal() == section -> getLocal())
		return false;
	}
	sections_[nombreSections_] = section;
	nombreSections_++;
	return true;
};

bool Ecole::supprimerSection(const string& sigle, const string& local){
	bool estDetruit = false;
	for (unsigned i = 0; i < nombreSections_; i++){
		if (sections_[i] -> getLocal() == local)
			estDetruit = true;

		if (estDetruit){
			if( i < nombreSections_ - 1)
				sections_[i] = sections_[i+1];
			else
				delete sections_[i];
		}
	}
	if (estDetruit)
		nombreSections_--;
		
	return estDetruit;
};


void Ecole::afficher() const{
	cout << "ecole : " << nom_ << " adresse : " << adresse_ << " nombresections : " << nombreSections_ << endl;
	for (unsigned i = 0; i < nombreSections_; i++){
		sections_[i] -> afficher();
	}
};

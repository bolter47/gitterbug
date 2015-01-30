#include "Section.h"

Section::Section():
sigle_(), local_(), titreCours_(), nombreEtudiants(0){
	etudiants_ = new Etudiant[MAX_ETUDIANTS];
}

Section::Section( const string& sigle, const string& local, const string& titre, const Professeur* prof):
sigle_(sigle), local_(local), titreCours_(titre), nombreEtudiants(0){
	etudiants_ = new Etudiant[MAX_ETUDIANTS];
}

Section::~Section(){
	delete professeur_;
	delete[] etudiants_;
}


string Section::getSigle() const{
	return sigle_;
}
string Section::getLocal() const{
	return local_;
}
string Section::getTitre() const{
	return titreCours_;
}
	
Professeur* Section::getProf() const{
	return professeur_;
}
	
unsigned Section::getNbEtudiants() const{
	return nombreEtudiants;
}
		

void Section::setSigle(const string& sigle){
	sigle_ = sigle;
}
void Section::setLocal(const string& local){
	local_ = local;
}
void Section::setTitre(const string& titre){
	titreCours_ = titre;
}
	
void Section::setProf(Professeur*& prof){
	professeur_ = prof;
}

void Section::setNbEtudiants(const unsigned& nEtudiants){
	nombreEtudiants = nEtudiants;
}

bool Section::ajouterEtudiant(const Etudiant& nouveau){
	if (nombreEtudiants == MAX_ETUDIANTS)
		return false;
	for (unsigned i = 0; i < MAX_ETUDIANTS; i++)
		if (etudiants_[i].getNom() == nouveau.getNom() && etudiants_[i].getPrenom() == nouveau.getPrenom())
			return false;
	etudiants_[nombreEtudiants] = nouveau;
	nombreEtudiants++;
	return true;
}

void Section::afficher(){
	cout << "Cours : " << sigle_ << " " << titreCours_ << endl
	<< "Local : " << local_ << endl
	<< "Nb d'etudiants : " << nombreEtudiants << endl;
	
	for (unsigned i = 0; i < nombreEtudiants; i++)
		etudiants_[i].afficher();
	}

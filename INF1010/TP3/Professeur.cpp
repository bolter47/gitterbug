#include "Professeur.h"

Professeur::Professeur(string nom, string prenom):Employe(nom, prenom){
}

unsigned Professeur::getNiveauAcces() const{
	return accesProfesseur_ + Employe::getNiveauAcces();
}

string Professeur::getClasseEmploye() const{
	return typeid(this).name();
}

ostream& operator<<(ostream& out, Professeur& professeur){
	return out << professeur;
}

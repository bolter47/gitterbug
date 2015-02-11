#include "Professeur.h"

Professeur::Professeur(string nom, string prenom){
	Employe(nom, prenom);
}

unsigned Professeur::getNiveauAcces(){
	return accesProfesseur_ + Employe::getNiveauAcces();
}

string Professeur::getClasseEmploye(){
	return typeid(this).name();
}

ostream& operator<<(ostream& out, Professeur& professeur){
	return out << professeur;
}
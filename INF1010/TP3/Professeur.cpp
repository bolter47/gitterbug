#include "Professeur.h"

Professeur::Professeur(string nom, string prenom):Employe(nom, prenom){
}

unsigned int Professeur::getNiveauAcces() const{
	return accesProfesseur_ + Employe::getNiveauAcces();
}

string Professeur::getClasseEmploye() const{
	return typeid(this).name();
}

ostream& operator<<(ostream& out, Professeur& professeur){
	out << "Nom, Prenom: " << professeur.getNom() << ", " << professeur.getPrenom() << endl
		<< "Classe d'employe: " << professeur.getClasseEmploye() << endl
		<< "Niveau d'acces: " << professeur.getNiveauAcces() << endl;
		
		return out;
}

/**
* L'implémentation de la classe du professeur qui inclut des surcharges des méthodes de la classe Employe
* \file   Professeur.cpp
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

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

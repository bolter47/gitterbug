/**
* L'implémentation de la classe d'employé qui contient des méthodes d'obtention de nom et de niveau d'acces
* \file   Employe.cpp
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

#include "Employe.h"
#include <typeinfo>

using namespace std;

	/*** CONSTRUCTEUR ***/

Employe::Employe(const string& nom, const string& prenom)
		:nom_(nom), prenom_(prenom){}
	
	/*** GETTERS ***/
		
string Employe::getNom() const{
	return nom_;
}

string Employe::getPrenom() const{
	return prenom_;
}

unsigned int Employe::getNiveauAcces() const{
	return accesEmploye_;
}
string Employe::getClasseEmploye() const{
	return typeid(this).name();
}
	
ostream& operator<<(ostream& out, const Employe& employe){
	out << "Nom, Prenom: " << employe.getNom() << ", " << employe.getPrenom() << endl
	<< "Classe d'employe : class " << employe.getClasseEmploye() << endl
	<< "Niveau d'acces: " << employe.getNiveauAcces() << endl;
	
	return out;
}	
	

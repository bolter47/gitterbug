/**
* Le Header de la classe Employe qui possède les méthodes et attributs communs à chaque personne qui fréquente la poly
* \file   Employe.h
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

#ifndef H_EMPLOYE
#define H_EMPLOYE

#include <iostream>
#include <string>


using namespace std;

class Employe{
	public:
	
		/*** CONSTRUCTEURS/DESTRUCTEURS ***/
	Employe(const string& nom, const string& prenom);
	
		/*** GETTERS ***/
	string getNom() const;
	string getPrenom() const;
	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;
	
	private:
	
	const int accesEmploye_ = 5;
	
	friend ostream& operator<<(ostream out, const Employe& employe);	
	
	protected:
		string nom_;
		string prenom_;
};

#endif

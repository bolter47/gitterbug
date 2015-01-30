#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <iostream>
#include <string>
using namespace std;

class Professeur
{
public:
	Professeur();
	Professeur(string nEmploye, string nom, string prenom,	string departement);
	~Professeur();

	// Les accesseurs
	string getnEmploye() const;
	string getNom() const;
	string getPrenom() const;
	string getdepartement_() const;

	// Les mutateurs
	void setnEmploye(const string& nEmploye);
	void setPrenom(const string& prenom);
	void setNom(const string& nom);
	void setDepartement(const string& Departement);

	void afficher() const;

private:
	string nEmploye_;
	string nom_;
	string prenom_;
	string departement_;
};

#endif
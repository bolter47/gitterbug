#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <string>
#include <typeinfo>
#include "Employe.h"

using namespace std;

class Professeur : public Employe {

public:
	//constructeur
	Professeur(string nom, string prenom);
	//accesseurs
	unsigned getNiveauAcces() const;
	string getClasseEmploye() const;
	friend ostream& operator<<(ostream& out, Professeur& professeur);

private:
	const unsigned accesProfesseur_ = 10;
};

#endif
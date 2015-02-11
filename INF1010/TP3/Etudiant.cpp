#include "Etudiant.h"
#include <typeid>

using namespace std;

Etudiant::Employe() 
	:(nom_(""), prenom_(""), accesEmploye(0))
{
}

Etudiant::Etudiant(const string& nom, const string& prenom)
	:(nom_(nom), prenom_(prenom))
{
};

string Etudiant :: getNom() const
{
	return nom_;
}

string Etudiant :: getPrenom() const
{
	return prenom_;
}

void Etudiant :: setNom(const string& nom)
{
	nom_ = nom;
}

void Etudiant :: setPrenom(const string& prenom)
{
	prenom_ = prenom;
}

unsigned int Etudiant::getNiveauAcces() const
{
	return accesEtudiant_;
}

string getClasseEmploye() const
{
	return *this.typeid;
}

ostream& operator<< (ostream& co, const Etudiant& etudiant)
{
	//Employe::operator<<(cout, (Employe) etudiant);
	co << "Nom, Prenom" << etudiant.getNom() << ", " << etudiant.getPrenom() << endl
		<< "Classe d'employe: " << etudiant.getClasseEmploye() << endl
		<< "Niveau d'acces: " << etudiant.getNiveauAcces() << endl;
	
	return co;
}
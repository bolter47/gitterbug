#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>
#include <string>

using namespace std;

class Etudiant : public Employe
{
	public:
		Etudiant(const string& nom, const string& prenom);
		string getNom() const;
		string getPrenom() const;
		void setNom(const string& nom);
		void setPrenom(const string& prenom);
		unsigned int getNiveauAcces() const;
		string getClasseEmploye() const;
		friend ostream& operator<< (ostream& co, const Etudiant& etudiant);

	private:
		const unsigned int accesEtudiant_ = 1;
};
#endif
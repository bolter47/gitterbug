#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <string>
#include <iostream>

using namespace std;

class Etudiant{
	private:
		string matricule_, prenom_, nom_;
		
	public:
		// Constructeur par défaut
		Etudiant();
		// Constructeur par params
		Etudiant(const string& matricule, const string& prenom, const string& nom);
		// Destructeur
		~Etudiant();
		
		//getters
		string getMatricule()const;
		string getPrenom()const;
		string getNom()const;
		//setters
		void setMatricule(const string& matricule);
		void setPrenom(const string& prenom);
		void setNom(const string& nom);
		
		//Affichage infos
		void afficher();
};

#endif

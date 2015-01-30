#ifndef SECTION_H
#define SECTION_H

#include <string>

#include "Professeur.h"
#include "Etudiant.h"

using namespace std;

const int MAX_ETUDIANTS = 75;

class Section{
	private:
		string sigle_, local_, titreCours_;
		Professeur* professeur_;
		Etudiant* etudiants_;
		unsigned nombreEtudiants;
		
	public:
	//constructeurs
		Section();
		Section( const string& sigle, const string& local, const string& titre, const Professeur* prof);
		
	//destructeurs
		~Section();
		
	//getters
		string getSigle() const;
		string getLocal() const;
		string getTitre() const;
		
		Professeur* getProf() const;
		
		unsigned getNbEtudiants() const;
		
	//setters
		void setSigle(const string& sigle);
		void setLocal(const string& local);
		void setTitre(const string& titre);
			
		void setProf(Professeur*& prof);
		
		void setNbEtudiants(const unsigned& nEtudiants);
		
		// autres fonctionnalités
		
		bool ajouterEtudiant(const Etudiant& nouveau);
		void afficher();
		
};

#endif

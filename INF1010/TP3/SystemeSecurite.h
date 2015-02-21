/**
* Le Header de la classe du système de sécurité qui prend des règles d'acces pour évaluer
* la permission d'acces à un local et fait des logs de ces tentatives d'acces
* \file   SystemeSecurite.h
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

#ifndef	SYSTEME_SECURITE_H
#define SYSTEME_SECURITE_H

#include "RegleAcces.h" 
#include "AgentSecurite.h"
#include "Professeur.h"
#include "Etudiant.h"
#include <vector>
#include <string>

using namespace std;

class SystemeSecurite
{
public:
	SystemeSecurite();

	bool accederLocal(const AgentSecurite& agent,	const string& local, const string& periode);
	bool accederLocal(const Professeur& prof,		const string& local, const string& periode);
	bool accederLocal(const Etudiant& etudiant,		const string& local, const string& periode);

	bool accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode);

	bool ajouterRegle(const RegleAcces& regle);

	void imprimerJournal() const;

private:

	string formatAffichage(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode, const bool estAccede);

	vector<RegleAcces>		regles_;
	vector<string>			journalAcces_;
};

#endif //DEPARTEMENT_H

/**
* Le Header de la classe de l'Agent de sécurité qui est une extension d'employe
* \file   AgentSecurite.h
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

#ifndef H_AGENTSECURITE
#define H_AGENTSECURITE

#include <string>
#include <iostream>
#include <typeinfo>
#include "Employe.h"

class AgentSecurite : public Employe {
	public:
	
	/*** CONSTRUCTEURS ***/
	AgentSecurite(const string& nom, const string& prenom);
	
	/*** GETTERS ***/
	
	unsigned int getNiveauAcces() const;
	
	string getClasseEmploye() const;
	
	friend ostream& operator<<(ostream& out, const AgentSecurite agent);
	
	private:
	const unsigned int accesAgentSecurite_ = 20;

};

#endif

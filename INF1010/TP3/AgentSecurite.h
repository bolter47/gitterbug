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
	
	unsigned getNiveauAcces() const;
	
	string getClasseEmploye() const;
	
	friend ostream& operator<<(ostream& out, const AgentSecurite agent);
	
	private:
	const int accesAgentSecurite_ = 20;

};

#endif

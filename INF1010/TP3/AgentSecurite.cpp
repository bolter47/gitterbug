/**
* L'implémentation de la classe d'agent de sécurité qui inclut des surcharges des méthodes de la classe Employe
* \file   AgentSecurite.cpp
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

#include "AgentSecurite.h"

using namespace std;

/*** CONSTRUCTEURS ***/
AgentSecurite::AgentSecurite(const string& nom, const string& prenom):Employe(nom, prenom){
}
	
/*** GETTERS ***/
	
unsigned int AgentSecurite::getNiveauAcces() const{
	return accesAgentSecurite_ + Employe::getNiveauAcces();
}
	
string AgentSecurite::getClasseEmploye() const{
	return typeid(this).name();
}
	
ostream& operator<<(ostream& out, const AgentSecurite agent){
	out << "Nom, Prenom: " << agent.getNom() << ", " << agent.getPrenom() << endl
		<< "Classe d'employe: " << agent.getClasseEmploye() << endl
		<< "Niveau d'acces: " << agent.getNiveauAcces() << endl;
		
		return out;
}

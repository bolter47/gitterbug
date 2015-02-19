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

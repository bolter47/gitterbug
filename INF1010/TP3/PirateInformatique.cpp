#include "PirateInformatique.h"

//constructeur
PirateInformatique::PirateInformatique(AgentSecurite agent) : AgentSecurite(agent.getNom(), agent.getPrenom()){
}

//accesseur
unsigned getNiveauAcces(){
	return Employe::getNiveauAcces() + Agentsecurite::getNiveauAcces();
}

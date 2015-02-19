#include "PirateInformatique.h"

//constructeur
PirateInformatique::PirateInformatique(AgentSecurite agent) : AgentSecurite(agent.getNom(), agent.getPrenom()){
}

//accesseur
unsigned int PirateInformatique::getNiveauAcces() const{
	return Employe::getNiveauAcces() + AgentSecurite::getNiveauAcces();
}

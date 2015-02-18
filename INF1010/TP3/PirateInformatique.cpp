#include "PirateInformatique.h"

//constructeur
PirateInformatique::PirateInformatique(AgentSecurite agent) : AgentSecurite(agent.getNom(), agent.getPrenom()){
}

//accesseur
unsigned PirateInformatique::getNiveauAcces() const{
	return Employe::getNiveauAcces() + AgentSecurite::getNiveauAcces();
}

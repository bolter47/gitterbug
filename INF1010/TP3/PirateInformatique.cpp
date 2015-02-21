/**
* L'implémentation de la classe du pirate qui se construit à partir d'un agent de sécurité
* \file   PirateInformatique.cpp
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

#include "PirateInformatique.h"

//constructeur
PirateInformatique::PirateInformatique(AgentSecurite agent) : AgentSecurite(agent.getNom(), agent.getPrenom()){
}

//accesseur
unsigned int PirateInformatique::getNiveauAcces() const{
	return Employe::getNiveauAcces() + AgentSecurite::getNiveauAcces();
}

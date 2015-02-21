/**
* Le Header de la classe du pirate qui est une extension de l'agent de sécurité
* \file   PirateInformatique.h
* \author Gendreau, Vincent et Courbariaux
* \date   11 février 2015
*/

#ifndef PIRATEINFORMATIQUE_H
#define PIRATEINFORMATIQUE_H

#include "AgentSecurite.h"

using namespace std;

class PirateInformatique : public AgentSecurite{

public:
	//constructeur
	PirateInformatique(AgentSecurite agent);
	//accesseur
	unsigned int getNiveauAcces() const;
};
#endif

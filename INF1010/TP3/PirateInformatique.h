#ifndef PIRATEINFORMATIQUE_H
#define PIRATEINFORMATIQUE_H
#include "AgentSecurite.h"

using namespace std;

class PirateInformatique : public AgentSecurite{

public:
	//constructeur
	PirateInformatique(AgentSecurite pirate);
	//accesseur
	unsigned getNiveauAcces();
}
#endif
#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include "Connection.h"
#include <vector>

using namespace std;

class BaseDeDonnees{

	public:
	
	// Gestion de connection
	bool virtual ajouterConnection(Connection* connection){
		bool estPresent = false;
		for (unsigned i = 0; i < connections_.size(); i++)
			if (connections_[i] == connection)
				estPresent = true;
		if (estPresent == false)
			connections_.push_back(connection);
		return estPresent;
	};
	
	bool virtual retirerConnection(Connection* connection){
		bool estPresent = false;
		for (unsigned i = 0; i < connections_.size(); i++)
			if (connections_[i] == connection){
				estPresent = true;
				delete connections_[i];
				std::vector<Connection*>::iterator it = connections_.begin();
				it += i;
				connections_.erase(it);
			}
		return estPresent;
	};
	void mettreAJourConnections(){
		for(unsigned i = 0; i < connections_.size(); i++)
			connections_[i] -> mettreAJourConnection(this);
	};
	// Gestion de donnees
	virtual void mettreAJourDonnees() = 0;
		
	protected:
	
	// Connections à la base
	vector<Connection*> connections_;
};

#endif

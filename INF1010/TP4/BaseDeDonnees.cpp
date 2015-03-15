#include "BaseDeDonnees.h"

// Gestion de connection
	bool BaseDeDonnees::ajouterConnection(Connection* connection){
		bool estPresent = false;
		for (unsigned i = 0; i < connections_.size(); i++)
			if (connections_[i] == connection)
				estPresent = true;
		if (estPresent == false)
			connections_.push_back(connection);
		return estPresent;
	}
	
	bool BaseDeDonnees::retirerConnection(Connection* connection){
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
	}
	
	void BaseDeDonnees::mettreAJourConnections(){
		for(unsigned i = 0; i < connections_.size(); i++)
			connections_[i] -> mettreAJourConnection(this);
	}

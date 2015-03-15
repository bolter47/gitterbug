#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include "Connection.h"
#include <vector>

using namespace std;

class BaseDeDonnees{

	public:
	
	// Gestion de connection
	bool virtual ajouterConnection(Connection* connection);
	
	bool virtual retirerConnection(Connection* connection);
	
	void mettreAJourConnections();
	
	// Gestion de donnees
	virtual void mettreAJourDonnees() = 0;
		
	protected:
	
	// Connections à la base
	vector<Connection*> connections_;
};

#endif

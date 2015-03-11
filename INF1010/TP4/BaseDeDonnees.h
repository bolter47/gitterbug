#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include "Connection.h"

class BaseDeDonnees{

	public:
	
	// Gestion de connection
	bool ajouterConnection(*Connection connection);
	bool retirerConnection(*Connection connection);
	void mettreAJourConnections();
	// Gestion de donnees
	virtual void mettreAJourDonnees() = 0;
		
	protected:
	
	// Connections à la base
	vector<*Connections> connections_;
}

#endif

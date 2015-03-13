#ifndef	CONNECTION_H
#define CONNECTION_H

class BaseDeDonnees;

class Connection
{
public:
	// Destructeur virtual pour empêcher BaseDeDonnees de chialer
	virtual ~Connection(){
	};

	virtual void mettreAJourConnection(BaseDeDonnees* donnees) = 0;
};

#endif

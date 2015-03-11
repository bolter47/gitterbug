#ifndef	CONNECTION_H
#define CONNECTION_H

#include "BaseDeDonnees.h"

class Connection
{
public:
	virtual void mettreAJourConnection(BaseDeDonnees* donnees) = 0;
};

#endif

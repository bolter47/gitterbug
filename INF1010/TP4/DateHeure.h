#ifndef DATEHEURE_H
#define DATEHEURE_H

#include <ctime>
#include "BaseDeDonnees.h"

class DateHeure:BaseDeDonnees{
	
	public:
	
	// Constructeur
	DateHeure();
	
	// Méthodes d'accès
	int getHeure() 			const;
	int getMinute()			const;
	int getSeconde() 		const;
	int getJourMois() 		const;
	int getJourSemaine() 	const;
	int getMois() 			const;
	int getAnnee() 			const;
	
	// Redef de mise a jour
	void mettreAJourDonnees();
	
	private:
	
	// Attributs
	unsigned heure_, minute_, seconde_, jourMois_, jourSemaine_, mois_, annee_;

};


#endif

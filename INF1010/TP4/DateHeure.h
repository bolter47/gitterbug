#ifndef DATEHEURE_H
#define DATEHEURE_H

#include <ctime>
#include "BaseDeDonnees.h"

class DateHeure:BaseDeDonnees{
	
	public:
	
	// Constructeur
	DateHeure();
	
	// Méthodes d'accès
	void getHeure() 		const;
	void getMinute()		const;
	void getSeconde() 		const;
	void getJourMois() 		const;
	void getJourSemaine() 	const;
	void getMois() 			const;
	void getAnnee() 		const;
	
	// Redef de mise a jour
	void mettreAJourDonnees();
	
	private:
	
	// Attributs
	unsigned heure_, minute_, seconde_, jourMois_, jourSemaine_, mois_, annee_;

};


#endif

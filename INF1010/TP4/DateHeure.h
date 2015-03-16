#ifndef DATEHEURE_H
#define DATEHEURE_H

#include <ctime>
#include "BaseDeDonnees.h"

class DateHeure: public BaseDeDonnees{
	
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
	
	void setHeure(int heure);
	void setMinute(int minute);
	void setSeconde(int seconde);
	void setJourMois(int jourMois);
	void setJourSemaine(int jourSemaine);
	void setMois(int mois);
	void setAnnee(int annee);
	
	// Redef de mise a jour
	void mettreAJourDonnees();
	
	void mettreAJourConnections();
	
	private:
	// Attributs
	unsigned heure_, minute_, seconde_, jourMois_, jourSemaine_, mois_, annee_;

};


#endif

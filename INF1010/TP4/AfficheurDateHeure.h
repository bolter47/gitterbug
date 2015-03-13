#ifndef AFFICHEUR_DATE_HEURE_H
#define AFFICHEUR_DATE_HEURE_H

#include "Afficheur.h"
#include "Connection.h"
#include "DateHeure.h"
#include <string>

const string JOUR_STRING_FR[] = { "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };
const string MOIS_STRING_FR[] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

const string JOUR_STRING_EN[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
const string MOIS_STRING_EN[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

class AfficheurDateHeure: Afficheur, Connection{
	
	public:
	
	// Redefs Afficheage
	void afficherFrançais() const;
	void afficherAnglais()	const;
	string getTypeAfficheur() const;
	
	//Redefs Connection
	void mettreAJourConnection(BaseDeDonnees* donnees);
	
	private:
	
	DateHeure dateHeure_;
};

#endif

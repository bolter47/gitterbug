#ifndef METEO_H
#define METEO_H

#include "BaseDeDonnees.h"

class Meteo:BaseDeDonnees{
	
	public:
	
	/*** Constructeurs ***/
	// Par Défaut
	Meteo();
	// Par Params
	Meteo(float temperature, float vent, float visibilite);
	
	/*** Methodes d'acces ***/
	float getTemperature() const;
	float getVent() const;
	float getVisibilite() const;
	
	// Redef de mise a jour
	void mettreAJourDonnees();
	
	// Fonction ajoutée pour mise à jour
	float ajusterValeur(float ancienneValeur);
	
	/** PAS SÛR S'IL FAUT REDEF mettreAJourConnections() **/
	
	private:
	
	// Attributs Celsius, km/h, km
	float temperature_, vent_, visibilite_;
	

};

#endif

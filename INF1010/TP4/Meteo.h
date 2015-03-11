#ifndef METEO_H
#define METEO_H

#include "BaseDeDonnees.h"

class Meteo:BaseDeDonnees{
	
	public:
	
	// Constructeur
	Meteo(temperature = 0.f, vent = 0.f, visibilite = 0.f);
	
	// Methodes d'acces
	float getTemperature() const;
	float getVent() const;
	float getVisibilite() const;
	
	// Redef de mise a jour
	void mettreAJourDonnees();
	
	/** PAS SÛR S'IL FAUT REDEF mettreAJourConnections() **/
	
	private:
	
	// Attributs Celsius, km/h, km
	float temperature_, vent_, visibilite_;
	

}

#endif

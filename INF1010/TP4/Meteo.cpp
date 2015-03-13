# include "Meteo.h"
#include <cstdlib>

using namespace std;

	/*** Constructeurs ***/
	// Par Défaut
	Meteo::Meteo():	temperature_(0.f),
					vent_(0.f),
					visibilite_(0.f){
	}
	// Par Params
	Meteo::Meteo(float temperature, float vent, float visibilite):	
					temperature_(temperature),
					vent_(vent),
					visibilite_(visibilite){
	}

	/*** Methodes d'acces ***/
	float Meteo::getTemperature() const{
		return temperature_;
	}
	float Meteo::getVent() const{
		return vent_;
	}
	float Meteo::getVisibilite() const{
		return visibilite_;
	}

	// Redef de mise a jour
	void Meteo::mettreAJourDonnees(){
		temperature_ 	=	ajusterValeur(temperature_);
		vent_ 			=	ajusterValeur(vent_);
		visibilite_		=	ajusterValeur(visibilite_);	
		mettreAJourConnections();	
	}
	
	float Meteo::ajusterValeur(float ancienneValeur){
		// ancienneValeur - 20% + [0 à 40%]
		return ancienneValeur - ancienneValeur * 0.2 + ancienneValeur*(float(rand()%41)/100);
	}

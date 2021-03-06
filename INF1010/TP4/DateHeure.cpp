#include "DateHeure.h"
	
	// Constructeur
	DateHeure::DateHeure():
	heure_(0),
	minute_(0),
	seconde_(0),
	jourMois_(0),
	jourSemaine_(0),
	mois_(0),
	annee_(0)
	{
	}
	
	// Méthodes d'accès
	int DateHeure::getHeure() 		const{
		return heure_;
	}
	int DateHeure::getMinute()		const{
		return minute_;
	}
	int DateHeure::getSeconde() 		const{
		return seconde_;
	}
	int DateHeure::getJourMois() 		const{
		return jourMois_;
	}
	int DateHeure::getJourSemaine() 	const{
		return jourSemaine_;
	}
	int DateHeure::getMois() 			const{
		return mois_;
	}
	int DateHeure::getAnnee() 		const{
		return annee_;
	}
	
	//Méthodes de modification des attributs
	void DateHeure :: setHeure(int heure){
		heure_ = heure;
	}
	void DateHeure :: setMinute(int minute){
		minute_ = minute;
	}
	void DateHeure :: setSeconde(int seconde){
		seconde_ = seconde;
	}
	void DateHeure :: setJourMois(int jourMois){
		jourMois_ = jourMois;
	}
	void DateHeure :: setJourSemaine(int jourSemaine){
		jourSemaine_ = jourSemaine;
	}
	void DateHeure :: setMois(int mois){
		mois_ = mois;
	}
	void DateHeure :: setAnnee(int annee){
		annee_ = annee;
	}
	
	// Redef de mise a jour
void DateHeure::mettreAJourDonnees(){
	time_t raw;
	struct tm * timeInfo;
	
	time (&raw);
	timeInfo = localtime(&raw);
	
	heure_ = timeInfo->tm_hour;
	minute_ = timeInfo->tm_min;
	seconde_ = timeInfo->tm_sec;
	jourMois_ = timeInfo->tm_mday;
	mois_ = timeInfo->tm_mon;
	annee_ = timeInfo->tm_year;
	jourSemaine_ = timeInfo->tm_wday;
	
	mettreAJourConnections();
}

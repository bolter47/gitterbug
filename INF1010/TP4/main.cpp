#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include "AfficheurDateHeure.h"
#include "AfficheurMeteo.h"
#include "AfficheurMeteoStatistiques.h"
#include "Meteo.h"
#include "DateHeure.h"
#include "SiteMeteo.h"

int main()
{
	srand(time(0));

	//Creer un objet AfficheurDateHeure
	AfficheurDateHeure afficheurDH;

	//Creer un objet AfficheurMeteo
	AfficheurMeteo afficheurM;
	
	//Creer un objet AfficheurMeteoStatistiques
	AfficheurMeteoStatistiques afficheurMS;

	//Creer un objet Meteo avec son constructeur par parametres
	Meteo meteoParam(10.375, 100.15, 20.3);

	//Connecter les afficheurs AfficheurMeteo et AfficheurMeteoStatistiques a la base de donnees Meteo
	afficheurM.mettreAJourConnection(&meteoParam);
	afficheurMS.mettreAJourConnection(&meteoParam);
	
	//Creer un objet DateHeure
	DateHeure dateHeure;

	//Connecter l'afficheur AfficheurDateHeure a la base de donnees DateHeure
	afficheurDH.mettreAJourConnection(&dateHeure);

	//Creer un objet SiteMeteo
	SiteMeteo site;

	//Ajouter les afficheurs AfficheurDateHeure, AfficheurMeteo et AfficheurMeteoStatistiques
	site.ajouterAfficheur(&afficheurDH);
	site.ajouterAfficheur(&afficheurM);
	site.ajouterAfficheur(&afficheurMS);

	for (;;)
	{
		//Mettre a jour les donnees des objets DonneesMeteo et DateHeure
		meteoParam.mettreAJourDonnees();
		dateHeure.mettreAJourDonnees();

		//Afficher le site meteo 
		site.afficherSite();

		//Pesez sur la touche F pour afficher en francais
		if (GetAsyncKeyState(0x46))	//F
		{
			//Mettre la langue en francais
			site.setLangue(FRANCAIS);
			
		}

		//Pesez sur la touche A pour afficher en francais
		else if (GetAsyncKeyState(0x41)) //A
		{
			//Mettre la langue en Anglais
			site.setLangue(ANGLAIS);
			
		}


		Sleep(1000);
		system("cls");
	}


	return 0;
}

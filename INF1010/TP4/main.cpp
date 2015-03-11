#include <Windows.h>
#include <cstdlib>
#include <time.h>

int main()
{
	srand(time(0));

	//Creer un objet AfficheurDateHeure
	

	//Creer un objet AfficheurMeteo
	

	//Creer un objet AfficheurMeteoStatistiques
	

	//Creer un objet Meteo avec son constructeur par parametres
	

	//Connecter les afficheurs AfficheurMeteo et AfficheurMeteoStatistiques a la base de donnees Meteo
	

	//Creer un objet DateHeure
	

	//Connecter l'afficheur AfficheurDateHeure a la base de donnees DateHeure
	

	//Creer un objet SiteMeteo
	

	//Ajouter les afficheurs AfficheurDateHeure, AfficheurMeteo et AfficheurMeteoStatistiques
	

	for (;;)
	{
		//Mettre a jour les donnees des objets DonneesMeteo et DateHeure
		

		//Afficher le site meteo 


		//Pesez sur la touche F pour afficher en francais
		if (GetAsyncKeyState(0x46))	//F
		{
			//Mettre la langue en francais
			
		}

		//Pesez sur la touche A pour afficher en francais
		else if (GetAsyncKeyState(0x41)) //A
		{
			//Mettre la langue en Anglais
			
		}


		Sleep(1000);
		system("cls");
	}


	return 0;
}
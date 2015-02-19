#include "SystemeSecurite.h"
#include "PirateInformatique.h"

int main()
{
	//Creer le systeme de securite
	SystemeSecurite systeme;

	/////////////////////////////////////////////////////////////
	//Ajouter les regles suivantes:
	//
	//	niveau d'acces	Local		Periode
	//
	//	1,				"L-3589",	PERIODE_ACCES_MATIN
	RegleAcces(1, "L-3589", PERIODE_ACCES_MATIN);
	//	1,				"L-3587",	PERIODE_ACCES_MATIN
	RegleAcces(1, "L-3587", PERIODE_ACCES_MATIN);
	//	1,				"L-3588",	PERIODE_ACCES_MATIN
	RegleAcces(1, "L-3588", PERIODE_ACCES_MATIN);
	//
	//	5,				"L-3589",	PERIODE_ACCES_SOIR
	RegleAcces(5, "L-3589", PERIODE_ACCES_SOIR);
	//	5,				"L-3587",	PERIODE_ACCES_SOIR
	RegleAcces(5, "L-3587", PERIODE_ACCES_SOIR);
	//	5,				"L-3588",	PERIODE_ACCES_SOIR
	RegleAcces(5, "L-3588", PERIODE_ACCES_SOIR);
	//
	//	20,				"L-3589",	PERIODE_ACCES_NUIT
	RegleAcces(20, "L-3589", PERIODE_ACCES_NUIT);
	//	20,				"L-3587",	PERIODE_ACCES_NUIT
	RegleAcces(20, "L-3587", PERIODE_ACCES_NUIT);
	//	25,				"L-3588",	PERIODE_ACCES_NUIT
	RegleAcces(25, "L-3588", PERIODE_ACCES_NUIT);
	//
	//	10,				"L-4489",	PERIODE_ACCES_MATIN
	RegleAcces(10, "L-4489", PERIODE_ACCES_MATIN);
	//	10,				"L-4487",	PERIODE_ACCES_MATIN
	RegleAcces(10, "L-4487", PERIODE_ACCES_MATIN);
	//
	//	10,				"L-4489",	PERIODE_ACCES_SOIR
	RegleAcces(10, "L-4489", PERIODE_ACCES_SOIR);
	//	10,				"L-4487",	PERIODE_ACCES_SOIR
	RegleAcces(10, "L-4487", PERIODE_ACCES_SOIR);
	//
	//	20,				"L-4489",	PERIODE_ACCES_NUIT
	RegleAcces(20, "L-4489", PERIODE_ACCES_NUIT);
	//	25,				"L-4487",	PERIODE_ACCES_NUIT
	RegleAcces(25, "L-4487", PERIODE_ACCES_NUIT);
	//
	////////////////////////////////////////////////////////////
	
	//Creer un agent de securite
	//
	//	nom: Nelson
	//  prenom: Garry
	//
	AgentSecurite agent("Nelson", "Garry");
    // afficher les infos de l'agent de sécurité (operator <<)
	cout << agent;
	//Creer un professeur
	//
	//	nom: Rios
	//  prenom: Janet
	//
	Professeur professeur("Rios", "Janet");
	// afficher les infos du professeur (operator <<)
	cout << professeur;
	//Creer un etudiant
	//
	//	nom: Ball
	//  prenom: Damon
	//
	Etudiant etudiant("Ball", "Damon");
	// afficher les infos de l'étudiant (operator <<)
	cout << etudiant;

	

	//Cree un pirate Informatique qui prendra l'identite 
	//du gardien de securite
	PirateInformatique pirate(agent);
	

	//L'agent de securite tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	cout << systeme.accederLocal(agent, "L-3587", PERIODE_ACCES_NUIT) << endl;
	//	"L-4489",	PERIODE_ACCES_SOIR
	cout << systeme.accederLocal(agent, "L-4489", PERIODE_ACCES_SOIR) << endl;
	//	"L-4487",	PERIODE_ACCES_NUIT
	cout << systeme.accederLocal(agent, "L-4487", PERIODE_ACCES_NUIT) << endl;
	//
	//
	
	

	//Le professeur tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_MATIN
	cout << systeme.accederLocal(professeur, "L-3587", PERIODE_ACCES_MATIN) << endl;
	//	"L-4489",	PERIODE_ACCES_NUIT
	cout << systeme.accederLocal(professeur, "L-4489", PERIODE_ACCES_NUIT) << endl;
	//	"L-4487",	PERIODE_ACCES_SOIR
	cout << systeme.accederLocal(professeur, "L-4487", PERIODE_ACCES_SOIR) << endl;
	//
	//
	


	//L'etudiant tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3589",	PERIODE_ACCES_MATIN
	cout << systeme.accederLocal(etudiant, "L-3589", PERIODE_ACCES_MATIN) << endl;
	//	"L-4489",	PERIODE_ACCES_NUIT
	cout << systeme.accederLocal(etudiant, "L-4489", PERIODE_ACCES_MATIN) << endl;
	//	"L-3589",	PERIODE_ACCES_SOIR
	cout << systeme.accederLocal(etudiant, "L-3589", PERIODE_ACCES_MATIN) << endl;
	//
	//
	


	//Le pirate informatique tente d'acceder aux locaux suivants a l'aide de la fonction suivante:
	//
	//	bool accederLocal(string nom, string prenom, string fonction, unsigned int niveauAcces, string local, string periode);
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	cout << systeme.accederLocal(pirate, "L-3587", PERIODE_ACCES_NUIT) << endl;
	//	"L-4489",	PERIODE_ACCES_SOIR
	cout << systeme.accederLocal(pirate, "L-4489", PERIODE_ACCES_SOIR) << endl;
	//	"L-4487",	PERIODE_ACCES_NUIT
	cout << systeme.accederLocal(pirate, "L-4487", PERIODE_ACCES_NUIT) << endl;
	//
	//
	


	//Afficher le journal d'acces du systeme de securite
	systeme.imprimerJournal();


	return 0;
}


//Reponse a la question:
//	
//	
//	Employe* etudiant = new Etudiant("Ball", "Damon");
//
//	sysSecu.accederLocal	(	etudiant->getNom(), 
//								etudiant->getPrenom(), 
//								etudiant->getFonction(), 
//								etudiant->getNiveauAcces(), 
//								"L-3589", 
//								PERIODE_ACCES_NUIT
//							);
//
//	delete etudiant;
//	
//	
//	
//	

/*
suggestion trim

*etudiant = AgentSecurite(etudiant.getNom(), etudiant.getPrenom());

*agent = *etudiant

*/



/********************************************************************
 Fichier: main.cpp
 Auteur: Konstantinos Lambrou-Latreille
 Description: 
	Fichier main qui contient l'ex�cution principale du TP1 de INF1010.
	Bien lire les commentaires et coder les instructions.
********************************************************************/

#include <iostream>
#include "Ecole.h"
#include "Etudiant.h"
#include "Professeur.h"
#include "Section.h"

using namespace std;

int main()
{
	cout << endl;
	
	// 1) Cr�er automatiquement un objet Ecole avec son constructeur par d�faut
	//    et modifier ses attributs :
	//	  nom="�cole Polytechnique de Montr�al"
	//	  adresse="2900 Boulevard Edouard-Montpetit, Montr�al, Qu�bec H3T 1J4"
	Ecole poly;
	poly.setNom("�cole Polytechnique de Montr�al");
	poly.setAdresse("2900 Boulevard Edouard-Montpetit, Montr�al, Qu�bec H3T 1J4");


	// 2) Cr�er dynamiquement un objet Ecole avec son constructeur par param�tres
	//    et modifier ses attributs :
	//	  nom="Universit� de Qu�bec � Montr�al"
	//	  adresse="405 Rue Sainte-Catherine Est, Montr�al, Qu�bec H2L 2C4"
	Ecole* uqam = new Ecole("Universit� de Qu�bec � Montr�al", "405 Rue Sainte-Catherine Est, Montr�al, Qu�bec H2L 2C4");


	// 3) Cr�er automatiquement un objet Professeur avec son constructeur par d�faut.
	//    et modifier les arguments suivants:
	//		matricule="p12"
	//		prenom="Jean-Martin"
	//		nom="Aussant"
	//		departement="D�partement de science �conomique"
	Professeur pJMA;
	pJMA.setnEmploye("p12");
	pJMA.setPrenom("Jean-Martin");
	pJMA.setNom("Aussant");
	pJMA.setDepartement("D�partement de science �conomique");


	// 4) Cr�er dynamiquement un objet Professeur avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		matricule="p13"
	//		prenom="Chahira"
	//		nom="Bechiri"
	//		departement="D�partement de science informatique"
	Professeur* pCB = new Professeur("p13", "Bechiri", "Chahira", "D�partement de science informatique");


	// 5) Cr�er dynamiquement un objet Professeur avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		matricule="p14"
	//		prenom="Samuel"
	//		nom="Kadoury"
	//		departement="D�partement de g�nie informatique et logiciel"
	Professeur* pSK = new Professeur("p14", "Kadoury", "Samuel", "D�partement de g�nie informatique et logiciel");


	// 6) Cr�er dynamiquement un objet Professeur avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		matricule="p15"
	//		prenom="Michel"
	//		nom="Gagnon"
	//		departement="D�partement de g�nie informatique et logiciel"
	Professeur* pMG = new Professeur("p15", "Gagnon", "Michel", "D�partement de g�nie informatique et logiciel");
	


	// 7) Cr�er automatiquement un objet Etudiant avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		matricule="1510301"
	//		prenom="Konstantinos"
	//		nom="Lambrou-Latreille"
	Etudiant eKLL = Etudiant("1510301", "Konstantinos", "Lambrou-Latreille");


	// 8) Cr�er automatiquement un objet Etudiant avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		matricule="1475812"
	//		prenom="Kahina"
	//		nom="Bechiri"
	Etudiant eKB = Etudiant("1475812", "Kahina", "Bechiri"); 


	// 9) Cr�er automatiquement un objet Etudiant avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		matricule="1506813"
	//		prenom="Mathieu"
	//		nom="Fafard"
	Etudiant eMF = Etudiant("1506813", "Mathieu", "Fafard");


	// 10) Cr�er automatiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF1000"
	//		local="C215"
	//		titre="�conomie 101"
	//		prof=p12 - Jean-Martin Aussant
	Section econo101 = Section("ISF1000", "C215", "�conomie 101", &pJMA);


	// 11) Ajouter le deuxi�me �tudiant au cours ISF1000.
	econo101.ajouterEtudiant(eKB);


	// 12) Cr�er dynamiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF2000"
	//		local="C214"
	//		titre="�tude en science cognitive"
	//		prof=p13 - Chahira Bechiri
	Section* sciCogn = new Section("ISF2000", "C214", "�tude en science cognitive", pCB);


	// 13) Ajouter le premier et le deuxi�me �tudiant au cours ISF2000.
	sciCogn -> ajouterEtudiant(eKLL);
	sciCogn -> ajouterEtudiant(eKB);


	// 14) Cr�er automatiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="INF1010"
	//		local="L6614"
	//		titre="Programmation orient�e-objet"
	//		prof=p14 - Samuel Kadoury
	Section progOO = Section("INF1010", "L6614", "Programmation orient�e-objet", pSK);

	// 15) Ajouter le premier et le troisi�me �tudiant au cours INF1010.
	
	progOO.ajouterEtudiant(eKLL);
	progOO.ajouterEtudiant(eMF);


	// 16) Cr�er dynamiquement un objet Section avec son constructeur par param�tre.
	//    Utiliser les arguments suivants:
	//		sigle="LOG4420"
	//		local="M6410"
	//		titre="Conception de sites web dynamiques et transactionnels"
	//		prof=p15 - Michel Gagnon
	Section* concWeb = new Section("LOG4420", "M6410", "Conception de sites web dynamiques et transactionnels", pMG);


	// 17) Ajouter le premier, le deuxi�me et le troisi�me �tudiant au cours LOG4420.
	concWeb -> ajouterEtudiant(eKLL);
	concWeb -> ajouterEtudiant(eKB);
	concWeb -> ajouterEtudiant(eMF);


	// 18) Ajouter le cours INF1010 et le cours LOG4420 � l'�cole Polytechnique.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section INF1010 et LOG4420 � l'�cole Polytechnique" << endl;
	cout << "===============================================" << endl;
	poly.ajouterSection(&progOO);
	poly.ajouterSection(concWeb);



	// 19) Ajouter le cours ISF1000 � l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF1000 � l'UQAM" << endl;
	cout << "===============================================" << endl;
	uqam->ajouterSection(&econo101);

	// 20) Modifier le local du cours ISF2000 vers le local A250.
	// 21) Ajouter le cours ISF2000 � l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF2000 � l'UQAM" << endl;
	cout << "===============================================" << endl;
	sciCogn->setLocal("A250");
	uqam->ajouterSection(sciCogn);

	// 22) Supprimer le cours ISF2000 de l'UQAM
	cout << endl << "===============================================" << endl;
	cout << "On supprime la section ISF2000 � l'UQAM" << endl;
	cout << "===============================================" << endl;
	uqam->supprimerSection("ISF2000","A250");

	// 23) Afficher les deux �coles cr��es.
	poly.afficher();
	uqam->afficher();
	
	cout << "afficheage termin�" << endl;

	// 24) Lib�rer la m�moire
	poly.~Ecole();
	cout << "Poly a explos�";
	delete uqam;
	cout << " et l'uqam aussi" << endl;
	
	return 0;
}

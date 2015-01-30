/********************************************************************
 Fichier: main.cpp
 Auteur: Konstantinos Lambrou-Latreille
 Description: 
	Fichier main qui contient l'exécution principale du TP1 de INF1010.
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
	
	// 1) Créer automatiquement un objet Ecole avec son constructeur par défaut
	//    et modifier ses attributs :
	//	  nom="École Polytechnique de Montréal"
	//	  adresse="2900 Boulevard Edouard-Montpetit, Montréal, Québec H3T 1J4"
	Ecole poly;
	poly.setNom("École Polytechnique de Montréal");
	poly.setAdresse("2900 Boulevard Edouard-Montpetit, Montréal, Québec H3T 1J4");


	// 2) Créer dynamiquement un objet Ecole avec son constructeur par paramètres
	//    et modifier ses attributs :
	//	  nom="Université de Québec à Montréal"
	//	  adresse="405 Rue Sainte-Catherine Est, Montréal, Québec H2L 2C4"
	Ecole* uqam = new Ecole("Université de Québec à Montréal", "405 Rue Sainte-Catherine Est, Montréal, Québec H2L 2C4");


	// 3) Créer automatiquement un objet Professeur avec son constructeur par défaut.
	//    et modifier les arguments suivants:
	//		matricule="p12"
	//		prenom="Jean-Martin"
	//		nom="Aussant"
	//		departement="Département de science économique"
	Professeur pJMA;
	pJMA.setnEmploye("p12");
	pJMA.setPrenom("Jean-Martin");
	pJMA.setNom("Aussant");
	pJMA.setDepartement("Département de science économique");


	// 4) Créer dynamiquement un objet Professeur avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="p13"
	//		prenom="Chahira"
	//		nom="Bechiri"
	//		departement="Département de science informatique"
	Professeur* pCB = new Professeur("p13", "Bechiri", "Chahira", "Département de science informatique");


	// 5) Créer dynamiquement un objet Professeur avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="p14"
	//		prenom="Samuel"
	//		nom="Kadoury"
	//		departement="Département de génie informatique et logiciel"
	Professeur* pSK = new Professeur("p14", "Kadoury", "Samuel", "Département de génie informatique et logiciel");


	// 6) Créer dynamiquement un objet Professeur avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="p15"
	//		prenom="Michel"
	//		nom="Gagnon"
	//		departement="Département de génie informatique et logiciel"
	Professeur* pMG = new Professeur("p15", "Gagnon", "Michel", "Département de génie informatique et logiciel");
	


	// 7) Créer automatiquement un objet Etudiant avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="1510301"
	//		prenom="Konstantinos"
	//		nom="Lambrou-Latreille"
	Etudiant eKLL = Etudiant("1510301", "Konstantinos", "Lambrou-Latreille");


	// 8) Créer automatiquement un objet Etudiant avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="1475812"
	//		prenom="Kahina"
	//		nom="Bechiri"
	Etudiant eKB = Etudiant("1475812", "Kahina", "Bechiri"); 


	// 9) Créer automatiquement un objet Etudiant avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="1506813"
	//		prenom="Mathieu"
	//		nom="Fafard"
	Etudiant eMF = Etudiant("1506813", "Mathieu", "Fafard");


	// 10) Créer automatiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF1000"
	//		local="C215"
	//		titre="Économie 101"
	//		prof=p12 - Jean-Martin Aussant
	Section econo101 = Section("ISF1000", "C215", "Économie 101", &pJMA);


	// 11) Ajouter le deuxième étudiant au cours ISF1000.
	econo101.ajouterEtudiant(eKB);


	// 12) Créer dynamiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF2000"
	//		local="C214"
	//		titre="Étude en science cognitive"
	//		prof=p13 - Chahira Bechiri
	Section* sciCogn = new Section("ISF2000", "C214", "Étude en science cognitive", pCB);


	// 13) Ajouter le premier et le deuxième étudiant au cours ISF2000.
	sciCogn -> ajouterEtudiant(eKLL);
	sciCogn -> ajouterEtudiant(eKB);


	// 14) Créer automatiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="INF1010"
	//		local="L6614"
	//		titre="Programmation orientée-objet"
	//		prof=p14 - Samuel Kadoury
	Section progOO = Section("INF1010", "L6614", "Programmation orientée-objet", pSK);

	// 15) Ajouter le premier et le troisième étudiant au cours INF1010.
	
	progOO.ajouterEtudiant(eKLL);
	progOO.ajouterEtudiant(eMF);


	// 16) Créer dynamiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="LOG4420"
	//		local="M6410"
	//		titre="Conception de sites web dynamiques et transactionnels"
	//		prof=p15 - Michel Gagnon
	Section* concWeb = new Section("LOG4420", "M6410", "Conception de sites web dynamiques et transactionnels", pMG);


	// 17) Ajouter le premier, le deuxième et le troisième étudiant au cours LOG4420.
	concWeb -> ajouterEtudiant(eKLL);
	concWeb -> ajouterEtudiant(eKB);
	concWeb -> ajouterEtudiant(eMF);


	// 18) Ajouter le cours INF1010 et le cours LOG4420 à l'École Polytechnique.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section INF1010 et LOG4420 à l'École Polytechnique" << endl;
	cout << "===============================================" << endl;
	poly.ajouterSection(&progOO);
	poly.ajouterSection(concWeb);



	// 19) Ajouter le cours ISF1000 à l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF1000 à l'UQAM" << endl;
	cout << "===============================================" << endl;
	uqam->ajouterSection(&econo101);

	// 20) Modifier le local du cours ISF2000 vers le local A250.
	// 21) Ajouter le cours ISF2000 à l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF2000 à l'UQAM" << endl;
	cout << "===============================================" << endl;
	sciCogn->setLocal("A250");
	uqam->ajouterSection(sciCogn);

	// 22) Supprimer le cours ISF2000 de l'UQAM
	cout << endl << "===============================================" << endl;
	cout << "On supprime la section ISF2000 à l'UQAM" << endl;
	cout << "===============================================" << endl;
	uqam->supprimerSection("ISF2000","A250");

	// 23) Afficher les deux écoles créées.
	poly.afficher();
	uqam->afficher();
	
	cout << "afficheage terminé" << endl;

	// 24) Libérer la mémoire
	poly.~Ecole();
	cout << "Poly a explosé";
	delete uqam;
	cout << " et l'uqam aussi" << endl;
	
	return 0;
}

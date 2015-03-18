
#include <vector>
#include <iostream>
#include "Foncteur.h"
#include "PanierArticles.h"
#include "Commerce.h"

using namespace std;

int main() {
	// 1) Créer une classe PanierArticle avec un id quelconque.

    
	// 2) Ajouter les articles suivants dans le panier
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$
	// Article 2 -> id = 2, nom = Film, prix = 34.97$
	// Article 3 -> id = 3, nom = Accessoire, prix = 12.12$
	// Article 4 -> id = 4, nom = Article bizarre, prix = 0.0$
	// Article 5 -> id = 5, nom = Mauvais article, prix = 0.0$

    
	// Afficher le panier avec l'opérateur <<

    
	// 3) Afficher la moyenne des prix des articles du panier

    
	// 4) Afficher l'id de l'article le moins cher et l'id de l'article le plus cher

    
	// 5) Supprimer l'article avec id = 2.
	cout << "Supprimer l'article avec id = 2..." << endl << endl;

    
	// 6) Supprimer les articles qui ont un prix == 0. Créer un foncteur FoncteurPrixZero
	// et le passer en paramètre dans la méthode supprimer.
	cout << "Supprimer les articles avec un prix = 0..." << endl << endl;

    
	// 7) Afficher de nouveau le panier
	cout << "Afficher de nouveau le panier..." << endl;

    
	// 8) Appeller la fonction trier du panier et afficher la liste d'article obtenue avec
	// la fonction for_each.
	cout << "Trier le panier" << endl;
	cout << "=============================" << endl;
    // ...
	cout << "=============================" << endl << endl << endl;

    
	// 9) Créer un nouveau panier avec id = 2.

    
	// 10) Ajouter les articles suivants dans ce panier:
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$ (reprendre celui créer plus haut)
	// Article 6 -> id = 6, nom = Laptop, prix = 400.0$


	// 11) Créer les clients suivants:
	// Client 1 -> id = 1, nom = Doe, prenom = John
	// Client 2 -> id = 2, nom = Tremblay, prenom = Martin


	cout << "*********** COMMERCE ***********" << endl;
	// 12) Créer un commerce et ajouter deux commandes
	// Commande 1 -> John Doe avec panier 1
	// Commande 2 -> Martin Tremblay avec panier 2


	// 13) Afficher les commandes par ordre alphabétique
	cout << "************* Affichage alphabetique ****************" << endl;


	// 14) Afficher les commandes en ordre décroissant par le prix moyen des panier
	cout << "************* Affichage prix moyen decroissant **************" << endl;


	// 15) Appliquer 10% de rabais sur le panier de Martin. 
	cout << "*********** Affichage apres modifications ***********" << endl;


	// 16) Créer l'article suivant:
	// Article 7 -> id = 7, nom = "Bureau", prix = 200


	// 17) Ajouter l'article 7 au panier de John


	// 18) Supprimer l'article 3 de John


	// 19) Afficher les commandes en ordre décroissant par le prix moyen des panier


	// 20) Supprimer la commande de Martin et afficher les commandes en ordre alphabétique
	cout << "******** Affichage apres suppression commande ************" << endl;


	// 21) Libérer la mémoire (si nécessaire)


	return 0;
}

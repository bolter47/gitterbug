
#include <vector>
#include <iostream>
#include <iomanip>
#include "PanierArticle.h"
#include "Commerce.h"

using namespace std;

class foncteurPrixZero{
	public:
	foncteurPrixZero(){};
	bool operator()(Article* article){
		return article -> getPrix() == 0;
	}
};

int main() {
	
	// 1) Cr�er une classe PanierArticle avec un id quelconque.
	PanierArticle panier1(1001);
    
	// 2) Ajouter les articles suivants dans le panier
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$
	// Article 2 -> id = 2, nom = Film, prix = 34.97$
	// Article 3 -> id = 3, nom = Accessoire, prix = 12.12$
	// Article 4 -> id = 4, nom = Article bizarre, prix = 0.0$
	// Article 5 -> id = 5, nom = Mauvais article, prix = 0.0$
	Article* article1 = new Article(1, "Livre", 32.73);
	panier1.ajouter(article1);
	Article* article2 = new Article(2, "Film", 34.97);
	panier1.ajouter(article2);
	Article* article3 = new Article(3, "Accessoire", 12.12);
	panier1.ajouter(article3);
	Article* article4 = new Article(4, "Article bizarre", 0.f);
	panier1.ajouter(article4);
	Article* article5 = new Article(5, "Mauvais article", 0.f);
	panier1.ajouter(article5);

    
	// Afficher le panier avec l'op�rateur <<
	cout << panier1;
	

    
	// 3) Afficher la moyenne des prix des articles du panier
	cout <<"La moyenne des prix est de : " << panier1.obtenirMoyenne() << "$" << endl;

    
	// 4) Afficher l'id de l'article le moins cher et l'id de l'article le plus cher
	cout << "L'article le moins cher est le #" << panier1.obtenirPlusPetitElement().getID() << endl;
	cout << "L'article le plus cher est le #" << panier1.obtenirPlusGrandElement().getID() << endl;

    
	// 5) Supprimer l'article avec id = 2.
	cout << "Supprimer l'article avec id = 2..." << endl << endl << endl;
	unsigned int val = 2;
	panier1.supprimer(val);
	

    
	// 6) Supprimer les articles qui ont un prix == 0. Cr�er un foncteur FoncteurPrixZero
	// et le passer en param�tre dans la m�thode supprimer.
	cout << "Supprimer les articles avec un prix = 0..." << endl << endl;
	foncteurPrixZero foncteurSuppr;
	panier1.supprimer<foncteurPrixZero>(foncteurSuppr);
    
	// 7) Afficher de nouveau le panier
	cout << "Afficher de nouveau le panier..." << endl;
	cout << panier1;

    
	// 8) Appeller la fonction trier du panier et afficher la liste d'article obtenue avec
	// la fonction for_each.
	cout << "Trier le panier" << endl;
	list<Article*> listeTest = panier1.trier();
	cout << "Debut listeTest : " << *listeTest.begin() << endl << "Fin listeTest : " << *listeTest.end() << endl;
	cout << "=============================" << endl;
    // proc�de au for_each en utilisant afficheurContenu
    for_each(listeTest.begin(), listeTest.end(), afficheurContenu<Article*>(&cout));
	cout << "=============================" << endl << endl << endl;

    
	// 9) Cr�er un nouveau panier avec id = 2.
	PanierArticle panier2(2);
    
	// 10) Ajouter les articles suivants dans ce panier:
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$ (reprendre celui cr�er plus haut)
	// Article 6 -> id = 6, nom = Laptop, prix = 400.0$
	panier2.ajouter(article1);
	Article* article6 = new Article(6, "Laptop", 400.f);
	panier2.ajouter(article6);

	// 11) Cr�er les clients suivants:
	// Client 1 -> id = 1, nom = Doe, prenom = John
	// Client 2 -> id = 2, nom = Tremblay, prenom = Martin
	Client johnDoe(1, "Doe", "John", 0.f);
	Client martinTremblay(2, "Tremblay", "Martin", 0.f);


	cout << "*********** COMMERCE ***********" << endl;
	// 12) Cr�er un commerce et ajouter deux commandes
	// Commande 1 -> John Doe avec panier 1
	// Commande 2 -> Martin Tremblay avec panier 2
	Commerce magasin;
	magasin.ajouterCommande(johnDoe, &panier1);
	magasin.ajouterCommande(martinTremblay, &panier2);


	// 13) Afficher les commandes par ordre alphab�tique
	cout << "************* Affichage alphabetique ****************" << endl;
	magasin.afficherParOrdreAlphabetique();

	// 14) Afficher les commandes en ordre d�croissant par le prix moyen des panier
	cout << "************* Affichage prix moyen decroissant **************" << endl;
	magasin.afficherParPrixMoyenDecroissant();

	// 15) Appliquer 10% de rabais sur le panier de Martin. 
	magasin.appliquerRabais(martinTremblay, foncteurRabais(10));
	cout << "*********** Affichage apres modifications ***********" << endl;

	// 16) Cr�er l'article suivant:
	// Article 7 -> id = 7, nom = "Bureau", prix = 200


	// 17) Ajouter l'article 7 au panier de John


	// 18) Supprimer l'article 3 de John


	// 19) Afficher les commandes en ordre d�croissant par le prix moyen des panier


	// 20) Supprimer la commande de Martin et afficher les commandes en ordre alphab�tique
	cout << "******** Affichage apres suppression commande ************" << endl;


	// 21) Lib�rer la m�moire (si n�cessaire)


	return 0;
}

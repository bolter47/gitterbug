#include <iostream>
#include <vector>
#include "Panier.h"

using namespace std;

int main()
{
	// 1. Créer un panier vide panierUn
	Panier panierUn;

	// 2. Créer quelques articles (au moins trois) avec  les constructeurs et 
	// l'opérateur >>
	//Création de l'objet epee
	Article epee(101, "Epee longue", 199.99);
	// Création de l'objet bouclier
	Article bouclier;
	cout << "Veuillez entrer les infos pour l'article bouclier" << endl;
	cin >> bouclier;
	//Création d'un objet Article vide
	Article vide;
	
	cout << "PANIER 1: Fin de creation des articles"  << endl;

	// 3. Ajouter les articles au panier
	panierUn += epee;
	panierUn += bouclier;
	panierUn += vide;
	
	cout << "PANIER 1: Fin de l'ajout des articles"  << endl;

	// 4. Afficher le panier
	cout << panierUn;

	// 5. Créer d'autres articles (au moins deux) et les placer dans un vecteur
	Article casque(104, "Casque", 90.45);
	Article armure(105, "Cote de maille", 279.99);
	vector<Article> kitArmure(2);
	kitArmure[0] = casque;
	kitArmure[1] = armure;
	cout << "PANIER 2: Creation du vecteur d'articles complete"  << endl;
	
	// 6. Créer un panierDeux qui contient initialement les articles du vecteur créé en 5
	Panier panierDeux(kitArmure);
	cout << "PANIER 2: Creation du panier a partir du vecteur"  << endl;

	// 7. Créer un panierTrois qui contient l'ensemble des articles du panierUn et du panierDeux (+)
	Panier panierTrois = panierUn + panierDeux;
	cout << "PANIER 3: Creation du panier 3 a partir de 1 et 2"  << panierTrois;

	// 8. Retirer un article créé en 2 du panierTrois avec l'operateur -=
	panierTrois -= vide;
	cout << "PANIER 3: Soustraction de l'objet vide" << endl;

	// 9. Afficher le panierTrois
	cout << panierTrois;

	// 10. Créer un panierQuatre vide puis lui assigner le second panier
	Panier panierQuatre = panierDeux;
	cout << "PANIER 4: Creation et assignation du panier 2" << endl << panierQuatre;
	

	// 11. Ajouter au panierQuatre  un article en utilisant uniquement un id (non utilisé précédement)
	Article tampon(22);
	panierQuatre += tampon;
	cout << "PANIER 4: Addition d'un article vide #22" << endl;

	// 12. Afficher le panierQuatre
	cout << panierQuatre;
	cout << "PANIER 4: fin du COUT" << endl;

	// 13. Créer un panierCinq vide
	Panier panierCinq;
	cout << "PANIER 5: Initialise" << endl;

	// 14. Effectuer l'opération "panierCinq = article + panierQuatre" puis afficher le panier 5
	panierCinq = bouclier + panierQuatre;
	cout << panierCinq;

	// 15. Créer un panierSix vide et ajouter au moins  4 articles.
	Panier panierSix;
	panierSix += epee;
	panierSix += bouclier;
	panierSix += panierDeux;

	// 16. créer un panierSept vide
	Panier panierSept;

	//  17. Effectuer l'opération panierSept = panierSix  - panierCinq 
	panierSept = panierSix  - panierCinq;
	
	//  18. Afficher le panierSept
	cout << panierSept;

	return 0;
}

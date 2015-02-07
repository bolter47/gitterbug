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

	// 3. Ajouter les articles au panier
	panierUn += epee;
	panierUn += bouclier;
	panierUn += vide;

	// 4. Afficher le panier
	cout << "PANIER 1:" << endl << panierUn;

	// 5. Créer d'autres articles (au moins deux) et les placer dans un vecteur
	Article casque(104, "Casque", 90.45);
	Article armure(105, "Cote de maille", 279.99);
	vector<Article> kitArmure(2);
	kitArmure[0] = casque;
	kitArmure[1] = armure;
	
	// 6. Créer un panierDeux qui contient initialement les articles du vecteur créé en 5
	Panier panierDeux(kitArmure);

	// 7. Créer un panierTrois qui contient l'ensemble des articles du panierUn et du panierDeux (+)
	Panier panierTrois = panierUn + panierDeux;

	// 8. Retirer un article créé en 2 du panierTrois avec l'operateur -=
	panierTrois -= vide;

	// 9. Afficher le panierTrois
	cout << "PANIER 3:" << endl << panierTrois;

	// 10. Créer un panierQuatre vide puis lui assigner le second panier
	Panier panierQuatre = panierDeux;
	

	// 11. Ajouter au panierQuatre  un article en utilisant uniquement un id (non utilisé précédement)
	Article tampon(22);
	panierQuatre += tampon;

	// 12. Afficher le panierQuatre
	cout << "PANIER 4:" << endl << panierQuatre;

	// 13. Créer un panierCinq vide
	Panier panierCinq;

	// 14. Effectuer l'opération "panierCinq = article + panierQuatre" puis afficher le panier 5
	panierCinq = bouclier + panierQuatre;
	cout << "PANIER 5" << endl << panierCinq;

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
	cout << "PANIER 7" << endl << panierSept;

	return 0;
}

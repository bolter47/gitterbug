#include <iostream>
#include <vector>
#include "Panier.h"

using namespace std;

int main()
{
	// 1. Cr�er un panier vide panierUn
	Panier panierUn;

	// 2. Cr�er quelques articles (au moins trois) avec  les constructeurs et 
	// l'op�rateur >>
	//Cr�ation de l'objet epee
	Article epee(101, "Epee longue", 199.99);
	// Cr�ation de l'objet bouclier
	Article bouclier;
	cout << "Veuillez entrer les infos pour l'article bouclier" << endl;
	cin >> bouclier;
	//Cr�ation d'un objet Article vide
	Article vide;
	
	cout << "PANIER 1: Fin de creation des articles"  << endl;

	// 3. Ajouter les articles au panier
	panierUn += epee;
	panierUn += bouclier;
	panierUn += vide;
	
	cout << "PANIER 1: Fin de l'ajout des articles"  << endl;

	// 4. Afficher le panier
	cout << panierUn;

	// 5. Cr�er d'autres articles (au moins deux) et les placer dans un vecteur
	Article casque(104, "Casque", 90.45);
	Article armure(105, "Cote de maille", 279.99);
	vector<Article> kitArmure(2);
	kitArmure[0] = casque;
	kitArmure[1] = armure;
	cout << "PANIER 2: Creation du vecteur d'articles complete"  << endl;
	
	// 6. Cr�er un panierDeux qui contient initialement les articles du vecteur cr�� en 5
	Panier panierDeux(kitArmure);
	cout << "PANIER 2: Creation du panier a partir du vecteur"  << endl;

	// 7. Cr�er un panierTrois qui contient l'ensemble des articles du panierUn et du panierDeux (+)
	Panier panierTrois = panierUn + panierDeux;
	cout << "PANIER 3: Creation du panier 3 a partir de 1 et 2"  << panierTrois;

	// 8. Retirer un article cr�� en 2 du panierTrois avec l'operateur -=
	panierTrois -= vide;
	cout << "PANIER 3: Soustraction de l'objet vide" << endl;

	// 9. Afficher le panierTrois
	cout << panierTrois;

	// 10. Cr�er un panierQuatre vide puis lui assigner le second panier
	Panier panierQuatre = panierDeux;
	cout << "PANIER 4: Creation et assignation du panier 2" << endl << panierQuatre;
	

	// 11. Ajouter au panierQuatre  un article en utilisant uniquement un id (non utilis� pr�c�dement)
	Article tampon(22);
	panierQuatre += tampon;
	cout << "PANIER 4: Addition d'un article vide #22" << endl;

	// 12. Afficher le panierQuatre
	cout << panierQuatre;
	cout << "PANIER 4: fin du COUT" << endl;

	// 13. Cr�er un panierCinq vide
	Panier panierCinq;
	cout << "PANIER 5: Initialise" << endl;

	// 14. Effectuer l'op�ration "panierCinq = article + panierQuatre" puis afficher le panier 5
	panierCinq = bouclier + panierQuatre;
	cout << panierCinq;

	// 15. Cr�er un panierSix vide et ajouter au moins  4 articles.
	Panier panierSix;
	panierSix += epee;
	panierSix += bouclier;
	panierSix += panierDeux;

	// 16. cr�er un panierSept vide
	Panier panierSept;

	//  17. Effectuer l'op�ration panierSept = panierSix  - panierCinq 
	panierSept = panierSix  - panierCinq;
	
	//  18. Afficher le panierSept
	cout << panierSept;

	return 0;
}

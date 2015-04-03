#ifndef COMMERCE_H
#define COMMERCE_H

#include "Client.h"
#include "Panier.h"
#include "Article.h"
#include "PanierArticle.h"
#include <map>
#include <iostream>


using namespace std;


class foncteurAffichagePanier{
	public:
		foncteurAffichagePanier();
		void operator()(PanierArticle* panier)
		{
			cout << *panier;
		}
};

class foncteurRabais{
	public:
		foncteurRabais(float rabais);
		void operator()(PanierArticle* panier)
		{
			((panier->sommeArticles) * (pourcentageRabais_ / 100));
		}
	private:
		float pourcentageRabais_;
};

class Commerce 
{
	public:
		bool estPresent(Client client);
		bool ajouterCommande(Client client, PanierArticle* panier);
		bool ajouterArticle(Client client, Article* article);
		bool supprimerCommande(Client client);
		bool supprimerArticleCommande(Client client, Article* article);
		void appliquerRabais(Client client, foncteurRabais());
		void afficher(Client client);
		void afficher(unsigned int idClient);
		void afficherParOrdreAlphabetique()	const;
		void afficherParPrixMoyenDecroissant()	const;

	private:
		map<unsigned int, PanierArticle*> mapClientPanier_;
		typedef map<unsigned int, PanierArticle*> ::const_iterator IterateurConst;
};

#endif
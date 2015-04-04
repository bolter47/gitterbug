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
		void operator()(pair<unsigned int, PanierArticle*> duo)
		{
			cout << duo.second;
		}
};

class foncteurRabais{
	public:
		foncteurRabais(float rabais):pourcentageRabais_(rabais){};
		void operator()(Client* clientEastwood)
		{
			clientEastwood->diminuerSolde(clientEastwood->getSolde() * (pourcentageRabais_ / 100));
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
		void appliquerRabais(Client client, foncteurRabais fonct);
		void afficher(Client client);
		void afficher(unsigned int idClient);
		void afficherParOrdreAlphabetique()	const;
		void afficherParPrixMoyenDecroissant()	const;

	private:
		map<unsigned int, PanierArticle*> mapClientPanier_;
		typedef map<unsigned int, PanierArticle*>::const_iterator IterateurConst;
};

#endif

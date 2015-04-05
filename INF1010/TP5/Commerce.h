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
		foncteurAffichagePanier(){};
		void operator()(pair<unsigned int, PanierArticle*> duo)
		{
			cout << *duo.second;
		}
};

class foncteurRabais{
	public:
		foncteurRabais(float rabais):pourcentageRabais_(rabais){};
		void operator()(Client &clientEastwood)
		{
			clientEastwood.diminuerSolde(clientEastwood.getSolde() * (pourcentageRabais_ / 100));
		}
	private:
		float pourcentageRabais_;
};

template<typename TypeClef, typename TypeList>
class foncteurPopulerListeParMap{
	public:
	foncteurPopulerListeParMap(list<TypeList>* liste):liste_(liste){};
	void operator()(pair<TypeClef, TypeList> duo)
		{
			liste_ -> push_back(duo.second);
		}
	private:
	list<TypeList>* liste_;
};

class Commerce 
{
	public:
		bool estPresent(Client &client);
		bool ajouterCommande(Client &client, PanierArticle* panier);
		bool ajouterArticle(Client &client, Article* article);
		bool supprimerCommande(Client &client);
		bool supprimerArticleCommande(Client &client, Article* article);
		void appliquerRabais(Client &client, foncteurRabais fonct);
		void afficher(const Client &client);
		void afficher(unsigned int idClient);
		void afficherParOrdreAlphabetique()	const;
		void afficherParPrixMoyenDecroissant()	const;

	private:
		map<unsigned int, PanierArticle*> mapClientPanier_;
		typedef map<unsigned int, PanierArticle*>::const_iterator IterateurConst;
};

#endif

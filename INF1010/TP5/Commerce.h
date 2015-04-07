/********************************************************************
 Fichier: Commerce.h
 Auteur: Gendreau, Vincent, Courbariau
 Date : Lundi 6 avril 2015
 Description: 
	Fichier ent�te du commerce qui se charge d'associer chaque client pr�sent � un panier d'articles.
	Ces associations se retrouvent dans la map mapClientPanier_.
	Commerce peut se voir ajouter et supprimer des commandes ou des articles d'une commande.
********************************************************************/
#ifndef COMMERCE_H
#define COMMERCE_H

#include "Client.h"
#include "Panier.h"
#include "Article.h"
#include "PanierArticle.h"
#include <map>
#include <iostream>


using namespace std;

/*
* Foncteur qui se charge d'afficher un panier
* � partir d'une pair d'unsigned int et un 
* pointeur vers un PanierArticle
*/

class foncteurAffichagePanier{
	public:
		foncteurAffichagePanier(){};
		void operator()(pair<unsigned int, PanierArticle*> duo)
		{
			cout << *duo.second;
		}
};

/*
* Foncteur qui applique un rabais transmis par
* param�tre � un solde d'un client
*/

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

/*
* Foncteur qui se charge de remplir une
* liste � partir d'une map
*/

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

/*
* Contenu de la classe Commerce
*/

class Commerce 
{
	/*
	* M�thodes publiques
	*/
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

	/*
	* Attributs priv�s
	*/
	private:
		map<unsigned int, PanierArticle*> mapClientPanier_;
		typedef map<unsigned int, PanierArticle*>::const_iterator IterateurConst;
};

#endif

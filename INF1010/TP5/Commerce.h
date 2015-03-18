#ifndef COMMERCE_H
#define COMMERCE_H

#include "Client.h"
#include "Panier.h"
#include "Article.h"
#include <map>
#include <iostream>


using namespace std;

class Commerce 
{
	public:
		bool ajouterCommande(Client client, Panier<Article>* panier); // Panier<?Article?> à confirmer!
		bool ajouterArticle(Client client, Article* article);
		void supprimerCommande(Client client);	// Le bon type des fonctions ci-dessous à venir (je les change au fur et a mesure que j'implemente)
		void supprimerArticleCommande(Client client, Panier<Article>* panier);
		void appliquerRabais(Client client, Foncteur* foncteur); //Foncteur pas encore fait On va le mettre comme ca pour pas oublier de le changer
		void payerPanier(Client client, float montantArgent);
		void afficher(Client client)	const; //Affiche panier d'un client
		void afficher(string nomClient)	const; //Affiche le panier d'un client selon son nom
		void afficherParOrdreAlphabetique()	const; //Affiche les panniers selon l'ordre alphabetique des clients. (Classement dans la map par clés)
		void afficherParPrixMoyenDecroissant()	const;

	private:
		map<Client, Panier<Article>*> mapClientPanier_;
		typedef map<Client, Panier<Article>*> ::const_iterator IterateurConst;
};

#endif
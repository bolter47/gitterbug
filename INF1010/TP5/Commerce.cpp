#include "Commerce.h"
#include "Client.h"
#include "Panier.h"
#include "Article.h"
#include <map>
#include <iostream>

using namespace std;

bool Commerce :: ajouterCommande(Client client, Panier<Article>* panier)
{
	map<Client, Panier<Article>*> ::iterator pos = mapClientPanier_.find(client);
	if (pos != mapClientPanier_.end()){
		return false;
	}
	else{
		mapClientPanier_.insert(pair<Client, Panier<Article>*>(pos->first, pos->second));
		return true;
	}
}

bool Commerce::ajouterArticle(Client client, Article* article)
{
	map<Client, Panier<Article>*> ::iterator pos = mapClientPanier_.find(client);
	if (pos != mapClientPanier_.end()){
		return false;
	}
	else{
		mapClientPanier_.operator[]()
	}
}
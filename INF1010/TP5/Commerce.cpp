#include "Commerce.h"

using namespace std;

bool Commerce::estPresent(Client client)
{
	bool estClientPresent = false;
	unsigned int idClient = client.getID();
	map<unsigned int, PanierArticle*> ::iterator pos = mapClientPanier_.find(idClient);
	if (pos != mapClientPanier_.end())
	{
		estClientPresent = true;
	}
	return estClientPresent;
}

bool Commerce::ajouterCommande(Client client, PanierArticle* panier)
{
	bool succes = false;
	if (estPresent(client))
	{
		mapClientPanier_[client.getID()] = panier;
		succes = true;
	}
	return succes;
}

bool Commerce::ajouterArticle(Client client, Article* article)
{
	bool succes = false;
	if (estPresent(client))
	{
		PanierArticle* panier = mapClientPanier_[client.getID()];
		panier->ajouter(article);
		succes = true;
	}
	return succes;
}

bool Commerce::supprimerCommande(Client client)
{
	bool succes = false;
	if (estPresent(client))
	{
		delete mapClientPanier_[client.getID()];
		mapClientPanier_.erase(client.getID());
		succes = true;
	}
	return succes;
}

bool Commerce::supprimerArticleCommande(Client client, Article* article)
{
	bool succes = false;
	if (estPresent(client))
	{
		PanierArticle* panier = mapClientPanier_[client.getID()];
		panier->supprimer(article->getID());
		succes = true;
	}
	return succes;
}

/*foncteurRabais::foncteurRabais(float rabais) : pourcentageRabais_(rabais){
};

void Commerce:: appliquerRabais(Client client, float rabais, foncteurRabais(float rabais))
{
	PanierArticle* panier = mapClientPanier_[client.getID()];
	foncteurRabais(rabais);
}*/

void Commerce::afficher(Client client) 
{
	PanierArticle* panier = mapClientPanier_[client.getID()];
	cout << *panier;
}

void Commerce::afficher(unsigned int idClient)
{
	PanierArticle* panier = mapClientPanier_[idClient];
	cout << *panier;
}

void Commerce::afficherParOrdreAlphabetique() const
{
	for_each(mapClientPanier_.begin, mapClientPanier_.end, foncteurAffichagePanier());
}

void Commerce::afficherParPrixMoyenDecroissant() const
{
	map<unsigned int, PanierArticle*>::iterator pos = mapClientPanier_.begin;
	unsigned int prixMoyen;
	map<unsigned int, PanierArticle*> mapDesPrixMoyensCroissants;

	while (pos != mapClientPanier_.end)
	{
		PanierArticle* panier = pos->second;
		prixMoyen = panier->obtenirMoyenne;
		mapDesPrixMoyensCroissants[prixMoyen] = panier;
		pos++;
	}
	for_each(mapDesPrixMoyensCroissants.end, mapDesPrixMoyensCroissants.begin, foncteurAffichagePanier());
}
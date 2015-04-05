#include "Commerce.h"

using namespace std;

bool Commerce::estPresent(Client &client)
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

bool Commerce::ajouterCommande(Client &client, PanierArticle* panier)
{
	bool succes = false;
	if (!estPresent(client))
	{
		mapClientPanier_[client.getID()] = panier;
		
		succes = true;
	}
	return succes;
}

bool Commerce::ajouterArticle(Client &client, Article* article)
{
	bool succes = false;
	if (estPresent(client))
	{
		mapClientPanier_[client.getID()] -> ajouter(article);
		succes = true;
	}
	return succes;
}

bool Commerce::supprimerCommande(Client &client)
{
	bool succes = false;
	if (estPresent(client))
	{
		mapClientPanier_.erase(client.getID());
		succes = true;
	}
	return succes;
}

bool Commerce::supprimerArticleCommande(Client &client, Article* article)
{
	bool succes = false;
	if (estPresent(client))
	{
		mapClientPanier_[client.getID()] -> supprimer(article->getID());
		succes = true;
	}
	return succes;
}

void Commerce:: appliquerRabais(Client &client, foncteurRabais rabaisseur)
{
	rabaisseur(client);
}

void Commerce::afficher(const Client &client) 
{
	cout << client;
	cout << *mapClientPanier_[client.getID()];
}

void Commerce::afficher(unsigned int idClient)
{
	cout << *mapClientPanier_[idClient];
}

void Commerce::afficherParOrdreAlphabetique() const
{
	for_each(mapClientPanier_.begin(), mapClientPanier_.end(), foncteurAffichagePanier());
}

void Commerce::afficherParPrixMoyenDecroissant() const
{
	// On se créer une liste de pointeurs de paniers servant à trier et afficher les paniers
	list<PanierArticle*> listeParPrixMoyensCroissants;

	// On popule cette liste à l'aide d'un foncteur trouvé dans commerce.h
	for_each(mapClientPanier_.begin(), mapClientPanier_.end(), foncteurPopulerListeParMap<unsigned int, PanierArticle*>(&listeParPrixMoyensCroissants));
	
	// On la trie à l'aide d'un foncteur trouvé dans panier.h
	listeParPrixMoyensCroissants.sort(comparaison<PanierArticle*>());
	
	// On l'affiche à l'aide d'un foncteur trouvé dans panier.h
	for_each(listeParPrixMoyensCroissants.begin(), listeParPrixMoyensCroissants.end(), afficheurContenu<PanierArticle*>(&cout));
}

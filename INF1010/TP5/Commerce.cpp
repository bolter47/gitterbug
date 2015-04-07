#include "Commerce.h"

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * *
* Petite méthode qui vérifie si un client se
* trouve dans la map. (principe DRY)
* Retourne :	vrai si le client est présent
*				dans la map
* * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui ajoute une commande
* c'est-à-dire qui ajoute un client et son
* panier à la map.
* Retourne :	vrai si la commande a été
*				ajouté à la map avec succes
* * * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui ajoute un article
* au panier d'un client.
* Retourne :	vrai si l'article a été
*				ajouté au panier avec succes
* * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui supprime une commande
* c'est-à-dire qui supprime un client et son 
* panier de la map.
* Retourne :	vrai si la commande a été 
*				supprimer de la map.
* * * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui supprime un article
* du panier d'un client
* Retourne :	vrai si l'article a été 
*				supprimer de la map.
* * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui appelle le foncteur
* qui applique le rabais sur le solde d'un
* client.
* * * * * * * * * * * * * * * * * * * * * * * */

void Commerce:: appliquerRabais(Client &client, foncteurRabais rabaisseur)
{
	rabaisseur(client);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui affiche le panier d'un
* client. 
* * * * * * * * * * * * * * * * * * * * * * * * */

void Commerce::afficher(const Client &client) 
{
	cout << client;
	cout << *mapClientPanier_[client.getID()];
}

/* * * * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui affiche le panier d'un
* client à partir de son ID.
* * * * * * * * * * * * * * * * * * * * * * * * */

void Commerce::afficher(unsigned int idClient)
{
	cout << *mapClientPanier_[idClient];
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui affiche tous les paniers
* de la map en ordre alphabétique (en ordre croissant
* de le l'ID des clients de la map.
* * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Commerce::afficherParOrdreAlphabetique() const
{
	for_each(mapClientPanier_.begin(), mapClientPanier_.end(), foncteurAffichagePanier());
}

/* * * * * * * * * * * * * * * * * * * * * * * * * *
* Méthode de Commerce qui affiche tous les paniers
* de la map en ordre décroissant de leur prix
* moyen.
* * * * * * * * * * * * * * * * * * * * * * * * * */

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

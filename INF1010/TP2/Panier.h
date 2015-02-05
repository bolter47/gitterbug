#ifndef PANIER_H
#define PANIER_H

#include <iostream>
#include <vector>
#include "Article.h"

using namespace std;

class Panier
{
public:
	/*
	* Panier() = construction avec valeurs defaut
	* Panier(vector<Article> articles) = liste vectorielle d'articles
	* Panier(const Panier& autrePanier) = constructeur par copie
	* ~Panier() = destructeur
	*/
	Panier();
	Panier(vector<Article> articles);
	Panier(const Panier& autrePanier);
	~Panier();

	/*
	* Panier& operator= (Panier panier) = ecrase le contenu d'un panier
	*/
	Panier& operator= (Panier panier);

	/*
	* Panier operator+ (Article article) = ajoute un article + met a jour le total d'articles
	* Panier operator+ (Panier autrePanier) = fusione deux paniers
	* Panier operator- (Article article) = retire un exemplaire d'un article
	*/
	Panier operator+ (Article article);
	Panier operator+ (Panier autrePanier);
	//Panier operator+ (int entier);
	Panier operator- (const Article& article) const;
	Panier operator- (const Panier& panier) const;
	
	//void operator+ (Panier panier) = addition d'un article à un Panier via son Id
	



	/*
	* void operator+= (Article article) = ajoute un article à une liste
	* void operator+= (Panier autrePanier) = fusionne avec un autre panier
	* void operator-= (Article article) = retire un exemplaire d'un article
	*/
	void operator+= (Article article);
	void operator+= (Panier autrePanier);
	void operator-= (Article article);
	void operator-= (Panier autrePanier);

	/*
	* size_t getTaille() = retourne la taille du vecteur du panier.
	* float getTotal() = retourne le prix total du panier
	*/
	size_t getTaille() const;
	float getTotal() const;
	
	/*
	* void operator<< (Panier panier) = affiche contenu et la somme totale
	*/
	friend ostream& operator<< (ostream& os, const Panier& panier);

	/*
	* liste d'articles
	* total 
	*/
private:
	vector<Article*> listeArticles_;
	float total_;



};
#endif

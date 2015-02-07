/**
* Header pour la classe Panier qui servira à contenir des articles
* \file   Panier.h
* \author Gendreau et Courbariaux
* \date   6 février 2015
*/

#ifndef PANIER_H
#define PANIER_H

#include <iostream>
#include <vector>
#include "Article.h"

using namespace std;

class Panier
{
public:
	/* ***CONSTRUCT DESTRUCT***
	* Panier() 							: construction avec valeurs defaut
	* Panier(vector<Article> articles) 	: liste vectorielle d'articles
	* Panier(const Panier& autrePanier) : constructeur par copie
	* ~Panier() 						: destructeur
	*/
	Panier();
	Panier(vector<Article> articles);
	Panier(const Panier& autrePanier);
	~Panier();

	/* ***ASSIGNATION***
	* Panier& operator= (Panier panier)	: ecrase le contenu d'un panier
	*/
	Panier& operator= (const Panier& panier);

	/* ***OPÉRATEURS ARITHMÉTIQUES***
	* Panier operator+ (Article article) 		: ajoute un article + met a jour le total d'articles
	* Panier operator+ (Panier autrePanier) 	: fusione deux paniers
	* Panier operator+ (Article& article, const Panier autrePanier) : addition d'ordre inversée
	* Panier operator- (Article article) 		: retire un exemplaire d'un article
	* Panier operator- (const Panier& panier) 	: retire les articles communs aux deux paniers
	*/
	Panier operator+ (Article& article) const;
	Panier operator+ (const Panier& autrePanier) const;
	friend Panier operator+ (Article& article, const Panier autrePanier);
	Panier operator- (const Article& article) const;
	Panier operator- (const Panier& panier) const;

	/* ***ARITHMÉTIQUES/ASSIGNATION***
	* void operator+= (Article article) 			: ajoute un article à une liste
	* void operator+= (Panier autrePanier) 			: fusionne avec un autre panier
	* void operator-= (Article article) 			: retire un exemplaire d'un article
	* void operator-= (const Panier& autrePanier) 	: retire les articles communs aux deux paniers
	*/
	void operator+= (Article article);
	void operator+= (const Panier& autrePanier);
	void operator-= (Article article);
	void operator-= (const Panier& autrePanier);

	/* ***GETTERS***
	* size_t getTaille()	: retourne la taille du vecteur du panier.
	* float getTotal() 		: retourne le prix total du panier
	*/
	size_t getTaille() const;
	float getTotal() const;
	
	/* ***OPÉRATEURS STREAM***
	* void operator<< (Panier panier) : affiche contenu et la somme totale
	*/
	friend ostream& operator<< (ostream& os, const Panier& panier);

	/* ***VARIABLES***
	* liste d'articles
	* total 
	*/
private:
	vector<Article*> listeArticles_;
	float total_;
};
#endif

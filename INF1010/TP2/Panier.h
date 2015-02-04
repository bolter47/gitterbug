#ifndef PANIER_H
#define PANIER_H

#include <iostream>
#include <vector>
#include "Article.h"
using namespace std;
class Panier
{
public:
	Panier();
	Panier(vector<Article> articles);
	Panier(const Panier& autrePanier);
	~Panier();

	Panier& operator= (Panier panier);

	Panier operator+ (Article article);
	Panier operator+ (Panier autrePanier);
	Panier operator- (Article article);

	void operator+= (Article article);
	void operator+= (Panier autrePanier);
	void operator-= (Article article);

	size_t getTaille();
	float getTotal();

private:
	vector<Article*> listeArticles_;
	float total_;
};
#endif
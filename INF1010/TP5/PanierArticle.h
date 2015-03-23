#ifndef PANIER_ARTICLE_H
#define PANIER_ARTICLE_H

#include "Article.h"
#include "Panier.h"

using namespace std;

/*********************************************
 * DEFINITION DU FONCTEUR D'ADDITION
 * ******************************************/
 class AdditionElement{
	 public:
	 AdditionElement(float* total): total_(total){};
	 
	 void operator()(Article* article){
		 *total_ += article->getPrix();
	 }
	 
	 private:
	 float* total_;
 };

/*********************************************
 * DEFINITION DE LA CLASSE PANIERARTICLE
 * ******************************************/
class PanierArticle:Panier<Article> {
	public:
	
	// Méthodes calcul de valeur
	float sommeArticles() const;
	float obtenirMoyenne() const;
	
	// Méthodes de triage
	list<Article> trier() const;
	
	// Méthodes d'afficheage
	friend ostream& operator<<(ostream& out, const PanierArticle& in);
};

#endif

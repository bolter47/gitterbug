#ifndef PANIER_ARTICLE_H
#define PANIER_ARTICLE_H

#include "Article.h"
#include "Panier.h"

using namespace std;

/*********************************************
 * DEFINITION DES FONCTEURS
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
 
 class compPrix{
	 public:
	 compPrix(){};
	 
	 bool operator()(Article* art1, Article* art2){
		 return art1 -> getPrix() >= art2 -> getPrix();
	 }
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
	list<Article*> trier() const;
	
	// Méthodes d'afficheage
	friend ostream& operator<<(ostream& out, const PanierArticle& in);
};

#endif

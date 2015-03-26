#ifndef PANIER_ARTICLE_H
#define PANIER_ARTICLE_H

#include "Article.h"
#include "Panier.h"

using namespace std;

/*********************************************
 * DEFINITION DES FONCTEURS
 * ******************************************/
 
 /*****************************************
  * Foncteur: additionElement
  * Ajoute le prix d'un article passé par l'opérateur()
  * à un float pointé par paramètre lors de la construction.
  * **************************************/
 class AdditionElement{
	 public:
	 
	 // Constructeur qui prend un pointeur vers un float
	 AdditionElement(float* total): total_(total){};
	 
	 
	 void operator()(Article* article){
		 *total_ += article -> getPrix();
	 }
	 
	 private:
	 // Pointeur vers le float qui se fait incrémenté
	 float* total_;
 };

/*********************************************
 * DEFINITION DE LA CLASSE PANIERARTICLE
 * ******************************************/
class PanierArticle:public Panier<Article> {
	public:
	
	// Méthodes calcul de valeur
	float sommeArticles() const;
	float obtenirMoyenne() const;
	
	// Méthodes de triage
	list<Article*> trier() const;
	
	// Méthodes d'afficheage
	friend ostream& operator<<(ostream& out, const PanierArticle& in);
	
	// Méthodes pour comparer paniers
	bool operator<(const PanierArticle& panier) const;
};

#endif

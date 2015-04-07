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
	/* * * * * * * * *
	* Constructeur
	* * * * * * * * */
	PanierArticle(unsigned int id);
	
	/* * * * * * * * * * * * * * * * * * * * *
	* Méthode qui calcule la somme des prix
	* des articles d'un PanierArticle
	* Retourne :	le montant total du
	*				PanierArticle
	* * * * * * * * * * * * * * * * * * * * */
	float sommeArticles() const;

	/* * * * * * * * * * * * * * * * * * * * * * * *
	* Méthode qui calcule la moyenne des prix
	* des articles contenus dans un PanierArticle
	* Retourne :	le prix moyen d'un 
	*				PanierArticle
	* * * * * * * * * * * * * * * * * * * * * * * */
	float obtenirMoyenne() const;
	
	/* * * * * * * * * *
	* Méthode de trie
	* * * * * * * * * */
	list<Article*> trier() const;
	
	/* * * * * * * * * * * * * * * * * * * * * * * *
	* Méthode d'affichage des articles contenus
	* dans un Panier
	* * * * * * * * * * * * * * * * * * * * * * * */
	friend ostream& operator<<(ostream& out, const PanierArticle& in);
	
	/* * * * * * * * * * * * * * * * * * * * * *
	* Méthode de comparaison de PanierArticle
	* qui compare les paniers selon leur prix
	* moyens
	* * * * * * * * * * * * * * * * * * * * * */
	bool operator<(const PanierArticle& panier) const;
};

#endif

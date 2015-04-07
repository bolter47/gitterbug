/********************************************************************
 Fichier: PanierArticle.cpp
 Auteur: Gendreau, Vincent, Courbariau
 Date : Lundi 6 avril 2015
 Description: 
	Implémentation de la classe PanierArticle.
	Pour l'implémentation des foncteurs, voir Panier.h ou PanierArticle.h
********************************************************************/

#include "PanierArticle.h"

/* * * * * * * * *
* Constructeur
* * * * * * * * */
	PanierArticle::PanierArticle(unsigned int id):Panier<Article>(id){
	}
	
	/* * * * * * * * * * * * * * * * * * * * *
	* Méthode qui calcule la somme des prix
	* des articles d'un PanierArticle
	* Retourne :	le montant total du
	*				PanierArticle
	* * * * * * * * * * * * * * * * * * * * */
	float PanierArticle::sommeArticles() const{
		float* n = new float(0.f);
		for_each(liste_.begin(), liste_.end(), AdditionElement(n));
		return *n;
	}

	/* * * * * * * * * * * * * * * * * * * * * * * *
	* Méthode qui calcule la moyenne des prix
	* des articles contenus dans un PanierArticle
	* Retourne :	le prix moyen d'un
	*				PanierArticle
	* * * * * * * * * * * * * * * * * * * * * * * */
	float PanierArticle::obtenirMoyenne() const{
		return sommeArticles()/liste_.size();
	}
	
	/* * * * * * * * * *
	* Méthode de trie
	* * * * * * * * * */
	list<Article*> PanierArticle::trier() const{
		// On se créer une copie de la liste
		list<Article*> listeRetour;
		listeRetour = liste_;
		listeRetour.sort(comparaison<Article*>());
		return listeRetour;
	}
	
	/* * * * * * * * * * * * * * * * * * * * * * * *
	* Méthode d'affichage des articles contenus
	* dans un Panier
	* * * * * * * * * * * * * * * * * * * * * * * */
	bool PanierArticle::operator<(const PanierArticle& panier) const{
		return obtenirMoyenne() < panier.obtenirMoyenne();
	}
	
	/* * * * * * * * * * * * * * * * * * * * * *
	* Méthode de comparaison de PanierArticle
	* qui compare les paniers selon leur prix
	* moyens
	* * * * * * * * * * * * * * * * * * * * * */
	ostream& operator<<(ostream& out, const PanierArticle& in){
		Panier<Article> baseIn = static_cast< Panier<Article> >(in);
		out << baseIn << "PRIX MOYEN : " << in.obtenirMoyenne() << endl
		<< "PRIX TOTAL : " << in.sommeArticles() << endl
		<< "==============================================" << endl;
		return out;
	}

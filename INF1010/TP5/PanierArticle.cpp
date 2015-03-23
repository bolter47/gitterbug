#include "PanierArticle.h"
	
	// Méthodes calcul de valeur
	float PanierArticle::sommeArticles() const{
		float* n;
		for_each(liste_.begin(), liste_.end(), AdditionElement(n));
		return *n;
	}
	
	float PanierArticle::obtenirMoyenne() const{
		return sommeArticles()/liste_.size();
	}
	
	// Méthodes de triage
	list<Article> PanierArticle::trier() const{
	}
	
	// Méthodes d'afficheage
	ostream& operator<<(ostream& out, const PanierArticle& in){
		// TODO : FIX THIS SHIT
		return out << static_cast<Panier<Article>>(in);
	}

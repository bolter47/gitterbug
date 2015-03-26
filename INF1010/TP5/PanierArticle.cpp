#include "PanierArticle.h"
	
	// Méthodes calcul de valeur
	float PanierArticle::sommeArticles() const{
		float* n;
		*n = 0;
		for_each(liste_.begin(), liste_.end(), AdditionElement(n));
		return *n;
	}
	
	float PanierArticle::obtenirMoyenne() const{
		return sommeArticles()/liste_.size();
	}
	
	// Méthodes de triage
	list<Article*> PanierArticle::trier() const{
		// On se créer une copie de la liste
		list<Article*> listeRetour;
		copy(liste_.begin(), liste_.end(), listeRetour.begin());
		// boucle qui trie tans et aussi longtemps qu'un déplacement à eut lieu
		listeRetour.sort(comparaison<Article*>());
		return listeRetour;
	}
	
	bool PanierArticle::operator<(const PanierArticle& panier) const{
		return obtenirMoyenne() < panier.obtenirMoyenne();
	}
	
	// Méthodes d'afficheage
	ostream& operator<<(ostream& out, const PanierArticle& in){
		// TODO : FIX THIS SHIT
		const Panier<Article> base(in);
		
		return out << base;
	}

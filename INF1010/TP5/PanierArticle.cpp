#include "PanierArticle.h"

	// Constructeur
	PanierArticle::PanierArticle(unsigned int id):Panier<Article>(id){
	}
	
	// Méthodes calcul de valeur
	float PanierArticle::sommeArticles() const{
		float* n = new float(0.f);
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
		Panier<Article> baseIn = static_cast< Panier<Article> >(in);
		out << baseIn;
		return out;
	}

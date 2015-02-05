#include "Panier.h"

	/*
	* Panier() = construction avec valeurs defaut
	* Panier(vector<Article> articles) = liste vectorielle de pointeurs d'articles
	* Panier(const Panier& autrePanier) = constructeur par copie
	* ~Panier() = destructeur
	*/
Panier::Panier(){
	Panier panier;
	panier.total_ = 0;
}
Panier::Panier(vector<Article> articles){
	total_ = 0;
	//donne la bonne taille au panier
	listeArticles_.resize(articles.size());
	//ajoute chaque article
	for (unsigned i = 0; i < articles.size(); i++){
		//deep copy
		listeArticles_[i] = new Article;
		*listeArticles_[i] = articles[i];
		//met a jour le prix total
		total_ += articles[i].getPrix();
	}
}
Panier::Panier(const Panier& autrePanier){
	//asigne la "valeur" autrePanier a panier
	*this = autrePanier;
}
Panier::~Panier(){
	////////////////////////////////	delete() 
}

	/*
	* Panier& operator= (Panier panier) = ecrase le contenu d'un panier
	*/
Panier& Panier::operator= (Panier panier){
	//similairement au constructeur par passage de
	total_ = panier.total_;
	listeArticles_.resize(panier.listeArticles_.size());
	for (unsigned i = 0; i < panier.listeArticles_.size(); i++){
		listeArticles_[i] = panier.listeArticles_[i];
	}
	return *this;
}

	/*
	* Panier operator+ (Article article) = ajoute un article + met a jour le total d'articles
	* Panier operator+ (Panier autrePanier) = fusione deux paniers
	* Panier operator- (Article article) = retire un exemplaire d'un article
	*/
Panier Panier::operator+ (Article article){
	listeArticles_.push_back(&article);
	return *this;
}
Panier Panier::operator+ (Panier autrePanier){
	total_ += autrePanier.getTotal();
	listeArticles_.resize(listeArticles_.size() + autrePanier.listeArticles_.size());
	for (unsigned i = 0; i < autrePanier.listeArticles_.size(); i++){
		listeArticles_.push_back(autrePanier.listeArticles_[i]);
	}
	return *this;
}

Panier Panier::operator- (Article article){
	
}


	/*
	* void operator+= (Article article) = ajoute un article à une liste
	* void operator+= (Panier autrePanier) = fusionne avec un autre panier
	* void operator-= (Article article) = retire un exemplaire d'un article
	*/
void Panier::operator+= (Article article){
}
void Panier::operator+= (Panier autrePanier){
}
void Panier::operator-= (Article article){
}

/*
* void operator<< (Panier panier) = affiche contenu et la somme totale
*/
ostream& operator << (ostream& os, const Panier& panier){
	for(unsigned i = 0; i < panier.listeArticles_.size(); i++)
		os << panier.listeArticles_.at(i);
	os << panier.getTotal();
	return os;
}

	/*
	* size_t getTaille() = retourne la taille du vecteur du panier.
	* float getTotal() = retourne le prix total du panier
	*/
//size_t Panier::getTaille(){
//}
float Panier::getTotal() const{
	return total_;
}

#include "Panier.h"

	/*
	* Panier() = construction avec valeurs defaut
	* Panier(vector<Article> articles) = liste vectorielle de pointeurs d'articles
	* Panier(const Panier& autrePanier) = constructeur par copie
	* ~Panier() = destructeur
	*/
Panier::Panier(){
	total_ = 0;
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
	////////////////////////////////	delete() - ne peut pas delete car les Articles* appartiennent au main
	//for (unsigned i = 0; i < this -> getTaille(); i++){
	//	delete (this -> listeArticles_[i]);
	//}
}

	/*
	* Panier operator= (Panier panier) = ecrase le contenu d'un panier
	*/
Panier& Panier::operator= (const Panier& panier){
	//similairement au constructeur par passage de
	this -> total_ = panier.total_;
	this -> listeArticles_.resize(panier.getTaille());
	for (unsigned i = 0; i < panier.listeArticles_.size(); i++)
		this -> listeArticles_[i]= panier.listeArticles_[i];
		
	return *this;
}

	/*
	* Panier operator+ (Article article) : ajoute un article + met a jour le total d'articles
	* Panier operator+ (Panier autrePanier) : fusione deux paniers
	* Panier operator+ (Article& article, const Panier& autrePanier) const : fonctionne comme operator+(article)
	* Panier operator- (Article article) : retire un exemplaire d'un article
	*/
Panier Panier::operator+ (Article& article) const{;
	Panier outPanier;
	outPanier = *this;
	outPanier.total_ += article.getPrix();
	outPanier.listeArticles_.push_back(&article);
	
	return outPanier;
}

Panier Panier::operator+ (const Panier& autrePanier) const{
	Panier outPanier(*this);
	outPanier.total_ += autrePanier.getTotal();
	for (unsigned i = 0; i < autrePanier.listeArticles_.size(); i++){
		outPanier.listeArticles_.push_back(autrePanier.listeArticles_[i]);
	}
	return outPanier;
}

Panier operator+ (Article& article, const Panier autrePanier){
	Panier outPanier = autrePanier + article;
	return autrePanier;
}

Panier Panier::operator-(const Article& article)const{
	Panier panier = *this;
	vector<Article*>::iterator it = panier.listeArticles_.begin();
	for (unsigned i = 0; i < listeArticles_.size(); i++){
		if (*listeArticles_[i] == article){
			panier.total_ -= article.getPrix();
			panier.listeArticles_.erase(it);
		}
		it++;
	}
	return panier;
}

Panier Panier::operator- (const Panier& panier) const{
	Panier outPanier(*this);
	for (unsigned i=0; i < panier.listeArticles_.size(); i++){
		outPanier = outPanier - *panier.listeArticles_[i];
	}
	return outPanier;
}


	/*
	* void operator+= (Article article) = ajoute un article à une liste
	* void operator+= (Panier autrePanier) = fusionne avec un autre panier
	* void operator-= (Article article) = retire un exemplaire d'un article
	*/
void Panier::operator+= (Article article){
	*this = *this + article;
}
void Panier::operator+= (const Panier& autrePanier){
	*this = *this + autrePanier;
}
void Panier::operator-= (Article article){
	*this = *this - article;
}
void Panier::operator-= (const Panier& autrePanier){
	*this = *this - autrePanier;
}

/*
* void operator<< (Panier panier) = affiche contenu et la somme totale
*/
ostream& operator << (ostream& os, const Panier& panier){
	for(unsigned i = 0; i < panier.listeArticles_.size(); i++){
		os << *panier.listeArticles_.at(i);
	}
	os << "TOTAL : " << panier.getTotal() << endl
	<< "======================================================" << endl;
	return os;
}

	/*
	* size_t getTaille() = retourne la taille du vecteur du panier.
	* float getTotal() = retourne le prix total du panier
	*/
size_t Panier::getTaille() const{
	return listeArticles_.size();
}
float Panier::getTotal() const{
	return total_;
}

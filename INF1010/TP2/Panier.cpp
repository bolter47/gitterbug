/**
* Fichier .cpp qui implémente les fonctionnalités de la classe panier
* Le Panier possède un vecteur de pointeurs d'articles ainsi qu'un coût
* \file   Panier.cpp
* \author Gendreau et Courbariaux
* \date   6 février 2015
* Créé le 4 février 2015
*/

#include "Panier.h"

	/* ***CONSTRUCT DESTRUCT*** */
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


	/* ***ASSIGNATON*** */

Panier& Panier::operator= (const Panier& panier){
	// Assignation du nouveau total
	this -> total_ = panier.total_;
	// Ajustement de la taille du panier
	this -> listeArticles_.resize(panier.getTaille());
	// Boucle de deep copy
	for (unsigned i = 0; i < panier.listeArticles_.size(); i++)
		this -> listeArticles_[i]= panier.listeArticles_[i];
		
	return *this;
}

	/* ***OPERATEURS ARITHMÉTIQUES*** */
	
Panier Panier::operator+ (Article& article) const{
	// Création et assignation du panier de sortie
	Panier outPanier;
	outPanier = *this;
	// Ajoute l'article et son prix au panier et son total
	outPanier.total_ += article.getPrix();
	outPanier.listeArticles_.push_back(&article);
	
	return outPanier;
}

Panier Panier::operator+ (const Panier& autrePanier) const{
	// Création du panier de sortie et assignation du total
	Panier outPanier(*this);
	outPanier.total_ += autrePanier.getTotal();
	// Boucle qui rajoute les articles d'un panier à l'autre
	for (unsigned i = 0; i < autrePanier.listeArticles_.size(); i++){
		outPanier.listeArticles_.push_back(autrePanier.listeArticles_[i]);
	}
	
	return outPanier;
}

Panier operator+ (Article& article, const Panier autrePanier){
	// Opération d'addition, catch de l'inverse
	Panier outPanier = autrePanier + article;
	
	return autrePanier;
}

Panier Panier::operator-(const Article& article)const{
	// Création et assignation du panier de sortie
	Panier outPanier = *this;
	// Iterateur de vecteur pour une fonction de Vecteur
	vector<Article*>::iterator it = outPanier.listeArticles_.begin();
	// Boucle qui cherche les articles similaires et les supprime
	for (unsigned i = 0; i < listeArticles_.size(); i++){
		if (*listeArticles_[i] == article){
			outPanier.listeArticles_.erase(it);
			// Mise à jour du total
			outPanier.total_ -= article.getPrix();
		}
		// update de l'iterator
		it++;
	}
	
	return outPanier;
}

Panier Panier::operator- (const Panier& panier) const{
	// Création du panier de sortie
	Panier outPanier(*this);
	// Boucle qui soustrait chaque article d'un panier de l'autre
	for (unsigned i=0; i < panier.listeArticles_.size(); i++){
		outPanier = outPanier - *panier.listeArticles_[i];
	}
	
	return outPanier;
}


	/* ***ARITHMÉTQUES / ASSIGNATION*** */
	
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

/* ***OPÉRATEURS OSTREAM*** */

ostream& operator << (ostream& os, const Panier& panier){
	// boucle qui rajoute chaque article du panier au ostream
	for(unsigned i = 0; i < panier.listeArticles_.size(); i++){
		os << *panier.listeArticles_.at(i);
	}
	// Sortie du total et fin
	os << "TOTAL : " << panier.getTotal() << endl
	<< "======================================================" << endl;
	
	return os;
}

	/* ***GETTERS*** */
	
size_t Panier::getTaille() const{
	return listeArticles_.size();
}

float Panier::getTotal() const{
	return total_;
}

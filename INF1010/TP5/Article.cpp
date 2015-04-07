#include "Article.h"

/* * * * * * * * *
* Constructeur
* * * * * * * * */
Article::Article(unsigned int id, string nom, float prix): id_(id), nom_(nom), prix_(prix){
	}

/* * * * * * * * *
* Destructeur
* * * * * * * * */
Article::~Article(){
	}

/* * * * * * * * *
* Accesseurs
* * * * * * * * */
unsigned int Article::getID() const {
	return id_; 
}
string Article::getNom() const { 
	return nom_; 
}
float Article::getPrix()const { 
	return prix_; 
}

/* * * * * * * * * * * * * * *
* Redefinition d'opétateurs
* * * * * * * * * * * * * * */
bool Article::operator<(const Article& item) const{
	return (prix_ < item.getPrix());
}

ostream& operator<<(ostream& out, const Article&  article) {
	out << "Article #" << article.id_ << " : " << article.nom_ << ", " << article.prix_ << "$" << endl;
	// Pas besoin de endl, le ostream_iterator s'en charge
	return out;
}

/* * * * * * * *
* Modificateurs
* * * * * * * */
Article& Article::operator=(const Article& article){
	id_ = article.getID();
	nom_ = article.getNom();
	prix_ = article.getPrix();
	return *this;
}

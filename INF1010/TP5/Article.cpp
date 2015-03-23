#include "article.h"


bool Article:: operator<(const float prix) const{
	return (prix_ < prix);
};

ostream& operator<<(ostream& out, const Article&  article) {
	out << article.id_ << ' ' << article.nom_ << ' ' << article.prix_ << endl;
};

void Article::operator=(const Article article){
	id_ = article.getID();
	nom_ = article.getNom();
	prix_ = article.getPrix();

}
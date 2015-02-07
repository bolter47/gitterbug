/**
* Le .cpp qui implémente les fonctionnalités de la classe Article
* \file   Article.cpp
* \author Gendreau et Courbariaux
* \date   6 février 2015
*/

#include "Article.h"

using namespace std;


/* ***CONSTRUCT DESTRUCT*** */

Article::Article()
	: id_(0), nom_(""), prix_(0)
{
}

Article::Article(int id, const string& nom, float prix)
	: id_(id), nom_(nom), prix_(prix)
{
}

Article::Article(int id)
	: id_(id), nom_("Divers"), prix_(1)
{
}

Article::~Article() {}

/* ***GETTERS*** */

unsigned int Article::getId() const
{
	return id_;
}

string Article::getNom() const
{
	return nom_;
}

float Article::getPrix() const
{
	return prix_;
}

/* ***SETTERS*** */
void Article::setId(unsigned int id)
{
	id_ = id;
}

void Article::setNom(const string& nom)
{
	nom_ = nom;
}

void Article::setPrix(float prix)
{
	prix_ = prix;
}

/* ***COMPARAISONS*** */

bool Article::operator==(const Article& article) const
{
	if (id_ == article.getId())
		return true;
	else
		return false;
}

bool Article::operator!=(const Article& article) const
{
	if (id_ != article.getId())
		return true;
	else
		return false;
}

/* ***OPÉRATEURS STREAM*** */

ostream& operator<< (ostream& os, const Article& article)
{
	os << "Article #" << article.id_ << ": "<< article.nom_ << ". Prix: " << article.prix_ << "$" << endl;
	return os;
}

 istream& operator >> (istream& os, Article& article)
 { 
	 cout << "DEFINITION DE L'ARTICLE:" << endl
	 << "Entrez le no d'identification : ";
	 os >> article.id_;
	 cout << "Entrez le nom de l'article : ";
	 os >> article.nom_;
	 cout << "Entrez le prix de l'article : ";
	 os >> article.prix_;
	 return os;
 }

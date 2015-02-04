#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include <string>
using namespace std;
class Article
{
public:

	/* ***CONSTRUCT DESTRUCT***
	*Article() 		: Constr par defaut
	*Article(id, nom, prix) : Constr a 3 params
	*Article(id) 		: Constr article avec id seulement
	*~Article() 		: Destructeur
	*/
	Article();

	Article(int id, const string& nom, float prix);

	Article(int id);

	~Article();

	/* ***GETTERS***
	*getId() 	: récupère le numéro d'indentification de l'article.
	*getNom() 	: récupère le nom de l'article.
	*getPrix() 	: récupère le prix de l'article.
	*/
	unsigned int getId() const;

	string getNom() const;

	float getPrix() const;

	/* ***SETTERS***
	*setId() 	: Corrige le no d'identification
	*setNom()	: Corrige le nom de l'article
	*setPrix	: Corrige le prix de l'article
	*/
	void setId(unsigned int id);

	void setNom(const string& nom);

	void setPrix(float prix);

	/* ***OPERATORS***
	*operator==	: Vérifie s'il y a id match
	*operator!=	: Vérifie si les id sont différents
	*operator<<	: Passe en stream les informations de l'article
	*operator>>	: Prend de l'usager les infos en stream
	*/
	bool operator==(const Article& article) const;
	bool operator!=(const Article& article) const;

	friend ostream& operator<< (ostream& os, const Article& article);
	friend istream& operator >> (istream& os, Article& article);


private:
	unsigned int id_;
	string nom_;
	float prix_;
};
#endif

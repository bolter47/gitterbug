#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <iostream>
using namespace std;

class Article{
public:
	//constructeur
	Article(unsigned int id, string nom, float prix);
	//destructeur
	~Article();
	//accesseurs
	unsigned int getID() const;
	string getNom() const;
	float getPrix()const;
	bool operator<(const Article& item) const;
	friend ostream& operator<<(ostream& out, const Article& article);
	friend ostream& operator<<(ostream& out, const Article* articlePointeur);
	//modifieurs
	Article& operator=(const Article& article);
private:
	unsigned int id_;
	string nom_;
	float prix_;
};
#endif

#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
using namespace std;

class Article{
public:
	//constructeur
	Article(unsigned int id, string nom, float prix) :id_(id), nom_(nom), prix_(prix){};
	//destructeur
	~Article();
	//accesseurs
	unsigned int getID() const { return id_; };
	string getNom() const { return nom_; };
	float getPrix()const { return prix_; };
	bool operator<(float Prix) const;
	friend ostream& operator<<(ostream& out, const Article& article);
	//modifieurs
	void operator=(const Article article);
private:
	unsigned int id_;
	string nom_;
	float prix_;
};
#endif
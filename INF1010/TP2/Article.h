#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include <string>
using namespace std;
class Article
{
public:
	Article();
	Article(int id, const string& nom, float prix);
	Article(int id);
	~Article();

	unsigned int getId() const;
	string getNom() const;
	float getPrix() const;

	void setId(unsigned int id);
	void setNom(const string& nom);
	void setPrix(float prix);

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
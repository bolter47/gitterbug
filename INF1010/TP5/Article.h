#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <iostream>
using namespace std;

/* * * * * * * * * *
* Classe Article
* * * * * * * * * */

class Article{
public:

	/* * * * * * * * *
	* Constructeur
	* * * * * * * * */
	Article(unsigned int id, string nom, float prix);

	/* * * * * * * * *
	* Destructeur
	* * * * * * * * */
	~Article();

	/* * * * * * * * *
	* Accesseurs
	* * * * * * * * */
	unsigned int getID() const;
	string getNom() const;
	float getPrix()const;

	/* * * * * * * * * * * * * * *
	* Redefinition d'opétateurs
	* * * * * * * * * * * * * * */
	bool operator<(const Article& item) const;
	friend ostream& operator<<(ostream& out, const Article& article);

	/* * * * * * * *
	* Modificateurs
	* * * * * * * */
	Article& operator=(const Article& article);

	/* * * * * * * * * * *
	* Attributs privés
	* * * * * * * * * * */
private:
	unsigned int id_;
	string nom_;
	float prix_;
};
#endif

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
using namespace std;

/* * * * * * * * * *
* Classe Client
* * * * * * * * * */

class Client{
public:

	/* * * * * * * * *
	* Constructeur
	* * * * * * * * */
	Client(unsigned int id, string nom, string prenom, float solde);

	/* * * * * * * *
	* Destructeur
	* * * * * * * */
	~Client();

	/* * * * * * *
	* Accesseurs
	* * * * * * */
	unsigned int getID() const;
	string getNom() const;
	string getPrenom() const;
	float getSolde() const;

	/* * * * * * * * * * * * * * * * *
	* Redefinition d'opérateurs
	* * * * * * * * * * * * * * * * */
	bool operator <( const Client& dude ) const;
	friend ostream& operator<<(ostream& out, const Client& client);
	Client& operator=(const Client& client);

	/* * * * * * *
	* Modifieurs
	* * * * * * */
	void diminuerSolde(float somme);

	/* * * * * * * * * *
	* Attributs privés
	* * * * * * * * * */
private:
	unsigned int id_;
	string nom_;
	string prenom_;
	float solde_;
};
#endif

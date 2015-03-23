#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
using namespace std;

class Client{
public:
	//constructeur
	Client(unsigned int id, string nom, string prenom, float solde);
	//destructeur
	~Client();
	//accesseurs
	unsigned int getID() const;
	string getNom() const;
	string getPrenom() const;
	float getSolde() const;
	//Redefs d'operateurs
	bool operator <( string nom ) const;
	friend ostream& operator<<(ostream& out, const Client& client);
	Client& operator=(const Client& client);
	//modifieurs
	void diminuerSolde(float somme);
private:
	unsigned int id_;
	string nom_;
	string prenom_;
	float solde_;
};
#endif

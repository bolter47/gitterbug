#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class Client{
public:
	//constructeur
	Client(unsigned int id, string nom, string prenom, float solde) : id_(id), nom_(nom), prenom_(prenom), solde_(solde){};
	//destructeur
	~Client();
	//accesseurs
	unsigned int getID() const { return id_; };
	string getNom() const { return nom_; };
	string getPrenom() const { return prenom_; };
	float getSolde() const { return solde_; };
	bool operator <( string nom ) const;
	friend ostream& operator<<(ostream& out, const Client& client);
	//modifieurs
	void operator=(const Client client);
	float diminuerSolde(float somme);
private:
	unsigned int id_;
	string nom_;
	string prenom_;
	float solde_;
};
#endif

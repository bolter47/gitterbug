#include "Client.h"

bool Client:: operator<(const string nom) const{
	//TODO: faire la comparaison
	nom_ < nom;
};

ostream& operator<<(ostream& out, const Client& client) {
	out << client.id_ << ' ' << client.nom_ << ' ' << client.prenom_ << ' ' << client.solde_ << endl;
};

void Client::operator=(Client client){
	id_ = client.getID();
	nom_ = client.getNom();
	prenom_ = client.getPrenom();
	solde_ = client.getSolde();
};
float Client::diminuerSolde(float somme){
	solde_ -= somme;
};
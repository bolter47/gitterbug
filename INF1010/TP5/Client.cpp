#include "Client.h"

//constructeur et destructeur
	Client::Client(unsigned int id, string nom, string prenom, float solde):id_(id), nom_(nom), prenom_(prenom), solde_(solde){
	};
		
	Client::~Client(){
	};
		
	/****************************
	 *  Accesseurs pour chq attribut
	 * *************************/
	 
	unsigned int Client::getID() const {
		return id_; 
	};
	
	string Client::getNom() const { 
		return nom_; 
	};
	
	string Client::getPrenom() const { 
		return prenom_;
	};
	
	float Client::getSolde() const {
		return solde_;
	};
	
	/****************************
	 *  Redefs d'operateurs
	 * operator< : vérifie la première lettre du nom de chq client
	 * operator<<: sort tous les infos d'un client sur une ligne
	 * operator= : retourne un client avec les mêmes attributs que celui à droite de l'operande
	 * *************************/
	 
	bool Client::operator<(const Client& dude) const{	
		return(id_ < dude.getID());
	};
	
	ostream& operator<<(ostream& out, const Client& client) {
		out << client.id_ << ' ' << client.nom_ << ' ' << client.prenom_ << ' ' << client.solde_ << endl;
		return out;
	};

	Client& Client::operator=(const Client& client){
		id_ = client.getID();
		nom_ = client.getNom();
		prenom_ = client.getPrenom();
		solde_ = client.getSolde();
		return *this;
	};
	
	/****************************
	 *  Modif de valeurs
	 * diminuerSolde: réduit le solde du client d'une valeur quelconque
	 * *************************/
	 
	void Client::diminuerSolde(float somme){
		solde_ -= somme;
	};

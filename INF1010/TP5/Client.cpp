#include "Client.h"

//constructeur et destructeur
	Client::Client(unsigned int id, string nom, string prenom, float solde):id_(id), nom_(nom), prenom_(prenom), solde_(solde){
	};
		
	Client::~Client(){
	};
		
	// Accesseurs
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
	
	// Redefs d'operateurs
	bool Client::operator<(const string nom) const{
		//TODO: faire la comparaison
		return(nom_ < nom);
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
	
	// Modification de valeurs
	void Client::diminuerSolde(float somme){
		solde_ -= somme;
	};

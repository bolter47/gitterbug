#include "Etudiant.h"
	
	// Constructeur par défaut
	Etudiant::Etudiant():matricule_(), prenom_(), nom_(){
	}
	// Constructeur par params
	Etudiant::Etudiant(const string& matricule, const string& prenom, const string& nom):
	matricule_(matricule), prenom_(prenom), nom_(nom){
	}
	//destructeur
	Etudiant::~Etudiant(){};

	//getters
	string Etudiant::getMatricule() const{
		return matricule_;
	}
	string Etudiant::getPrenom() const{
		return prenom_;
	}
	string Etudiant::getNom() const{
		return nom_;
	}
	
	//setters
	void Etudiant::setMatricule(const string& matricule){
		matricule_ = matricule;
	}
	void Etudiant::setPrenom(const string& prenom){
		prenom_ = prenom;
	}
	void Etudiant::setNom(const string& nom){
		nom_ = nom;
	}
	
	// Affichage
	void Etudiant::afficher(){
		cout << nom_ << ", " << prenom_ << " : " << matricule_ << endl;
	}

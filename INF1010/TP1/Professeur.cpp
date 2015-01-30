#ifndef PROFESSEUR_H
#include "Professeur.h"
#endif

//constructeurs
Professeur::Professeur() : nEmploye_(""), nom_(""), prenom_(""), departement_(""){}
Professeur::Professeur(string nEmploye, string nom, string prenom, string departement):
	nEmploye_(nEmploye), nom_(nom), prenom_(prenom), departement_(departement){}

//destructeur
Professeur::~Professeur(){};

//accesseurs
string Professeur::getnEmploye() const{ return nEmploye_; };
string Professeur::getNom() const{ return nom_; };
string Professeur::getPrenom() const{ return prenom_; };
string Professeur::getdepartement_() const{ return departement_; };

//modificateurs
void Professeur::setnEmploye(const string& nEmploye){ nEmploye_ = nEmploye; };
void Professeur::setPrenom(const string& prenom){ prenom_ = prenom; };
void Professeur::setNom(const string& nom){ nom_ = nom; };
void Professeur::setDepartement(const string& departement){ departement_ = departement; };

//affichage
void Professeur::afficher() const{
	cout << "Employe n: " << nEmploye_ << " nom : " << nom_ << " prenom : " << prenom_ << " departement : " << departement_ << endl;
};
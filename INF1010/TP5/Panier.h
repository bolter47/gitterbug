#ifndef PANIER_H
#define PANIER_H

#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/*************************************
 * FONCTEURS UNAIRES
 * pour ID
 * pour afficher
 * ***********************************/
 
template <typename OBJ>
class estID
{
public : 
	// id à comparer passè au constr.
	estID(int refID) : refID_(refID) {}

	// param etant l'objet dont on getID pour comparer avec refID
	bool operator() (OBJ param)
	{
		return (refID_ == param.getID());
	};

private :
	int refID_;
};

template <typename OBJ>
class afficheurContenu{
	public:
	void operator() (OBJ param)
	{
		cout << param << endl;
	};
};

/*************************************
 * CLASSE PANIER
 * ***********************************/

template <typename T>
class Panier{
	
	public:
	/********************************** 
	 * Constructeur 
	 **********************************/
	
	Panier(unsigned int id):id_(id){};
	
	/********************************** 
	 * Accesseurs 
	 **********************************/
	
	unsigned int getID() const{
		return id_;
	}
	
	/********************************** 
	 * Manip de la liste
	 **********************************/
	
	void ajouter(T nouvelElement){
		liste_.push_back(nouvelElement);
	};
	
	// Pas sûr si le const est une bonne idée ici, dépend des fct inclus, il se peut que nous devons assurer l'ordre
	T obtenirPlusPetitElement() const{
		return *min_element(liste_.begin(), liste_.end());
	};
	T obtenirPlusGrandElement() const{
		return *max_element(liste_.begin(), liste_.end());
	};
	
	void supprimer(unsigned int id){
		estID<T> pred(id);
		typename list<T>::iterator it = find_if(liste_.begin(), liste_.end(), pred);
		if (it != liste_.end() || pred(*liste_.end()))
			liste_.erase(it);
	};
	
	template<typename Pred>
	void supprimer(Pred pred){
		remove_if(liste_.begin(), liste_.end(), pred);
	};
	
	/******************************
	 * Surcharge d'opperateurs
	 ******************************/
	 template<typename OBJ>
	friend ostream& operator<<( ostream& out, Panier<OBJ>& panier){
		copy(panier.liste_.begin(), panier.liste_.end(), ostream_iterator<OBJ>(out, "\n"));
		return out;
	};
	
	private:
	/******************************
	 * Attributs
	 ******************************/
	unsigned int id_;
	list<T> liste_;
};


#endif

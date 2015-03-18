#ifndef PANIER_H
#define PANIER_H

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Panier{
	
	public:
	/********************************** 
	 * Constructeur 
	 **********************************/
	
	Panier(unsigned int id);
	
	/********************************** 
	 * Accesseurs 
	 **********************************/
	
	unsigned int getID() const;
	
	/********************************** 
	 * Manip de la liste
	 **********************************/
	
	void ajouter(T nouvelElement){
		liste_.push_back(nouvelElement);
	};
	
	// Pas sûr si le const est une bonne idée ici, dépend des fct inclus, il se peut que nous devons assurer l'ordre
	T obtenirPlusPetitElement() const{
		return *min_element(liste_.begin(), liste.end());
	};
	T obtenirPlusGrandElement() const{
		return *max_element(liste_.begin(), liste.end());
	};
	
	void supprimer(unsigned int id){
		//Implementation
		liste<t>::iterator it = find_if(liste_.begin(), liste_.end(), estID)
		liste_.erase(it);
	};
	
	template<typename Pred>
	void supprimer(Pred pred){
		//Implementation
	};
	
	/******************************
	 * Surcharge d'opperateurs
	 ******************************/
	friend ostream& operator<<( ostream& out, T& panier){
		//Implementation
	};
	
	
	private:
	/******************************
	 * Attributs
	 ******************************/
	int id_;
	list<T> liste_;
}
#endif

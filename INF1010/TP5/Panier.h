#ifndef PANIER_H
#define PANIER_H

#include <list>
#include <iostream>

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
		// Implementation
	};
	
	// Pas sûr si le const est une bonne idée ici, dépend des fct inclus
	T obtenirPlusPetitElement() const{
		//Implementation
	};
	T obtenirPlusGrandElement() const{
		//Implementation
	};
	
	void supprimer(unsigned int id){
		//Implementation
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

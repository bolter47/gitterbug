#ifndef PANIER_H
#define PANIER_H

#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/*************************************
 * FONCTEURS UNAIRES
 * estID: Compare si le ID de l'article passé en paramètre est la même que l'ID enregistre
 * afficheurContenu: Fais un cout de l'objet passé en paramètre à l'aide de l'operator<<
 * comparaison: Vŕifier si l'élément pointé par param1 < élément pointé par param2
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
		return (refID_ == param->getID());
	}

private :
	int refID_;
};

template <typename OBJ>
class afficheurContenu{
	public:
	void operator() (OBJ param)
	{
		// déréférencie param avant de le passer par cout
		cout << *param << endl;
	}
};

template <typename OBJ>
class comparaison{
	public:
	bool operator() (OBJ param1, OBJ param2){
		return *param1 < *param2;
	}
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
	
	void ajouter(T* nouvelElement){
		liste_.push_back(nouvelElement);
	};
	
	// MAX et MIN NE RISQUENT PAS DE FONCTIONNER BECAUSE POINTERS DAMNIT
	T obtenirPlusPetitElement() const{
		return **min_element(liste_.begin(), liste_.end(), comparaison<T*>());
	};
	T obtenirPlusGrandElement() const{
		return **max_element(liste_.begin(), liste_.end(), comparaison<T*>());
	};
	
	void supprimer(unsigned int id){
		estID<T*> pred(id);
		typename list<T*>::iterator it = find_if(liste_.begin(), liste_.end(), pred);
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
	
	/******************************
	 * Attributs
	 ******************************/
	private:
	unsigned int id_;
	
	protected:
	list<T*> liste_;
};


#endif

#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <string>
#include <typeinfo>

using namespace std;

class Afficheur
{
public:
	virtual ~Afficheur()
	{
	}

	virtual void	afficherFrancais()	const = 0;
	virtual void	afficherAnglais()	const = 0;

	virtual string	getTypeAfficheur()	const
	{
		return typeid(Afficheur).name();
	}
};

#endif

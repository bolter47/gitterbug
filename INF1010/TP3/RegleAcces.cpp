#include "RegleAcces.h"

using namespace std;

RegleAcces :: RegleAcces()
:(local_(""), niveauAccesRequis_(1), periode_(PERIODE_ACCES_MATIN))
{
}

RegleAcces::RegleAcces(unsigned int niveau, const string& local, const string& periode)
: (local_(local), niveauAccesRequis_(niveau), periode_(periode))
{
}

string  RegleAcces::getLocal() const
{
	return local_;
}

unsigned int RegleAcces::getNiveauAccesRequis() const
{
	return niveauAccesRequis_;
}

string RegleAcces::getPeriode() const
{
	return periode_;
}

bool RegleAcces::operator== (const RegleAcces& regle) const
{
	bool estMemeRegleAcces = false;
	if (local_ == regle.getLocal() && niveauAccesRequis_ == regle.getNiveauAccesRequis() && periode_ == regle.getPeriode())
	{
		estMemeRegleAcces = true;
	}

	return estMemeRegleAcces;
}
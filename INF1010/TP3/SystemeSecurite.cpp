#include "SystemeSecurite.h"

using namespace std;

SystemeSecurite::SystemeSecurite()
	:regles_(vector<RegleAcces>()), journalAcces_(vector<string>())
{
	//Implémenter l'initialisation des vecteurs journal et regles
}

bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode)
{
	bool estAccepte = false;
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_[i].getLocal() == local) &&
			(regles_[i].getPeriode() == periode) &&
			(regles_[i].getNiveauAccesRequis() >= agent.getNiveauAcces())){
			estAccepte = true;
		}
	}
	//String d'affichage
	return estAccepte;
}

bool SystemeSecurite::accederLocal(const Professeur& prof, const string& local, const string& periode)
{
	bool estAccepte = false;
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_.getLocal() == local) && 
			(regles_.getPeriode() == periode) && 
			(regles_.getNiveauAccesRequis() >= prof.getNiveauAcces())){
			estAccepte = true;
		}
	}
	//String d'affichage
	return estAccepte;
}

bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode)
{
	bool estAccepte = false;
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_.getLocal() == local) &&
			(regles_.getPeriode() == periode) &&
			(regles_.getNiveauAccesRequis() >= etudiant.getNiveauAcces())){
			estAccepte = true;
		}
	}
	//String d'affichage
	return estAccepte;
}

bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode)
{
	bool estAccepte = false;
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_.getLocal() == local) &&
			(regles_.getPeriode() == periode) &&
			(regles_.getNiveauAccesRequis() >= niveauAcces)){
			estAccepte = true;
		}
	}
	//String d'affichage
	return estAccepte;
}

bool SystemeSecurite::ajouterRegle(const RegleAcces& regle)
{ 
	bool estPresente = false;
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_.at(i).getLocal() == regle.getLocal()) && (regles_.at(i).getPeriode() == regle.getPeriode()) && (regles_.at(i).getNiveauAcces() == regle.getNiveauAcces())){
			estPresente = true;
		}
	}
	if (!estPresente){
		regles_.pushback(regle);
	}
	return estPresente;
}

void SystemeSecurite::imprimerJournal() const
{
	//Stringstream?
	int tailleVecteur = (journalAcces_.end() - journalAcces_.begin());
	for (int i = 0; i < tailleVecteur;i++){
		cout << journalAcces[i];
	}
}

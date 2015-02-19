#include "SystemeSecurite.h"
#include <sstream>

using namespace std;

SystemeSecurite::SystemeSecurite()
	:regles_(vector<RegleAcces>()), journalAcces_(vector<string>())
{
	//Implémenter l'initialisation des vecteurs journal et regles
}

bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode)
{
	bool estAccepte = false;
	stringstream ss;
	char niveauAccesString[3];
	sprintf(niveauAccesString, "%d", agent.getNiveauAcces());
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_[i].getLocal() == local) &&
			(regles_[i].getPeriode() == periode) &&
			(regles_[i].getNiveauAccesRequis() >= agent.getNiveauAcces())){
			estAccepte = true;
		}
	}
	journalAcces_.push_back(formatAffichage(agent.getNom(), agent.getPrenom(), agent.getClasseEmploye(), agent.getNiveauAcces(), local, periode, estAccepte));
	return estAccepte;
}

bool SystemeSecurite::accederLocal(const Professeur& prof, const string& local, const string& periode)
{
	bool estAccepte = false;
	char niveauAccesString[3];
	sprintf(niveauAccesString, "%d", prof.getNiveauAcces());
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_[i].getLocal() == local) && 
			(regles_[i].getPeriode() == periode) && 
			(regles_[i].getNiveauAccesRequis() >= prof.getNiveauAcces())){
			estAccepte = true;
		}
	}
	journalAcces_.push_back(formatAffichage(prof.getNom(), prof.getPrenom(), prof.getClasseEmploye(), prof.getNiveauAcces(), local, periode, estAccepte));
	return estAccepte;
}

bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode)
{
	bool estAccepte = false;
	char niveauAccesString[3];
	sprintf(niveauAccesString, "%d", etudiant.getNiveauAcces());
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_[i].getLocal() == local) &&
			(regles_[i].getPeriode() == periode) &&
			(regles_[i].getNiveauAccesRequis() >= etudiant.getNiveauAcces())){
			estAccepte = true;
		}
	}
	journalAcces_.push_back(formatAffichage(etudiant.getNom(), etudiant.getPrenom(), etudiant.getClasseEmploye(), etudiant.getNiveauAcces(), local, periode, estAccepte));
	return estAccepte;
}

bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode)
{
	bool estAccepte = false;
	char niveauAccesString[3];
	sprintf(niveauAccesString, "%d", niveauAcces);
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_[i].getLocal() == local) &&
			(regles_[i].getPeriode() == periode) &&
			(regles_[i].getNiveauAccesRequis() >= niveauAcces)){
			estAccepte = true;
		}
	}
	journalAcces_.push_back(formatAffichage(nom, prenom, fonction, niveauAcces, local, periode, estAccepte));

	return estAccepte;
}

bool SystemeSecurite::ajouterRegle(const RegleAcces& regle)
{ 
	bool estPresente = false;
	int tailleVecteur = (regles_.end() - regles_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		if ((regles_.at(i).getLocal() == regle.getLocal()) && (regles_.at(i).getPeriode() == regle.getPeriode()) && (regles_.at(i).getNiveauAccesRequis() == regle.getNiveauAccesRequis())){
			estPresente = true;
		}
	}
	if (!estPresente){
		regles_.push_back(regle);
	}
	return estPresente;
}

void SystemeSecurite::imprimerJournal() const
{
	int tailleVecteur = (journalAcces_.end() - journalAcces_.begin());
	for (int i = 0; i < tailleVecteur; i++){
		cout << journalAcces_[i];
	}
}

string SystemeSecurite :: formatAffichage(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode, const bool estAccede){
	stringstream ss;
	if (estAccede){
		ss << "Nom, Prenom:" << nom << ", " << prenom << endl
			<< "Classe d'employe: " << fonction << endl
			<< "Niveau d'acces: " << niveauAcces << endl
			<< "Local: " << local << endl
			<< "Periode: " << periode << endl
			<< "Acces: Accorde" << endl;
	}
	else{
		ss << "Nom, Prenom:" << nom << ", " << prenom << endl
			<< "Classe d'employe: " << fonction << endl
			<< "Niveau d'acces: " << niveauAcces << endl
			<< "Local: " << local << endl
			<< "Periode: " << periode << endl
			<< "Acces: Refuse" << endl;
	}
	
	string affichage = ss.str();
	return affichage;
}

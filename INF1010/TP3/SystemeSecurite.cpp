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
	journalAcces_.push_back(agent.getNom());
	journalAcces_.push_back(agent.getPrenom());
	journalAcces_.push_back(agent.getClasseEmploye());
	journalAcces_.push_back(niveauAccesString);
	journalAcces_.push_back(local);
	journalAcces_.push_back(periode);
	if (estAccepte){
		journalAcces_.push_back("Accorde");
	}
	else{
		journalAcces_.push_back("Refuse");
	}

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
	journalAcces_.push_back(prof.getNom());
	journalAcces_.push_back(prof.getPrenom());
	journalAcces_.push_back(prof.getClasseEmploye());
	journalAcces_.push_back(niveauAccesString);
	journalAcces_.push_back(local);
	journalAcces_.push_back(periode);
	if (estAccepte){
		journalAcces_.push_back("Accorde");
	}
	else{
		journalAcces_.push_back("Refuse");
	}
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
	journalAcces_.push_back(etudiant.getNom());
	journalAcces_.push_back(etudiant.getPrenom());
	journalAcces_.push_back(etudiant.getClasseEmploye());
	journalAcces_.push_back(niveauAccesString);
	journalAcces_.push_back(local);
	journalAcces_.push_back(periode);
	if (estAccepte){
		journalAcces_.push_back("Accorde");
	}
	else{
		journalAcces_.push_back("Refuse");
	}
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
	journalAcces_.push_back(nom);
	journalAcces_.push_back(prenom);
	journalAcces_.push_back(fonction);
	journalAcces_.push_back(niveauAccesString);
	journalAcces_.push_back(local);
	journalAcces_.push_back(periode);
	if (estAccepte){
		journalAcces_.push_back("Accorde");
	}
	else{
		journalAcces_.push_back("Refuse");
	}
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
	stringstream ss;
	string nom, prenom, fonction, niveauAcces, local, periode, acces;
	ss << "Nom, Prenom:" << nom << ", " << prenom << endl
		<< "Classe d'employe: " << fonction << endl
		<< "Niveau d'acces: " << niveauAcces << endl
		<< "Local: " << local << endl
		<< "Periode: " << periode << endl
		<< "Acces: " << acces << endl;

	int tailleVecteur = (journalAcces_.end() - journalAcces_.begin());
	int position = 0;
	for (int j = 0; j < ((tailleVecteur + 7) / 7); j++){
		for (int i = 0; i < 8; i++){
			ss << journalAcces_[position];
			position++;
		}
	}
	cout << ss.str() << endl;
}

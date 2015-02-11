#ifndef H_EMPLOYE
#define H_EMPLOYE

class Employe{
	public:
	
		/*** CONSTRUCTEURS/DESTRUCTEURS ***/
	Employe(const string& nom, const string& prenom);
	
		/*** GETTERS ***/
	string getNom() const;
	string getPrenom() const;
	int getNiveauAcces() const;
	string getClasseEmploye() const;
	
	private:
	
	const int accesEmploye_ = 5;
	
	friend ostream& operator<<(ostream out, Employe employe);	
	
	protected:
		string nom_;
		string prenom_;
}

#endif

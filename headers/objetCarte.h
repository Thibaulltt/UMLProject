#pragma once

#include <string>
#include <utility>

using namespace std;

class objetCarte {
	string nom;
	pair<int, int> coordonnees;

	public:
		objetCarte(string nom_n);			// Construction de l'objet
		pair<int,int> getCoordonnees();
		void setCoordonnees(pair<int,int>);
		void setCoordonnees(int,int);
		std::string getType();
};
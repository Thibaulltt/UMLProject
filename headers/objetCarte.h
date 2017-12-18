#pragma once

#include <string>
#include <utility>

using namespace std;

class objetCarte {

	protected:
		string nom;
		pair<int, int> coordonnees;
		bool ramassable;

	public:
		objetCarte();
		objetCarte(string nom_n, bool ramassable_n);
		pair<int,int> getCoordonnees();
		void setCoordonnees(pair<int,int>);
		void setCoordonnees(int,int);
		std::string getType();
		~objetCarte();
};
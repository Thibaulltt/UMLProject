#pragma once

#include <utility>
#include <string>

using namespace std;

class objetCarte {
	pair<int, int> coordonnees;

	public:
		pair<int,int> getCoordonnees();
		void setCoordonnees(pair<int,int>);
		void setCoordonnees(int,int);
		virtual std::string getType();
};
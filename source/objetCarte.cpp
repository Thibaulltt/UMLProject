#include <utility>
#include <string>

#include "../headers/objetCarte.h"

using namespace std;

pair<int,int> objetCarte::getCoordonnees() {
	return coordonnees;
}

void objetCarte::setCoordonnees(pair<int,int> nouvellesCoordonnees) {
	coordonnees.first = nouvellesCoordonnees.first;
	coordonnees.second = nouvellesCoordonnees.second;
}

void objetCarte::setCoordonnees(int nouveauX, int nouveauY) {
	coordonnees.first = nouveauX;
	coordonnees.second = nouveauY;
}

std::string objetCarte::getType() {
	return std::string("objetCarte");
}
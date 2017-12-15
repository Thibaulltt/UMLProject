#include <utility>
#include <string>

#include "../headers/objetCarte.h"

using namespace std;

pair<int,int> objetCarte::getCoordonnees() {
	return coords;
}

void objetCarte::setCoordonnees(pair<int,int> nouvellesCoordonnees) {
	coords.first = nouvellesCoordonnees.first;
	coords.second = nouvellesCoordonnees.second;
}

void objetCarte::setCoordonnees(int nouveauX, int nouveauY) {
	coords.first = nouveauX;
	coords.second = nouveauY;
}

std::string objetCarte::getType() {
	return std::string("objetCarte");
}
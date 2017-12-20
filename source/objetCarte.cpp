#include <string>
#include <typeinfo>
#include <utility>

#include "../headers/objetCarte.h"

using namespace std;

objetCarte::objetCarte()
{
}

objetCarte::objetCarte(string nom_n, bool ramassable_n)
{
	nom = nom_n;
	setCoordonnees(make_pair(0, 0));
	ramassable = ramassable_n;
	setCoordonnees(make_pair(0, 0));
}

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


string objetCarte::getType() {
	return typeid(this).name();
}

string objetCarte::toString()
{
	string stringRetour = nom;
	return stringRetour;
}

string objetCarte::getNom()
{
	return nom;
}

objetCarte::~objetCarte()
{
}
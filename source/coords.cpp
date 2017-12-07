#include <iostream>

#include "coords.h"

using namespace std;

//Fonctions classe coords

coords::coords()
{
	valeurs.first = 0;
	valeurs.second = 0;
}

coords::~coords()
{

}

void coords::setValeurs(pair<int, int> valeurs_n)
{
	valeurs.first = valeurs_n.first;
	valeurs.second = valeurs_n.second;
}

pair<int, int> coords::getValeurs()
{
	return valeurs;
}
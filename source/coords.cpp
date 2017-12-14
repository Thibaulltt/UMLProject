#include <iostream>

#include "../headers/coords.h"

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

void coords::setValeurs(coords valeurs_n)
{
	pair<int,int> bufferValue = valeurs_n.getValeurs();
	valeurs.first = bufferValue.first;
	valeurs.second = bufferValue.second;
}

pair<int, int> coords::getValeurs()
{
	return valeurs;
}
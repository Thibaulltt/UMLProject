#include "../headers/ennemi.h"

using namespace std;

ennemi::ennemi(string nom_n, bool ramassable_n) : entite(nom_n, ramassable_n)
{
	nom = nom_n;
	scoreATT = 100;
	scoreDEF = 100;
	ramassable = ramassable_n;
}


void ennemi::seDeplacer(carte mappe)
{
}

void ennemi::setVectPort(pair<int, int>, int)
{
}

void ennemi::attaquer()
{
}

string ennemi::toString()
{
	string stringRetour = "E/" + entite::toString();
	//string stringRetour = nom;
	return stringRetour;
}

ennemi::~ennemi()
{
}
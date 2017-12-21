#include "../headers/flibustier.h"


flibustier::flibustier(string nom_n, bool ramassable_n) : ennemi(nom_n, ramassable_n)
{
	nom = nom_n;
	scoreATT = 100;
	scoreDEF = 100;
	porteeATT = 1;
	ramassable = ramassable_n;
}

void flibustier::seDeplacer(carte mappe)
{
}

void flibustier::attaquer()
{
}

string flibustier::toString()
{
	string stringRetour = "F/" + ennemi::toString();
	return stringRetour;
}

flibustier::~flibustier()
{
}
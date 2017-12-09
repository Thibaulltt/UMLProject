#include "../headers/flibustier.h"


flibustier::flibustier(string nom_n) : ennemi(nom_n)
{
	nom = nom_n;
	scoreATT = 100;
	scoreDEF = 100;
	porteeATT = 1;
}
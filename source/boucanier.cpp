#include "../headers/boucanier.h"


boucanier::boucanier(string nom_n) : ennemi(nom_n)
{
	nom = "Boucanier";
	scoreATT = 100;
	scoreDEF = 100;
	porteeDEP = 2;
}
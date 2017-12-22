#include "../headers/flibustier.h"


flibustier::flibustier(string nom_n, bool ramassable_n) : ennemi(nom_n, ramassable_n)
{
	nom = nom_n;
	scoreATT = 100;
	scoreDEF = 100;
	porteeATT = 1;
	ramassable = ramassable_n;
	baseType = "flibustier";
}

void flibustier::setVectPort(pair<int, int> slot_n, int tailleMap)
{
	pair<int, int> pair_c = slot_n;
	pair<int, int> dummy;

	pair<int, int> sup_g = make_pair(pair_c.first - porteeATT, pair_c.second - porteeATT);
	pair<int, int> inf_d = make_pair(pair_c.first + porteeATT, pair_c.second + porteeATT);

	vectPort.resize(pow(sup_g.second - sup_g.first + 1, 2));

	dummy = pair_c;
	vectPort.push_back(dummy);

	for (int i = sup_g.first; i <= inf_d.first; i++)
	{
		for (int j = sup_g.second; j <= inf_d.second; j++)
		{
			if (i < 0 || j < 0 || i > tailleMap || j > tailleMap)	//hors map
			{
				continue;
			}

			dummy = make_pair(i, j);
			vectPort.push_back(dummy);
		}
	}
}

void flibustier::seDeplacer(carte mappe)
{
}

bool flibustier::attaquer(entite * adver)
{
	double d_resATTFlib = (this->getScoreATT() * 100) / adver->getScoreDEF();
	d_resATTFlib = ceil(d_resATTFlib - 100); //Chances de tuer sur 100 (arrondies à l'unité supérieure)
	int resATTFlib = (int)d_resATTFlib;	//Conversion entier

	int alea = rand() % 100 + 1;	//entre 1 et 100

	if (alea < resATTFlib)	//Coup fatal
	{
		return true;
	}
	return false;
}

string flibustier::toString()
{
	string stringRetour = "F/" + ennemi::toString();
	return stringRetour;
}

flibustier::~flibustier()
{
}
#include "../headers/boucanier.h"


boucanier::boucanier(string nom_n) : ennemi(nom_n)
{
	nom = nom_n;
	scoreATT = 100;
	scoreDEF = 100;
	porteeDEP = 2;
}

void boucanier::seDeplacer(carte mappe)
{

}

void boucanier::setVectPort(pair<int, int> slot_n, int tailleMap) //[A DEPLACER DANS ENTITE CONCERNEE]
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
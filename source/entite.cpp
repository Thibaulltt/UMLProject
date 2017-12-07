#include "../headers/coords.h"
#include "../headers/entite.h"

using namespace std;

//Fonctions classe entite

entite::entite(string nom_n)
{
	nom = nom_n;
	porteeDEP = 1;
	scoreATT = 0;
	porteeATT = 0;
	scoreDEF = 0;
	vivant = true;
	slot.setValeurs(pair<int, int>(0, 0));
}

string entite::getNom()
{
	return nom;
}

int entite::getScoreATT()
{
	return scoreATT;
}

int entite::getScoreDEF()
{
	return scoreDEF;
}

void entite::setSlot(pair<int, int> slot_n)
{
	slot.setValeurs(pair<int, int>(slot_n.first, slot_n.second));
}

coords entite::getSlot()
{
	return slot;
}

void entite::setVectPort(coords slot_n)
{
	vectPort.resize(8 * porteeATT);	//8 directions

	pair<int, int> pair_c = slot_n.getValeurs();
	coords dummy;

	for (int i = 0; i < 8; i++)	//8 coordonnées à entrer
	{
		for (int j = 1; j <= porteeATT; j++)	//Prolongement des coordonnées (= portée)
		{
			dummy.setValeurs(pair<int, int>(pair_c.first - (1 * i), pair_c.second - (1 * i)));	//(x-i, y-1)
			vectPort.push_back(dummy);
			dummy.setValeurs(pair<int, int>(pair_c.first - (1 * i), pair_c.second));			//(x-i, y)
			vectPort.push_back(dummy);			
			dummy.setValeurs(pair<int, int>(pair_c.first - (1 * i), pair_c.second + (1 * i)));	//(x-i, y+i)
			vectPort.push_back(dummy);
			dummy.setValeurs(pair<int, int>(pair_c.first, pair_c.second - (1 * i)));			//(x, y-i)
			vectPort.push_back(dummy);
			dummy.setValeurs(pair<int, int>(pair_c.first, pair_c.second + (1 * i)));			//(x, y+i)
			vectPort.push_back(dummy);
			dummy.setValeurs(pair<int, int>(pair_c.first + (1 * i), pair_c.second - (1 * i)));	//(x+i, y-1)
			vectPort.push_back(dummy);
			dummy.setValeurs(pair<int, int>(pair_c.first + (1 * i), pair_c.second));			//(x+i, y)
			vectPort.push_back(dummy);
			dummy.setValeurs(pair<int, int>(pair_c.first + (1 * i), pair_c.second + (i * i)));	//(x+i, y+i)
			vectPort.push_back(dummy);
		}
	}
}

vector<coords> entite::getVectPort()
{
	return vectPort;
}

entite::~entite()
{

}
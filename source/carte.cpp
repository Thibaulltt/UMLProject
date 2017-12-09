#include <vector>

#include "../headers/carte.h"

using namespace std;

//Fonctions classe carte
carte::carte()
{
	taille = 12;
	aireJeu.resize(taille);

	vector<vector<int>>::iterator it_vvi;

	for (it_vvi = aireJeu.begin(); it_vvi != aireJeu.end(); it_vvi++)
	{
		for (int i = 0; i < 12; i++)
		{
			(*it_vvi).push_back(0);
		}
	}
}

int carte::getTaille()
{
	return taille;
}

void carte::setAireJeu(pair<int, int> slot, int value)
{
	aireJeu[slot.first][slot.second] = value;
}

void carte::setCase(pair<int, int> slot, int value)
{

}

int carte::getCase(pair<int,int> slot) 
{
	return aireJeu[slot.first][slot.second];
}

vector<vector<int>> carte::getAireJeu()
{
	return aireJeu;
}

carte::~carte()
{

}
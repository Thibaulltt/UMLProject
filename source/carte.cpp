#include <vector>
#include <iostream>
#include "../headers/carte.h"
#include "../headers/objetCarte.h"

using namespace std;

//Fonctions classe carte
carte::carte()
{
}

carte::carte(int taille_n)
{
	taille = taille_n;
	aireJeu.resize(taille);

	vector<vector<vector<objetCarte *>>>::iterator it_vvi;	//Parcours carte

	for (it_vvi = aireJeu.begin(); it_vvi != aireJeu.end(); it_vvi++)	//Pour toute la carte
	{
		for (unsigned int i = 0; i < taille; i++)	//Pour chaque case carte
		{
			vector<objetCarte *> vect_objC;	//Vecteur d'objets			
			(*it_vvi).push_back(vect_objC);	//Rajout vecteur d'objets dans case carte
		}
	}
}

string carte::toString()
{
	string stringRetour = "";

	for (int i = 0; i < aireJeu.size(); i++)
	{
		for (unsigned long j = 0; j < aireJeu[i].size(); j++)
		{
			if (aireJeu[i][j].size() == 0) // Si case vide
			{
				stringRetour += "0";
			}
			
			if (aireJeu[i][j].size() != 0) // Si case non vide
			{
				for (unsigned long k = 0; k < aireJeu[i][j].size(); k++)
				{
					if (aireJeu[i][j][k]->getVivant())
					{
						if (k != (aireJeu[i][j].size()) - 1)
						{
							stringRetour += aireJeu[i][j][k]->toString() + "$";
						}
						else
						{
							stringRetour += aireJeu[i][j][k]->toString();
						}
					}
				}
			}

			stringRetour += "|";
		}
	}

	return stringRetour;

	/*Format retour : 
0 si case vide
| séparateur de case
$ séparateur de ce qui se trouve dans une case
	*/
}

void carte::delObjet(int x, int y, int position)
{
	aireJeu[x][y].erase(aireJeu[x][y].begin() + position);
}


int carte::getTaille()
{
	return taille;
}


void carte::setCase(pair<int, int> slot, objetCarte * objC)
{
	aireJeu[slot.first][slot.second].push_back(objC);
}

vector<objetCarte *> carte::getCase(pair<int,int> slot) 
{
	return aireJeu[slot.first][slot.second];
}

vector<vector<vector<objetCarte *>>> carte::getAireJeu()
{
	return aireJeu;
}

carte::~carte()
{
}
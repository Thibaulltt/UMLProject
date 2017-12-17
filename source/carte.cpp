#include <vector>

#include "../headers/carte.h"

using namespace std;

//Fonctions classe carte
carte::carte(int taille_n)
{
	taille = taille_n;
	aireJeu.resize(taille);

	objetCarte objC;	//Objet vide à insérer

	vector<vector<vector<objetCarte>>>::iterator it_vvi;	//Parcours carte

	for (it_vvi = aireJeu.begin(); it_vvi != aireJeu.end(); it_vvi++)	//Pour toute la carte
	{
		for (int i = 0; i < taille; i++)	//Pour chaque case carte
		{
			vector<objetCarte> vect_objC;	//Vecteur d'objets			
			vect_objC.push_back(objC);		//Rajout objet vide
			(*it_vvi).push_back(vect_objC);	//Rajout vecteur d'objets dans case carte
		}
	}
}

string carte::carteString()
{
	string stringRetour = "";

	for (int i = 0; i < aireJeu.size(); i++)
	{
		for (int j = 0; j < aireJeu[i].size(); j++)
		{
			stringRetour += to_string(aireJeu[i][j]);
		}
	}

	return stringRetour;
}


int carte::getTaille()
{
	return taille;
}


void carte::setCase(pair<int, int> slot, objetCarte objC)
{
	aireJeu[slot.first][slot.second].push_back(objC);
}

vector<objetCarte> carte::getCase(pair<int,int> slot) 
{
	return aireJeu[slot.first][slot.second];
}

vector<vector<vector<objetCarte>>> carte::getAireJeu()
{
	return aireJeu;
}

carte::~carte()
{
}
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

#include "../headers/carte.h"
#include "../headers/entite.h"
#include "../headers/objetCarte.h"

using namespace std;

//Fonctions classe entite

entite::entite(string nom_n, bool ramassable_n) : objetCarte(nom_n, ramassable_n)
{
	nom = nom_n;
	porteeDEP = 1;
	scoreATT = 0;
	porteeATT = 0;
	scoreDEF = 0;
	vivant = true;
	ramassable = ramassable_n;
}

vector<pair<int, int>> entite::getVectPort()
{
	return vectPort;
}

int entite::getScoreATT()
{
	return scoreATT;
}

int entite::getScoreDEF()
{
	return scoreDEF;
}

void entite::setVivant(bool vivant_n)
{
	vivant = vivant_n;
}

bool entite::getVivant()
{
	return vivant;
}

void entite::seDeplacer(carte mappe)
{
}

void entite::setVectPort(pair<int, int>, int)
{
}

void entite::attaquer()
{
}

string entite::toString() //Format retour : nom / porteeATT : scoreATT : scoreDEF
{
	string stringRetour = objetCarte::toString();

	//Ajout stats
	string stats = to_string(porteeATT) + ":" + to_string(scoreATT) + ":" + to_string(scoreDEF);

	//String final
	stringRetour += "/" + stats;

	return stringRetour;
}

entite::~entite()
{
}
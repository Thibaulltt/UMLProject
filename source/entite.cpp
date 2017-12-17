#include <math.h>
#include <string>
#include <vector>

#include "../headers/carte.h"
#include "../headers/entite.h"

using namespace std;

//Fonctions classe entite

entite::entite(string nom_n)	//Ca marche ça?
{
	porteeDEP = 1;
	scoreATT = 0;
	porteeATT = 0;
	scoreDEF = 0;
	vivant = true;
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

void entite::setVivant(bool vivant_n)
{
	vivant = vivant_n;
}

bool entite::getVivant()
{
	return vivant;
}

entite::~entite() {}

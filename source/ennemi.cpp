#include "../headers/ennemi.h"

using namespace std;

ennemi::ennemi(string nom_n, bool ramassable_n) : entite(nom_n, ramassable_n)
{
	nom = nom_n;
	scoreATT = 100;
	scoreDEF = 100;
	ramassable = ramassable_n;
}

string ennemi::ennemiString() //Format retour : nom / coordX : coordY / boolVivant / porteeDEP : scoreATT : scoreDEF
{
	//string stringRetour = "";

	////Ajout coordonnées
	//string coordonnees = to_string(getCoordonnees().first) + ":" + to_string(getCoordonnees().second);

	////Ajout bool
	//string booleens = to_string(vivant);

	////Ajout stats
	//string stats = to_string(porteeATT) + ":" + to_string(scoreATT) + ":" + to_string(scoreDEF);

	////String final
	//stringRetour = nom + "/" + coordonnees + "/" + booleens + "/" + stats;


	//return stringRetour;
}

void ennemi::seDeplacer(carte mappe)
{
}

void ennemi::setVectPort(pair<int, int>, int)
{
}

void ennemi::attaquer()
{
}

ennemi::~ennemi()
{
}
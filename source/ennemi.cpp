﻿#include "../headers/ennemi.h"

using namespace std;

ennemi::ennemi(string nom_n) : entite(nom_n)
{
	scoreATT = 100;
	scoreDEF = 100;
}

string ennemi::ennemiString() //Format retour : nom / coordX : coordY / boolVivant / porteeDEP : scoreATT : scoreDEF
{
	string stringRetour = "";

	//Ajout coordonnées
	string coordonnees = to_string(slot.getValeurs().first) + ":" + to_string(slot.getValeurs().second);

	//Ajout bool
	string booleens = to_string(vivant);

	//Ajout stats
	string stats = to_string(porteeATT) + ":" + to_string(scoreATT) + ":" + to_string(scoreDEF);

	//String final
	stringRetour = nom + "/" + coordonnees + "/" + booleens + "/" + stats;


	return stringRetour;
}


void ennemi::attaquer()
{

}

void ennemi::deplacerMob()
{

}
#include <iostream>
#include <string>
#include <vector>

#include "../headers/ennemi.h"
#include "../headers/joueur.h"
#include "../headers/objet.h"


#pragma once

using namespace std;

class jeu
{
	int nb_joueurs;
	int difficulte;
	vector<joueur> vect_joueur;
	vector<objet> vect_objet;
	vector<ennemi> vect_ennemi;

public:
	jeu();
	void lancerPartie();
	void tourJoueur(joueur player);
	vector<joueur> getVectJoueur();
	vector<ennemi> getVectEnnemi();
	void tourEnnemi(ennemi enemy);
	~jeu();
};

//Fonctions diverses
bool isNumber(std::string s_input);

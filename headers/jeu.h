#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../headers/ennemi.h"
#include "../headers/joueur.h"
#include "../headers/objet.h"

using namespace std;

class jeu
{
	int nb_joueurs;
	int difficulte;
	vector<joueur> vect_joueur;
	vector<objet> vect_objet;
	vector<ennemi> vect_ennemi;
	carte mappe;

public:
	jeu();
	int lancerPartie();
	void tourJoueur(joueur player);
	vector<joueur> getVectJoueur();
	void tourEnnemi(ennemi enemy, int & nb_joueurs_n);
	vector<ennemi> getVectEnnemi();
	~jeu();
};

//Fonctions diverses
bool isInteger(std::string s_input);

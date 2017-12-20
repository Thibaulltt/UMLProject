#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../headers/ennemi.h"
#include "../headers/joueur.h"
#include "../headers/objetCarte.h"
#include "../headers/objetCombat.h"
#include "../headers/flibustier.h"

using namespace std;

class jeu
{
	int nb_joueurs;
	int difficulte;
	vector<joueur*> vect_joueur;
	vector<objetCarte*> vect_objet;
	vector<ennemi*> vect_ennemi;
	carte mappe;

public:
	jeu(int taille_n);
	int lancerPartie();
	void tourJoueur(joueur * player);
	vector<joueur*> getVectJoueur();
	void tourEnnemi(ennemi * enemy, int & nb_joueurs_n);
	vector<ennemi*> getVectEnnemi();
	void sauvegarderPartie();
	~jeu();
};

//Fonctions diverses
bool isInteger(std::string s_input);

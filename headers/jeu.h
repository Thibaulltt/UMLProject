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
	void tourEnnemi(ennemi enemy);
	vector<ennemi> getVectEnnemi();
	void supprEnnemi(int index);
	void supprJoueur(int index);
	bool tourCheck();
	void tourEnnemi(ennemi enemy);
	vector<ennemi> getVectEnnemi();
	~jeu();
};

//Fonctions diverses
bool isInteger(std::string s_input);

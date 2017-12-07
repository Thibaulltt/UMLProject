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
<<<<<<< HEAD
	void supprJoueur(int index);
=======
	bool tourCheck();
	void tourEnnemi(ennemi enemy);
	vector<ennemi> getVectEnnemi();
>>>>>>> 9564d06ae7c0771892a5a4e78d295d012120ea55
	~jeu();
};

//Fonctions diverses
bool isInteger(std::string s_input);

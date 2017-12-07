// Ici, on definit le namespace IO, qui sert a
// se charger de toutes les operations d'entree
// sortie du programme.

#include <iostream>
#include <vector>
#include "carte.h"
#include "coords.h"
#include "joueur.h"
#include "ennemi.h"

namespace io {
	/////
	/////
	////
	
	extern pair<int,int> positionJoueur;
	// Vecteur de paire contenant un ennemi et une coordonnee
	extern vector<pair<ennemi,coords>> positionEnnemi;

	////
	/////
	////
	extern void afficherCarte(vector<vector<int>>);
	extern void choisirCase();
};
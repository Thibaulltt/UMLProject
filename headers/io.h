// Ici, on definit le namespace IO, qui sert a
// se charger de toutes les operations d'entree
// sortie du programme.

#include <iostream>
#include <vector>
#include <string>
#include "carte.h"
#include "coords.h"
#include "joueur.h"
#include "ennemi.h"

namespace io {
	/////////////////////////////////
	/////////////////////////////////
	///// Variables necessaires /////
	/////////////////////////////////
	/////////////////////////////////
	
	// Retiens la position du joueur pour mettre a jour l'affichage de la carte
	extern coords positionJoueur;
	// Vecteur de paire contenant un ennemi et une coordonnee
	extern vector< pair<ennemi,coords> > positionEnnemi;

	//////////////////////////////////
	//////////////////////////////////
	///// Fonctions a developper /////
	//////////////////////////////////
	//////////////////////////////////
	//affiche la totalite de la carte
	extern void afficherCarte(vector< vector<int> >);
	// permet au joueur de choisir ou il va se deplacer
	extern void choisirCase(coords&);
	// affiche un message dans la baniere en bas du jeu
	extern void afficherMessage(int, string);
	// contient case a mettre a jour
	extern void updateCarte(coords);
};
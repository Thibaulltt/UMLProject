#ifndef IO_H
#define IO_H
#pragma once 
// Ici, on definit le namespace IO, qui sert a
// se charger de toutes les operations d'entree
// sortie du programme.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <vector>
#include <termios.h>
#include "carte.h"
#include "coords.h"
#include "joueur.h"
#include "ennemi.h"
#include "carte.h"

namespace io {
	/////////////////////////////////
	/////////////////////////////////
	///// Variables necessaires /////
	/////////////////////////////////
	/////////////////////////////////
	
	// Retiens la position du joueur pour mettre a jour l'affichage de la carte
	extern coords positionJoueur;
	// Retiens la marge du coin HG de la carte par rapport au coin HG du terminal
	extern coords margesCarte;
	// Vecteur de paire contenant un ennemi et une coordonnee
	extern vector< pair<ennemi,coords> > positionEnnemi;
	extern int TermWidth;
	extern int TermHeight;
	static struct termios before, after;

	//////////////////////////////////
	//////////////////////////////////
	///// Fonctions a developper /////
	//////////////////////////////////
	//////////////////////////////////

	// prends la largeur du terminal
	int getTerminalWidth();
	// prends la hauteur du terminal
	int getTerminalHeight();
	void ChangeTerminal(bool Ech = 0);
	void ResetTerminal();
	char de();
	//affiche la totalite de la carte
	extern void afficherCarte(carte);
	// permet au joueur de choisir ou il va se deplacer
	extern void choisirCase(carte, coords&);
	// affiche un message dans la baniere en bas du jeu
	extern void updateMessage(int, string);
	extern void afficherMessage();
	// contient case a mettre a jour
	extern void updateCarte(coords);
	// genere les mouvements possibles sur une case passee en argument
	vector< pair<coords,bool> > genererMouvements(carte, pair<int,int>);
	// verifie que le terminal est bien configure avant de commencer le programme
	bool setup();
}
#endif
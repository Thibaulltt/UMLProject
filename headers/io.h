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
#include "joueur.h"
#include "ennemi.h"
#include "carte.h"

namespace io {
	/////////////////////////////////
	/////////////////////////////////
	///// Variables necessaires /////
	/////////////////////////////////
	/////////////////////////////////
	
	//! Retiens la position du joueur pour mettre a jour l'affichage de la carte
	extern pair<int,int> positionJoueur;
	//! Retiens la marge du coin HG de la carte par rapport au coin HG du terminal
	extern pair<int,int> margesCarte;
	//! Vecteur de paire contenant un ennemi et une coordonnee
	extern vector< pair<ennemi,pair<int,int>> > positionEnnemi;
	//! Largeur du terminal
	extern int TermWidth;
	//! Hauteur du terminal
	extern int TermHeight;
	//! Stockage des états du terminal
	static struct termios before, after;

	//////////////////////////////////
	//////////////////////////////////
	///// Fonctions a developper /////
	//////////////////////////////////
	//////////////////////////////////

	//! Prends la largeur du terminal
	int getTerminalWidth();
	//! Prends la hauteur du terminal
	int getTerminalHeight();
	//! Change le mode d'entrée standard du terminal
	void ChangeTerminal(bool Ech = 0);
	//! Remet le terminal comme avant
	void ResetTerminal();
	//! Entrée d'un seul caractère
	char de();
	
	//! Affiche la totalite de la carte
	extern void afficherCarte(carte);
	
	//! Permet au joueur de choisir ou il va se deplacer
	extern void choisirCase(carte, pair<int,int>&);
	
	//! Affiche un message dans la baniere en bas du jeu
	extern void updateMessage(int, string);
	extern void afficherMessage();
	
	//! Contient case à mettre a jour
	extern void updateCarte(pair<int,int>);
	
	//! Genere les mouvements possibles sur une case passee en argument
	vector< pair<pair<int,int>,bool> > genererMouvements(carte, pair<int,int>);

	//! Verifie que le terminal est bien configuré avant de commencer le programme
	bool setup();
}
#endif
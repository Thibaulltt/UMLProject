﻿// Corps de toutes les fonctions du namespace IO

#include <iostream>
#include <fstream>
#include <utility>
#include <stdio.h>
#include <termios.h>
#include "../headers/io.h"
#include "../headers/carte.h"

// Taille de la carte
#define MAX_X_MAP 12
#define MAX_Y_MAP 12
// Taille requise du terminal
#define TERM_MIN_WIDTH MAX_X_MAP+2
#define TERM_MIN_HEIGHT MAX_Y_MAP+5
// Fonctions emettant un code echappement terminal
#define TERM_ERASE_LINE printf("\033[K")
#define TERM_ERASE_SCREEN printf("\033[2J")
#define TERM_MOVE_CURSOR_UP(s) printf("\033[%iA",(s))
#define TERM_MOVE_CURSOR_DOWN(s) printf("\033[%iB",(s))
#define TERM_MOVE_CURSOR_RIGHT(s) printf("\033[%iC",(s))
#define TERM_MOVE_CURSOR_LEFT(s) printf("\033[%iD",(s))
// Sequences d'echappement pour le terminal
#define BLANK "\033[0m"
#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define MAGENTA "\033[95m"

using namespace std;

namespace io {

	int TermHeight = 0;
	int TermWidth = 0;

	int getTerminalWidth()
	{
		FILE * r;
		std::string w1,w2;
		char * ww1 = new char[6];
		char * ww2 = new char[6];
		system("stty -a | grep row | cut -d\' \' -f 7 >> dump.txt");
		r = fopen("dump.txt", "r");
		w1 = fgets(ww1,5,r);
		fclose(r);
		system("rm dump.txt");
		system("stty -a | grep row | cut -d\' \' -f 6 >> dump.txt");
		r = fopen("dump.txt", "r");
		w2 = fgets(ww2,5,r);
		fclose(r);
		system("rm dump.txt");
		if (w1[0] == 'c')
		{
			io::TermWidth = std::stoi(w2.substr(0,w2.size()-1));
			return io::TermWidth;
		}
		else
		{
			io::TermWidth = std::stoi(w1.substr(0,w1.size()-1));
			return io::TermWidth;
		}
	}

	int getTerminalHeight()
	{
		FILE * r;
		std::string h1,h2;
		char * hh1 = new char[6];
		char * hh2 = new char[6];
		system("stty -a | grep row | cut -d\' \' -f 5 >> dump.txt");
		r = fopen("dump.txt", "r");
		h1 = fgets(hh1,5,r);
		fclose(r);
		system("rm dump.txt");
		system("stty -a | grep row | cut -d\' \' -f 4 >> dump.txt");
		r = fopen("dump.txt", "r");
		h2 = fgets(hh2,5,r);
		fclose(r);
		system("rm dump.txt");
		if (h1[0] == 'r')
		{
			io::TermHeight = std::stoi(h2.substr(0,h2.size()-1));
			return io::TermHeight;
		}
		else
		{
			io::TermHeight = std::stoi(h1.substr(0,h1.size()-1));
			return io::TermHeight;
		}
	}

	void choisirCase(carte gameMap, coords &posJ){
		//a faire dans joueur.cpp, fonction deplacerJoueur :
		/*
		prendre coordonnees joueur actuelles
		les mettre dans un type <coords>
		appeller choisirCase(positionJoueur)
		la nouvelle coordonnee sera mise dans la position actuelle joueur
		*/
		// a faire ici :
		/*
		variables : x,y (tiennent temporairement la position voulue par le joueur)

		prendre coordonnees actuelles
		verifier ou il peut aller (en regardant coordonnees + taille carte)
		proposer les bons prompt sur le message de bas d'ecran
		mettre a jour le message de bas d'ecran
		afficher une croix ou le joueur peut aller
		mettre a jour la carte
		faire :
			- attendre entree clavier
			- quand entree clavier, verifier que on peut l'accepter (joueur peut se deplacer la)
			- mettre a jour affichage
			- mettre a jour coordonnees choisies
		tant que entree != touche valider
		une fois la case choisie :
		mettre x,y dans posJ
		mettre a jour affichage
		retourner
		*/
		vector< pair<coords,bool> > positionsPossibles = genererMouvements(gameMap, posJ.getValeurs()); // Positions possibles dans la vicinite directe du joueur
		// Maintenant on update l'affichage pour chaque case dispo
		// afficherMouvements(positionsPossibles);
		cout << "Test : " << TERM_MOVE_CURSOR_LEFT(6) << "his" << TERM_MOVE_CURSOR_RIGHT(3) << "is bullshit." << TERM_MOVE_CURSOR_DOWN(2) << TERM_MOVE_CURSOR_RIGHT(1) << printf("\033[%iC",1)  << printf("\033[%iC",1) << endl;
		return;
	}

	vector< pair<coords,bool> > genererMouvements(carte gameMap, pair<int,int> playerPos) {
		// Generation du vecteur avec des valeurs de base
		vector< pair<coords,bool> > resultVector;
		// Coordonnees utilisees pour la paire dans le vecteur
		coords dummyCoordinates;
		for (int i = -1; i <= 1; i++) { // i va iterer pour x
			for (int j = -1; j <= 1; j++) { // j va iterer pour y
				dummyCoordinates.setValeurs(std::make_pair(playerPos.first+i, playerPos.second+j));
				resultVector.push_back(std::make_pair(dummyCoordinates, false));
			}
		}
		// Des valeurs par default sont initialisees, donc on les traite maintenant
		// On itere de vector.begin() a vector.end()
		for (vector< pair<coords,bool> >::iterator i = resultVector.begin(); i != resultVector.end(); i++) {
			int x = i->first.getValeurs().first;
			int y = i->first.getValeurs().second;
			if (x >= 0 && x < MAX_X_MAP && y >= 0 && y < MAX_Y_MAP) {
				// Si la case de la map est pas prise
				if (gameMap.getCase(i->first.getValeurs()) == 0) {
					// Mettre la valeur a true
					i->second = true;
				}
			}
		}
		return resultVector;
	}

	bool setup() {
		// Verifie d'abord la taille du terminal
		int tempTermWidth = getTerminalWidth();
		int tempTermHeight = getTerminalHeight();
		while (tempTermWidth < io::TermWidth || tempTermHeight < io::TermHeight) {
			cout << TERM_ERASE_SCREEN;
			cout << "Taille non conforme. Veillez a ce que votre terminal soit d'une taille superieure ou egale a ";
			cout << TERM_MIN_WIDTH << "x" << TERM_MIN_HEIGHT;
			cout << ".\nAppuyez sur une touche une fois votre terminal redimensionne." << endl;
		}
	}
}
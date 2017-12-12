// Corps de toutes les fonctions du namespace IO

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "../headers/io.h"
#include "../headers/carte.h"

// Taille de la carte
#define MAX_X_MAP 12
#define MAX_Y_MAP 12
// Infos relatives au bandereau de message
#define TERM_MESSAGE_HEIGHT 5
#define TERM_MESSAGE_LINES_AVAILABLE TERM_MESSAGE_HEIGHT-2
#define TERM_MESSAGE_REFRESH_DELAY 4
// Taille requise du terminal
#define TERM_MIN_WIDTH MAX_X_MAP+2
#define TERM_MIN_HEIGHT MAX_Y_MAP+TERM_MESSAGE_HEIGHT
// Fonctions emettant un code echappement terminal pour le mouvement curseur
#define TERM_ERASE_LINE printf("\033[K")
#define TERM_ERASE_SCREEN printf("\033[2J")
#define TERM_MOVE_CURSOR_UP(s) printf("\033[%iA",(s))
#define TERM_MOVE_CURSOR_DOWN(s) printf("\033[%iB",(s))
#define TERM_MOVE_CURSOR_RIGHT(s) printf("\033[%iC",(s))
#define TERM_MOVE_CURSOR_LEFT(s) printf("\033[%iD",(s))
#define TERM_MOVE_CURSOR_GOTO(x,y) printf("\033[%i;%if",(x),(y))
// Sequences d'echappement pour la couleur dans le terminal
#define TERM_COLOR_TEXT_BLANK "\033[0m"
#define TERM_COLOR_TEXT_RED "\033[91m"
#define TERM_COLOR_TEXT_GREEN "\033[92m"
#define TERM_COLOR_TEXT_YELLOW "\033[93m"
#define TERM_COLOR_TEXT_BLUE "\033[94m"
#define TERM_COLOR_TEXT_MAGENTA "\033[95m"

using namespace std;

namespace io {

	int TermHeight = 0;
	int TermWidth = 0;
	coords margesCarte;

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

	void ChangeTerminal(bool Ech)
	{
		tcgetattr(0, &before);			/* Grab old terminal i/o settings */
		after = before;				/* Make new settings same as old settings */
		after.c_lflag &= ~ICANON;		/* Disable buffered i/o */
		after.c_lflag &= Ech==1 ? ECHO:~ECHO;	/* Set echo mode */
		tcsetattr(0, TCSANOW, &after);		/* Use these new terminal i/o settings now */
	}

	void ResetTerminal()
	{
		tcsetattr(0, TCSANOW, &before);		// Restore old terminal I/O settings
	}

	char de()
	{
		char ch;				// Return character
		ChangeTerminal();
		ch = getchar();				// getchar() ne prends qu'un caractère
		ResetTerminal();
		if (ch == 27)
			throw 27;
		return ch;
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
		  = fonction genererMouvements()
		proposer les bons prompt sur le message de bas d'ecran
		mettre a jour le message de bas d'ecran
		afficher une croix ou le joueur peut aller
		mettre a jour la carte
		  = fonction afficherMouvements()
		faire :
			- attendre entree clavier
			- quand entree clavier, verifier que on peut l'accepter (joueur peut se deplacer la)
			- mettre a jour affichage
			- mettre a jour coordonnees choisies
			  = fonction updateMouvements()
		tant que entree != touche valider
		une fois la case choisie :
		mettre x,y dans posJ
		mettre a jour affichage
		retourner
		*/
		vector< pair<coords,bool> > positionsPossibles = genererMouvements(gameMap, posJ.getValeurs()); // Positions possibles dans la vicinite directe du joueur
		// Maintenant on update l'affichage pour chaque case dispo
		// afficherMouvements(positionsPossibles);
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
		// Tant que le terminal est pas de la bonne taille
		while (tempTermWidth < io::TermWidth || tempTermHeight < io::TermHeight) {
			cout << TERM_ERASE_SCREEN;
			cout << "Taille non conforme. Veillez a ce que votre terminal soit d'une taille superieure ou egale a ";
			cout << TERM_MIN_WIDTH << "x" << TERM_MIN_HEIGHT;
			cout << ".\nAppuyez sur une touche une fois votre terminal redimensionne." << endl;
		}
		return true;
	}

	void afficherCarte(carte gameMap) {
		TERM_ERASE_SCREEN;

		io::TermHeight = getTerminalHeight();
		io::TermWidth = getTerminalWidth();
		int leftMarginMap = (io::TermWidth - MAX_X_MAP) / 2;
		int upperMarginMap = (io::TermHeight - MAX_Y_MAP - TERM_MESSAGE_HEIGHT) / 2;
		if (upperMarginMap != 0) {
			cout << std::string(upperMarginMap, '\n');
		}
		for (int i = 0; i < MAX_Y_MAP; i++) {
			cout << std::string(leftMarginMap, ' ');
			for (int j = 0; j < MAX_X_MAP; j++) {
				int contenuCase = gameMap.getCase(std::make_pair(i,j));
				switch (contenuCase) {
					case 1:
						cout << TERM_COLOR_TEXT_BLUE << 'X' << TERM_COLOR_TEXT_BLANK;
						break;
					case 2:
						cout << TERM_COLOR_TEXT_GREEN << 'Y' << TERM_COLOR_TEXT_BLANK;
						break;
					case 3:
						cout << TERM_COLOR_TEXT_MAGENTA << 'O' << TERM_COLOR_TEXT_BLANK;
						break;
					case 4:
						cout << TERM_COLOR_TEXT_RED << 'A' << TERM_COLOR_TEXT_BLANK;
						break;
					default:
						cout << ' ';
						break;
				}
			}
			cout << endl;
		}
		if (upperMarginMap != 0) {
			cout << std::string(upperMarginMap, '\n');
		}
		afficherMessage();
		io::margesCarte.setValeurs(std::make_pair(leftMarginMap+1,upperMarginMap+1));

		// Tests ...
		std::stringstream launchMessage;
		launchMessage << "Voila les coordonnees carte : (" << margesCarte.getValeurs().first;
		launchMessage << "," << margesCarte.getValeurs().second << ").";
		launchMessage << launchMessage.str();
		launchMessage << launchMessage.str();
		launchMessage << launchMessage.str();
		updateMessage(0,launchMessage.str());
	} 

	void afficherMessage() {
		TERM_MOVE_CURSOR_GOTO(getTerminalHeight()-TERM_MESSAGE_HEIGHT, 1);

		cout << TERM_COLOR_TEXT_BLUE << std::string(getTerminalWidth(), '*') << TERM_COLOR_TEXT_BLANK << endl;
		for (int i = 0; i < TERM_MESSAGE_HEIGHT-2; i++) {
			cout << TERM_COLOR_TEXT_BLUE << '*' << std::string(getTerminalWidth()-2, ' ') << '*' << endl;
		}
		cout << TERM_COLOR_TEXT_BLUE << std::string(getTerminalWidth(), '*') << TERM_COLOR_TEXT_BLANK;

		TERM_MOVE_CURSOR_GOTO(io::margesCarte.getValeurs().first+1,io::margesCarte.getValeurs().second+1);
	}

	void updateMessage(int selectedLine, std::string desiredMessage) {
		// On va au message
		TERM_MOVE_CURSOR_GOTO(getTerminalHeight()-TERM_MESSAGE_HEIGHT + selectedLine + 1, 1);
		
		int stringPosition = 0;
		int maxTextOnLine = getTerminalWidth()-4;

		// dont ask why, it just works™
		int timetemp = TERM_MESSAGE_REFRESH_DELAY;
		int ttemp = TERM_MESSAGE_LINES_AVAILABLE;
		double temp = (double)TERM_MESSAGE_LINES_AVAILABLE;
		
		// Donne le nombre de lignes necessaires pour afficher TOUT le message
		double numberLinesMessage = floor(((double)desiredMessage.length() / (double)maxTextOnLine)+1.0);
		// Donne le nombre d' "ecrans" necessaires pour afficher TOUT le message
		double quotientLinesMessage = numberLinesMessage / temp;
		// eh je sais pas putain
		int remainderLinesMessage = int(floor(numberLinesMessage)) % ttemp;

		// faut faire des substrings
		// et puis
		// reste a afficher le message
		for (int i = 0; i < int(floor(quotientLinesMessage+1.0)); i++) {
			for (int j = 0; j < numberLinesMessage; j++) {
				// On essaie d'afficher le message
				std::string arrgh;
				try {
					arrgh = desiredMessage.substr(stringPosition, maxTextOnLine);
				} catch (...) {
					if (stringPosition <= desiredMessage.length()) {
						arrgh = desiredMessage.substr(stringPosition);
					} else {
						arrgh = "";
					}
				}
				int t = maxTextOnLine - arrgh.length();
				// On affiche le debut du truc
				cout << TERM_COLOR_TEXT_BLUE << '*' << TERM_COLOR_TEXT_BLANK << ' ' << std::string((int)t/2, ' ');
				// On affiche une partie du message
				cout << arrgh;
				// On affiche la fin du truc
				cout << std::string((int)(t/2+t%2), ' ') << ' ' << TERM_COLOR_TEXT_BLUE << '*' << TERM_COLOR_TEXT_BLANK;
				// On remet le curseur au debut de la ligne
				TERM_MOVE_CURSOR_GOTO(getTerminalHeight()-TERM_MESSAGE_HEIGHT+2+j, 1);
				// On incremente la position de depart de la string
				stringPosition += maxTextOnLine;
			}
			cout.flush();
			// On attends pour changer de message, pour que l'utilisateur 
			// puisse lire un peu ce qu'il y a ecrit
			sleep(TERM_MESSAGE_REFRESH_DELAY);
			// On remet le curseur dans le coin du message
			TERM_MOVE_CURSOR_GOTO(getTerminalHeight()-TERM_MESSAGE_HEIGHT + 1, 1);
		}
		TERM_MOVE_CURSOR_GOTO(io::margesCarte.getValeurs().first+1,io::margesCarte.getValeurs().second+1);
	}
}
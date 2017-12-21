#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>

#include "../headers/jeu.h"
#include "../headers/joueur.h"

// g++ -std=c++11 -pedantic boucanier.cpp carte.cpp ennemi.cpp entite.cpp flibustier.cpp jeu.cpp joueur.cpp mainJeu.cpp objetCombat.cpp objetCarte.cpp io.cpp -o ../Dig_or_die

using namespace std;

int main()
{
	srand(time(NULL));
	
	joueur bob("booob", false);
	cout << "joueur :" << bob.toString() << endl; 

	ennemi mechant("Flibustier", false);
	cout << "ennemi:" << mechant.toString() << endl;

	objetCombat fusil("fusil", 100, 50, true);
	cout << "arme : " << fusil.toString();

	cout << bob.getType();


	while (1)
	{
		jeu current(12);

		int nb_joueurs_g = 0;

		cout << "\nDig or Die est un jeu dans lequel vous devez trouver des objets\n";
		cout << "et combattre d'impitoyables pirates afin de vous frayer un chemin jusqu'au trésor.\n";
		cout << "Mais attention! Vous devrez dénicher la précieuse pelle afin d'avoir une chance de le trouver!\n";
		cout << "\n Appuyez sur n'importe quelle touche pour continuer...\n";

		string cont;
		getline(cin, cont);

		cout << "\n";
		cout << "                                Bienvenue\n";
		cout << "                                   dans\n";

		struct timeval half_sec;			//Temps d'attente (0.5s)
		half_sec.tv_sec = 0;
		half_sec.tv_usec = 500000;

		struct timeval fifth_sec;			//Temps d'attente (0.2s)
		fifth_sec.tv_sec = 0;
		fifth_sec.tv_usec = 200000;

		select(0, NULL, NULL, NULL, &half_sec);

	///Affichage titre [beg]
		cerr << "     _____     ___                                  _____     ___\n";
		select(0, NULL, NULL, NULL, &fifth_sec);
		cerr << "    /  __ \\   /__/                                 /  __ \\   /__/\n";
		fifth_sec.tv_usec = 200000;
		select(0, NULL, NULL, NULL, &fifth_sec);
		cerr << "   / /  / /  ___   ______     ______   ______     / /  / /  ___   ______\n";
		fifth_sec.tv_usec = 200000;
		select(0, NULL, NULL, NULL, &fifth_sec);
		cerr << "  / /  / /  /  /  / __  /    / __  /  /  ___/    / /  / /  /  /  / ____/\n";
		fifth_sec.tv_usec = 200000;
		select(0, NULL, NULL, NULL, &fifth_sec);
		cerr << " / /__/ /  /  /  / /_/ /    / /_/ /  /  /       / /__/ /  /  /  / ___/\n";
		fifth_sec.tv_usec = 200000;
		select(0, NULL, NULL, NULL, &fifth_sec);
		cerr << "/______/  /__/  /___  /    /_____/  /__/       /______/  /__/  /_____/\n";
		fifth_sec.tv_usec = 200000;
		select(0, NULL, NULL, NULL, &fifth_sec);
		cerr << "                 __/ /\n";
		fifth_sec.tv_usec = 200000;
		select(0, NULL, NULL, NULL, &fifth_sec);
		cerr << "                /___/\n";
		cerr << "\n";
	///Affichage titre [end]

		cout << "                          1 - Nouvelle partie\n";
		cout << "                          2 - Charger partie\n";
		cout << "                          3 - Quitter\n";

	///Choix action [beg]
		string s_choice = "";				//Stockage input
		bool valid = false;					//Validité de l'input

		while (valid == false)				//Input non valide
		{
			getline(cin, s_choice);			//Input

			while (isInteger(s_choice) == false)	//NaN
			{
				cout << "Valeur incorrecte. Veuillez réessayer: ";
				getline(cin, s_choice);		//Input
			}

			int choice = atoi(s_choice.c_str());	//string -> int

			valid = true;

			switch (choice)					//Option choisie
			{
				case 1:						//Nouvelle partie
				{
					nb_joueurs_g = current.lancerPartie();
					current.sauvegarderPartie();
					break;
				}
				case 2:						//Chargement de partie
				{
					int numLigne;
					cout << "Veuillez choisir une sauvegarde: ";
					cin >> numLigne;
					current.chargerPartie(numLigne);
					break;
				}
				case 3:						//Quitter jeu
				{
					return 0;
				}
				default:					//Mauvaise valeur
				{
					valid = false;
					cout << "Valeur incorrecte. Veuillez réessayer: ";
				}
			}
		}
	///Choix action [end]


	///Partie[beg]
		for (unsigned int i = 0; i < current.getVectJoueur().size(); i++)	//pour chaque joueur
		{
			current.tourJoueur(current.getVectJoueur()[i]);

			if (current.getVectJoueur()[i] -> getVictoire() == true)
			{
				return 1;	//Victoire
			}
		}

		for (unsigned int i = 0; i < current.getVectEnnemi().size(); i++)	//pour chaque ennemi
		{
			current.tourEnnemi(current.getVectEnnemi()[i], nb_joueurs_g);

			if (nb_joueurs_g == 0)	//tous joueurs morts
			{
				return 0;	//Défaite
			}
		}
	///Partie[end]
	}

	return 0;
}
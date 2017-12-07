#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>

#include "../headers/jeu.h"
#include "../headers/joueur.h"
#include "../headers/coords.h"


using namespace std;

int main()
{
	srand(time(NULL));

	while (1)
	{
		jeu current;

		//Pr�sentation des r�gles � mettre ici

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
		bool valid = false;					//Validit� de l'input

		while (valid == false)				//Input non valide
		{
			getline(cin, s_choice);			//Input

			while (isNumber(s_choice) == false)	//NaN
			{
				cout << "Valeur incorrecte. Veuillez r�essayer: ";
				getline(cin, s_choice);		//Input
			}

			int choice = atoi(s_choice.c_str());	//string -> int

			valid = true;

			switch (choice)					//Option choisie
			{
				case 1:						//Nouvelle partie
				{
					current.lancerPartie();
					break;
				}
				case 2:						//Chargement de partie
				{
					//chargerPartie();
					break;
				}
				case 3:						//Quitter jeu
				{
					return 0;
				}
				default:					//Mauvaise valeur
				{
					valid = false;
					cout << "Valeur incorrecte. Veuillez r�essayer: ";
				}
			}
		}
	///Choix action [end]

	///Partie[beg]
		for (unsigned int i = 0; i < current.getVectJoueur().size(); i++)	//pour chaque joueur
		{
			current.tourJoueur(current.getVectJoueur()[i]);

			if (current.getVectJoueur()[i].getVictoire() == true)
			{
				return 1;	//Victoire
			}
		}

		for (unsigned int i = 0; i < current.getVectEnnemi().size(); i++)	//pour chaque ennemi
		{
			current.tourEnnemi(current.getVectEnnemi()[i]);

			if (current.getVectJoueur().size() == 0)	//tous joueurs morts
			{
				return 0;	//D�faite
			}
		}
	///Partie[end]
	}

	return 0;
}
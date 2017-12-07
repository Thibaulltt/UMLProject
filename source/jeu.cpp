#include <map>
#include <math.h>
#include <vector>

#include "../headers/carte.h"
#include "../headers/ennemi.h"
#include "../headers/jeu.h"
#include "../headers/joueur.h"

jeu::jeu()
{
}

void jeu::lancerPartie()
{
	bool validation = false;
	vector<string> vect_string;

	while (validation == false)		//tant que les saisies n'ont pas été validées
	{
		cout << "\n                   -- Création de nouvelle partie --\n";

		//Choix nombre joueurs
		string s_nb_joueurs = "";

		cout << "\nVeuillez choisir le nombre de joueurs (entre 1 et 4): ";

		bool valid = false;

		while (valid == false)
		{
			getline(cin, s_nb_joueurs);

			while (isInteger(s_nb_joueurs) == false)
			{
				cout << "\nValeur incorrecte. Veuillez réessayer: ";
				getline(cin, s_nb_joueurs);
			}

			nb_joueurs = atoi(s_nb_joueurs.c_str());

			if (nb_joueurs < 1 || nb_joueurs > 4)
			{
				cout << "\nValeur incorrecte. Veuillez réessayer: ";
			}
			else
			{
				valid = true;
			}
		}

		//Choix noms joueurs
		for (int i = 0; i < nb_joueurs; i++)
		{
			string nom = "";
			cout << "\nChoisissez un nom pour le joueur " << i + 1 << ": ";
			getline(cin, nom);

			while (nom.size() < 1)
			{
				cout << "\nValeur incorrecte";
				cout << "\nChoisissez un nom pour le joueur " << i + 1 << ": ";
				getline(cin, nom);
			}

			vect_string.push_back(nom);
		}

		//Choix difficulté
		string s_difficulte = "";

		cout << "\nVeuillez choisir la difficulté de la partie (1, 2 ou 3): \n";
		cout << "                          1- Facile\n";
		cout << "                          2- Normal\n";
		cout << "                          3- Difficile\n";

		valid = false;

		while (valid == false)
		{
			getline(cin, s_difficulte);

			while (isInteger(s_difficulte) == false)
			{
				cout << "\nValeur incorrecte. Veuillez réessayer: ";
				getline(cin, s_difficulte);
			}

			difficulte = atoi(s_difficulte.c_str());

			if (difficulte < 1 || difficulte > 3)
			{
				cout << "\nValeur incorrecte. Veuillez réessayer: ";
			}
			else
			{
				valid = true;
			}
		}

		//Confirmation choix
		string s_validation = "";

		cout << "Vous avez choisi une partie à " << vect_string.size();
		
		if (vect_string.size() == 1)
		{
			cout << " joueur";
		}
		else
		{
			cout << " joueurs";
		}

		cout << " (";

		for (unsigned int i = 0; i < vect_string.size(); i++)
		{
			cout << vect_string[i];

			if (i + 1 < vect_string.size())
			{
				if (i + 1 < vect_string.size() - 1)
				{
					cout << ", ";
				}
				else
				{
					cout << " et ";
				}
			}
		}

		cout << ") en difficulté " << difficulte << ".\n";
		cout << "Validez-vous ces choix? (o/n)\n";

		getline(cin, s_validation);

		if (s_validation == "o" || s_validation == "O" || s_validation == "0")
		{
			validation = true;
		}
	}

	int alea = 0;

	//Création des joueurs
	for (unsigned int i = 0; i < vect_string.size(); i++)
	{
		joueur dummy(vect_string[i]);
		vect_joueur.push_back(dummy);
	}

	//Création des ennemis
	vector<ennemi> vect_ennemi;
	ennemi boucanier("Boucanier");
	ennemi flibustier("flib");

	vect_ennemi.push_back(boucanier);
	vect_ennemi.push_back(flibustier);

	for (int i = 0; i < ((2 * difficulte) + (nb_joueurs - 1)); i++)
	{
		alea = rand() % (vect_ennemi.size());
		vect_ennemi.push_back(vect_ennemi[alea]);
	}

	cout << "\n";

	//Création objets + carte
	objet tresor(1);
	objet pelle(2);
	objet mousquet(3);
	objet armure(4);

	carte desert;
	vector<pair<int, int>> vect_case;
	pair<int, int> duo;

	//Vecteur cases (x, y)
	for (int i = 0; i < desert.getTaille(); i++)
	{
		for (int j = 0; j < desert.getTaille(); j++)
		{
			duo = pair<int, int>(i, j);
			vect_case.push_back(duo);
		}
	}

	//Placement trésor
	vect_objet.push_back(tresor);
	vector<objet>::iterator itvo = vect_objet.begin();

	alea = rand() % (vect_case.size() + 1);

	duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);
	desert.setAireJeu(duo, (*itvo).getID());
	vect_objet.erase(itvo);
	vect_case.erase(vect_case.begin() + alea);

	//Placement joueurs
	for (int i = 0; i < nb_joueurs; i++)	//pour chaque joueur
	{
		alea = rand() % (vect_case.size() + 1);

		duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);
		vect_joueur[i].setSlot(duo);
		vect_case.erase(vect_case.begin() + alea);
	}

	//Placement ennemis
	for (unsigned int i = 0; i < vect_ennemi.size(); i++)	//pour chaque ennemi
	{
		alea = rand() % (vect_case.size() + 1);

		duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);
		vect_ennemi[i].setSlot(duo);
	}

	//Placement objets
	for (unsigned int i = 0; i < vect_joueur.size(); i++)	//pour chaque joueur
	{
		vect_objet.push_back(pelle);
		vect_objet.push_back(mousquet);
		vect_objet.push_back(armure);

		while (vect_objet.empty() == false)	//tant qu'un objet doit être placé
		{
			itvo = vect_objet.begin();
			alea = rand() % (vect_case.size() + 1);

			duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);
			desert.setAireJeu(duo, (*itvo).getID());

			vect_objet.erase(itvo);
			vect_case.erase(vect_case.begin() + alea);
		}
	}
	
	//Test affichage map début partie
	for (int i = 0; i < desert.getTaille(); i++)
	{
		for (int j = 0; j < desert.getTaille(); j++)
		{
			pair<int, int> posit (i,j);

			if (desert.getAireJeu()[i][j] != 0)
			{
				cout << desert.getAireJeu()[i][j] << " ";
			}
			else
			{
				bool joueur = false;

				for (unsigned int k = 0; k < vect_joueur.size(); k++)
				{
					if (posit == vect_joueur[k].getSlot().getValeurs())
					{
						joueur = true;
						cout << "j ";
						break;
					}
				}

				if (joueur == false)
				{
					cout << ". ";
				}
			}
		}
		cout << "\n";
	}

	return;
}

void jeu::tourJoueur(joueur player)
{
	player.deplacerJoueur();

	//Ramassage auto
	player.ramasser();

	//Creusage auto
	if (player.getPelle() == true)
	{
		player.creuser();
	}
}

void jeu::tourEnnemi(ennemi enemy)
{
	//Déplacement ennemis
	for (unsigned int i = 0; i < getVectEnnemi().size(); i++)
	{
		getVectEnnemi()[i].deplacerMob();
	}

	//Check joueurs à portée
	for (unsigned int i = 0; i < getVectEnnemi().size(); i++)	//Pour chaque ennemi
	{
		for (unsigned int j = 0; j < getVectEnnemi()[i].getVectPort().size(); j++)	//Pour chaque case accessible
		{
			for (unsigned int k = 0; k < getVectJoueur().size(); k++)	//Pour chaque joueur
			{
				if (getVectEnnemi()[i].getVectPort()[j].getValeurs() == getVectJoueur()[k].getSlot().getValeurs())	//Si joueur à portée
				{				
					//Scores de base:
					//Corsaire: 0 ATT, 0 DEF
					//Pirate: 100 ATT, 100 DEF

					//Règles scores:
					//Mousquet = +150 ATT
					//Armure = +91 DEF, ATT * 2
					
					//Règle combat: pour avoir 100% de chances de tuer l'ennemi,
					//le score d'ATT doit être au moins égal à 2 * la DEF adverse.
					//Sous cette valeur, on a un pourcentage de chances de tuer seulement.
					//Si ATT = DEF: 0% de chances.
					//Si ATT = 1.5 * DEF: 50% de chances.
					//etc...

					//Attaque joueur
					double d_resATTJoueur = (getVectJoueur()[j].getScoreATT() * 100) / getVectEnnemi()[i].getScoreDEF();
					d_resATTJoueur = ceil(d_resATTJoueur - 100); //Chances de tuer sur 100 (arrondies à l'unité supérieure)
					int resATTJoueur = (int)d_resATTJoueur;	//Conversion entier

					int alea = rand() % 100 + 1;	//entre 1 et 100

					if (alea < resATTJoueur)	//Coup fatal
					{
						supprEnnemi(i);
						i--;		//Replacement i pour tenir compte de l'élément supprimé
						goto nextEnnemi;
					}

					//Attaque pirate
					double d_resATTEnnemi = (getVectEnnemi()[i].getScoreATT() * 100) / getVectJoueur()[j].getScoreDEF();
					d_resATTEnnemi = ceil(d_resATTEnnemi - 100); //Chances de tuer sur 100 (arrondies à l'unité supérieure)
					int resATTEnnemi = (int)d_resATTEnnemi;	//Conversion entier

					alea = rand() % 100 + 1;	//entre 1 et 100

					if (alea < resATTEnnemi)	//Coup fatal
					{
						supprJoueur(k);
						k--;		//Replacement k pour tenir compte de l'élément supprimé
					}
				}
			}
		}
	nextEnnemi: continue;
	}
}

vector<joueur> jeu::getVectJoueur()
{
	return vect_joueur;
}

void jeu::supprJoueur(int index)
{
	vect_joueur.erase(index);
}

vector<ennemi> jeu::getVectEnnemi()
{
	return vect_ennemi;
}

jeu::~jeu()
{

}

//Fonctions diverses
bool isInteger(std::string s_input)
{
	for (unsigned int i = 0; i < s_input.size(); i++)
	{
		if (s_input[0] == '-')
		{
			continue;
		}

		if (!isdigit(s_input[i]))
		{
			return false;
		}
	}

	return true;
}
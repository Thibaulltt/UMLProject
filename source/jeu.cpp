#include <map>
#include <math.h>
#include <vector>
#include <unistd.h>

#include "../headers/boucanier.h"
#include "../headers/carte.h"
#include "../headers/ennemi.h"
#include "../headers/flibustier.h"
#include "../headers/jeu.h"
#include "../headers/joueur.h"
#include "../headers/objetCarte.h"
#include "../headers/objetCombat.h"

jeu::jeu(int taille_n)
{
	mappe = carte(taille_n);
}

int jeu::lancerPartie()
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

		while (s_validation != "o" && s_validation != "O" && s_validation != "n" && s_validation != "N")
		{
			cout << "\nValeur incorrecte.Validez-vous ces choix? (o/n)\n";
			getline(cin, s_validation);
		}

		if (s_validation == "o" || s_validation == "O")
		{
			validation = true;
		}
	}

	int alea = 0;

	//Création des joueurs
	for (unsigned int i = 0; i < vect_string.size(); i++)
	{
		joueur dummy(vect_string[i], false);
		vect_joueur.push_back(dummy);
	}

	//Création des ennemis
	boucanier bouc("Boucanier", false);
	flibustier flib("Flibustier", false);

	vect_ennemi.push_back(bouc);
	vect_ennemi.push_back(flib);

	for (int i = 0; i < ((2 * difficulte) + (nb_joueurs - 1)); i++)
	{
		alea = rand() % (vect_ennemi.size());
		vect_ennemi.push_back(vect_ennemi[alea]);
	}

	cout << "\n";

	//Création objets + carte
	objetCarte tres("trésor", true);
	objetCarte pel("pelle", true);
	objetCombat mousq("mousquet", 150, 0, true);
	objetCombat arm("armure", 91, 50, true);

	vector<pair<int, int>> vect_case;
	pair<int, int> duo;

	//Vecteur cases disponibles pour placement objets (x, y)
	for (int i = 0; i < mappe.getTaille(); i++)
	{
		for (int j = 0; j < mappe.getTaille(); j++)
		{
			duo = pair<int, int>(i, j);
			vect_case.push_back(duo);
		}
	}

	//Placement trésor
	vect_objet.push_back(tres);
	vector<objetCarte>::iterator itvo = vect_objet.begin();

	alea = rand() % (vect_case.size() + 1);	//indice aléatoire

	duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);	//case aléatoire
	mappe.setCase(duo, (*itvo));	//insertion dans case
	vect_objet.erase(itvo);	//suppression objet inséré
	vect_case.erase(vect_case.begin() + alea);	//suppression slot (dispo -> indispo)

	//Placement joueurs
	for (int i = 0; i < nb_joueurs; i++)	//pour chaque joueur
	{
		alea = rand() % (vect_case.size() + 1);	//indice aléatoire

		duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);	//case aléatoire
		vect_joueur[i].setCoordonnees(duo);
		mappe.setCase(duo, vect_joueur[i]);
		vect_case.erase(vect_case.begin() + alea);
	}

	//Placement ennemis
	for (unsigned int i = 0; i < vect_ennemi.size(); i++)	//pour chaque ennemi
	{
		alea = rand() % (vect_case.size() + 1);

		duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);
		vect_ennemi[i].setCoordonnees(duo);
		mappe.setCase(duo, vect_ennemi[i]);
	}

	//Placement objets
	for (unsigned int i = 0; i < vect_joueur.size(); i++)	//pour chaque joueur
	{
		vect_objet.push_back(pel);
		vect_objet.push_back(mousq);
		vect_objet.push_back(arm);

		while (vect_objet.empty() == false)	//tant qu'un objet doit être placé
		{
			itvo = vect_objet.begin();
			alea = rand() % (vect_case.size() + 1);	//indice aléatoire

			duo = pair<int, int>(vect_case[alea].first, vect_case[alea].second);	//case aléatoire
			mappe.setCase(duo, (*itvo));	//insertion dans carte

			vect_objet.erase(itvo);	//suppression objet inséré
			vect_case.erase(vect_case.begin() + alea);	//suppression case (dispo -> indispo)
		}
	}
	
	//Test affichage map début partie
	io::afficherCarte(mappe);

	cout.flush();
	sleep(10);

	return nb_joueurs;
}

void jeu::tourJoueur(joueur player)
{
	player.seDeplacer(mappe);

	//Ramassage auto
	//player.ramasser(mappe);
}

void jeu::tourEnnemi(ennemi enemy, int & nb_joueurs_n)
{
	//Déplacement ennemis
	enemy.seDeplacer(mappe);

	//Check joueurs à portée
	for (unsigned int j = 0; j < enemy.getVectPort().size(); j++)	//Pour chaque case accessible
	{
		for (unsigned int k = 0; k < getVectJoueur().size(); k++)	//Pour chaque joueur
		{
			if (getVectJoueur()[k].getVivant() == false)
			{
				continue;
			}

			if (enemy.getVectPort()[j] == getVectJoueur()[k].getCoordonnees())	//Si joueur à portée
			{				
				//Scores de base:
				//Corsaire: 0 ATT, 0 DEF
				//Pirate: 100 ATT, 100 DEF

				//Règles scores:
				//Mousquet = +150 ATT
				//Armure = +91 DEF, ATT +50
					
				//Règle combat: pour avoir 100% de chances de tuer l'ennemi,
				//le score d'ATT doit être au moins égal à 2 * la DEF adverse.
				//Sous cette valeur, on a un pourcentage de chances de tuer seulement.
				//Si ATT = DEF: 0% de chances.
				//Si ATT = 1.5 * DEF: 50% de chances.
				//etc...

				//Attaque joueur
				double d_resATTJoueur = (getVectJoueur()[j].getScoreATT() * 100) / enemy.getScoreDEF();
				d_resATTJoueur = ceil(d_resATTJoueur - 100); //Chances de tuer sur 100 (arrondies à l'unité supérieure)
				int resATTJoueur = (int)d_resATTJoueur;	//Conversion entier

				int alea = rand() % 100 + 1;	//entre 1 et 100

				if (alea < resATTJoueur)	//Coup fatal
				{
					enemy.setVivant(false);	//Ennemi mort
					return;
				}

				//Attaque pirate
				double d_resATTEnnemi = (enemy.getScoreATT() * 100) / getVectJoueur()[j].getScoreDEF();
				d_resATTEnnemi = ceil(d_resATTEnnemi - 100); //Chances de tuer sur 100 (arrondies à l'unité supérieure)
				int resATTEnnemi = (int)d_resATTEnnemi;	//Conversion entier

				alea = rand() % 100 + 1;	//entre 1 et 100

				if (alea < resATTEnnemi)	//Coup fatal
				{
					getVectJoueur()[j].setVivant(false);	//Joueur mort
					nb_joueurs_n--;
				}
			}
		}
	}
}

void jeu::sauvegarderPartie()
{
	ifstream fichierSaveL("../saves.txt", ios::in);

	//ID save
	int nbLignes = 1;
	string ligne;
	while (getline(fichierSaveL, ligne))
	{
		nbLignes++;
	}
	ligne = to_string(nbLignes);
	fichierSaveL.close();

	ofstream fichierSave("../saves.txt", ios::app);


	//Joueurs
	string allPlayers = "";
	for (int i = 0; i < vect_joueur.size(); i++)
	{
		if (vect_joueur.size() >= 2)
		{
			if (i != (vect_joueur.size()) - 1)
			{
				allPlayers = allPlayers + vect_joueur[i].joueurString() + "§";
			}
			else
			{
				allPlayers = allPlayers + vect_joueur[i].joueurString();
			}
		}

		else
		{
			allPlayers = vect_joueur[0].joueurString();
		}
		
	}

	//Ennemis
	string allEnemys = "";
	for (int j = 0; j == vect_ennemi.size(); j++)
	{
		if (j != (vect_ennemi.size()) - 1)
		{
			allEnemys = allEnemys + vect_ennemi[j].ennemiString() + "§";
		}
		else
		{
			allEnemys = allEnemys + vect_ennemi[j].ennemiString();
		}
	}

	//Carte
	string strMap = mappe.carteString();

	//String final
	string finalString = ligne + "|" + strMap + "|" + allPlayers + "|" + allEnemys + "\n"; //Format final : IDsauvegarde | carte | joueur1 § joueur2 | ennemi1 § ennemi2 

	if (fichierSave)
	{
		fichierSave << finalString; //Ecriture
		fichierSave.close();
	}

	else
	{
		cout << "Impossible d'ouvrir le fichier de sauvegarde." << endl;								///////////// COUT A CHANGER //////////////
	}
}

vector<joueur> jeu::getVectJoueur()
{
	return vect_joueur;
}

vector<ennemi> jeu::getVectEnnemi()
{
	return vect_ennemi;
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

jeu::~jeu()
{
}
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../headers/ennemi.h"
#include "../headers/joueur.h"
#include "../headers/objetCarte.h"
#include "../headers/objetCombat.h"
#include "../headers/flibustier.h"

using namespace std;
//!
/*!

*/
class jeu
{
	//! Nombre de joueurs
	int nb_joueurs;
	//! Niveau de difficulté (influe sur le nombre d'ennemis)
	int difficulte;
	//! Vecteur contenant tous les joueurs de la partie
	vector<joueur*> vect_joueur;
	//! Vecteur des objets présents sur la carte. (permet que chaque joueur puisse obtenir un objet de chaque type)
	vector<objetCarte*> vect_objet;
	//! Vecteur contenant les ennemis présents dans la partie
	vector<ennemi*> vect_ennemi;
	//! Carte sur laquelle se déroule la partie
	carte mappe;

public:
	//! Constructeur de jeu
	/*! 
		Permet de construite une partie sur une carte de taille "taille_n"
	*/
	jeu(int taille_n);

	//! Fonction permettant de créer et lancer une partie
	/*!
		A partir de cette fonction, on peut créer une Nouvelle partie, Charger une ancienne partie, ou bien quitter.
		Dans cette fonction seront choisis :
		 - le nombre de joueurs
		 - leur nom
		 - le niveau de diffficulté de la partie

		 Suite à ces choix, la carte est générée et tous les objets necessaires sont créés et placés aléatoirement.

		 \return Un entier correspondant au nombre de joueurs choisi
	*/
	int lancerPartie();

	//! Fonction correspondant aux actions ayant lieues durant le tour d'un joueur.
	void tourJoueur(joueur * player);
	
	//! Fonction retournant le vecteur de joueur
	/*!
		\return Vecteur contenant des joueurs
	*/
	vector<joueur*> getVectJoueur();

	//! Fonction correspondant aux actions ayant lieues durant le tour des ennemis.
	/*!
		Les ennemis se déplacent et attaquent les joueurs
	*/
	void tourEnnemi(ennemi * enemy, int & nb_joueurs_n);

	//! Fonction retournant le vecteur d'ennemis
	/*!
		\return Vecteur contenant des ennemis
	*/
	vector<ennemi*> getVectEnnemi();

	//! Fonction permettant de sauvegarder une partie
	/*!
		Sauvegarde la partie sous forme d'une ligne dans le fichier saves.txt
		Chaque sauvegarde à un identifiant correspondant au nombre de ligne dans le fichier
		La fonction toString est appelée sur la carte, permettant de conserver toutes les infomations necessaires
		\return Un booléen à un true si la sauvegarde est réussie. False sinon.
	*/
	bool sauvegarderPartie();

	//! Fonction permerttant d'afficher la liste des sauvegardes avec la liste des joueurs présents sur chaque sauvegarde
	bool afficherSave();

	//! Fonction permettant de charger une partie
	bool chargerPartie(int numLigne);
	
	//! Destructeur de jeu
	~jeu();
};

//Fonctions diverses

//! Fonction permettant de savoir si l'argument est un entier
/*!
	\return Retourne True si l'argument est un entier
*/
bool isInteger(std::string s_input);

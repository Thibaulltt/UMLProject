#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../headers/ennemi.h"
#include "../headers/joueur.h"
#include "../headers/objetCarte.h"
#include "../headers/objetCombat.h"

using namespace std;
//!
/*!
	Classe permettant de gérer les aspects relatifs au déroulement d'une partie.
	Elle permet notamment de gérer la création de partie (par création d'une nouvelle partie ou chargement d'une partie existante).
	Elle gère également les événements en cours de partie: le combat, les tours des différents acteurs (joueurs et "IA") et la fin de partie (victoire ou défaite).
*/
class jeu
{
	//! Nombre de joueurs.
	int nb_joueurs;
	//! Niveau de difficulté (influe sur le nombre d'ennemis).
	int difficulte;
	//! Vecteur contenant tous les joueurs de la partie.
	vector<joueur*> vect_joueur;
	//! Vecteur des objets présents sur la carte (permet que chaque joueur puisse obtenir un objet de chaque type).
	vector<objetCarte*> vect_objet;
	//! Vecteur contenant les ennemis présents dans la partie.
	vector<ennemi*> vect_ennemi;
	//! Carte sur laquelle se déroule la partie.
	carte mappe;

public:
	//! Constructeur de jeu.
	/*! 
		Permet de construire une partie sur une carte de taille "taille_n".
	*/
	jeu(int taille_n);

	//! Fonction permettant de créer et lancer une partie.
	/*!
		A partir de cette fonction, on peut créer une Nouvelle partie, Charger une ancienne partie, ou bien quitter.
		Dans cette fonction seront choisis :
		 - le nombre de joueurs,
		 - leur nom,
		 - le niveau de difficulté de la partie.

		 Suite à ces choix, la carte est générée et tous les objets nécessaires sont créés et placés aléatoirement.

		 \return Un entier correspondant au nombre de joueurs choisi.
	*/
	int lancerPartie();

	//! Fonction correspondant aux actions ayant lieu durant le tour d'un joueur.
	/*!
		Le joueur se déplace sur une des cases lui étant acccessibles.
		Si un objet s'y trouve, et que le joueur ne le possède pas déjà, il le ramasse.
		Si le joueur possède la pelle, il creuse automatiquement à la recherche du trésor.
		Si le joueur déterre le trésor, il gagne la partie.
	*/
	void tourJoueur(joueur * player);

	//! Fonction retournant le vecteur de joueur.
	/*!
		\return Vecteur contenant des joueurs.
	*/
	vector<joueur*> getVectJoueur();

	//! Fonction correspondant aux actions ayant lieu durant le tour des ennemis.
	/*!
		Les ennemis se déplacent selon leur schéma de déplacement.
		S'ils se retrouvent à portée d'un joueur, le joueur effectue une attaque pré-emptive (priorité au joueur).
		S'ils survivent à l'attaque du joueur, ils attaquent à leur tour.
	*/
	void tourEnnemi(ennemi * enemy, int & nb_joueurs_n);

	//! Fonction retournant le vecteur d'ennemis.
	/*!
		\return Vecteur contenant des ennemis.
	*/
	vector<ennemi*> getVectEnnemi();

	//! Fonction permettant de sauvegarder une partie.
	/*!
		Sauvegarde la partie sous forme d'une ligne dans le fichier saves.txt.
		Chaque sauvegarde a un identifiant correspondant au nombre de lignes dans le fichier.
		La fonction toString est appelée sur la carte, permettant de conserver toutes les infomations nécessaires.
		\return Un booléen à true si la sauvegarde est réussie. False sinon.
	*/
	bool sauvegarderPartie();

	//! Fonction permettant d'afficher la liste des sauvegardes avec la liste des joueurs présents sur chaque sauvegarde.
	/*!
		Affiche la liste des sauvegardes en lisant chaque ligne du fichier de sauvegarde et en comptant les joueurs présents + en stockant leur nom.
		\return Un booléen à true si la lecture a réussi, false sinon.
	*/
	bool afficherSave();

	//! Fonction permettant de charger une partie.
	bool chargerPartie(int numLigne);
	
	//! Destructeur de jeu.
	~jeu();
};

//Fonctions diverses

//! Fonction permettant de savoir si l'argument représente un entier.
/*!
	\return Retourne True si l'argument représente un entier.
*/
bool isInteger(std::string s_input);

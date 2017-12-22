#pragma once

#include <string>
#include <vector>

#include "../headers/objetCarte.h"

using namespace std;


//!
/*!
Classe représentant la carte où se déroule le jeu.
Elle est représentée par un vecteur de vecteur de vecteur d'objetCarte.
On peut représenter ça par un tableau (formé par les deux premiers vecteurs, de taille n) dont chaque case est vecteur.
Ce dernier vecteur contient tout ce qu'il se trouve sur une case simultanément. Ceci peut-être un joueur, un ennemi, une pelle... (n'importe quel objet tiré d'une classe fille d'objetCarte)
On stock en fait des pointeurs vers un objetCarte afin de gérer les problèmes d' "object slicing" liées au C++, afin de pouvoir utiliser les fonction overridées des classes filles.
*/
class carte
{
	//! Taille de la carte
	unsigned int taille;

	//! Tableau où chaque case est un vecteur d'objerCarte.
	vector<vector<vector<objetCarte*>>> aireJeu;

public:
	//! Constructeur vide de carte
	carte();

	//! Constructeur permettant de créer une carte de taille "taille_n"
	/*!
	 Pour chaque case, on push un vecteur d'objetCarte.
	*/
	carte(int taille_n);

	//! Fonction renvoyant la taille de la carte
	/*!
		\return Un entier
	*/
	int getTaille();

	//! Fonction permettant d'insérer un objet dans une case de l'attribut aireJeu
	/*!
		La paire d'int représente les coordonnées auxquelles on veut insérer l'objet.
		ObjC est un pointeur vers l'objet qu'on veut insérer
	*/
	void setCase(pair<int, int> slot, objetCarte * objC);

	//! Fonction permettant d'obtenir un vecteur d'objetCarte
	/*!
		La paire d'int représente les coordonnées de la case dont on veut récupérer le vecteur d'objet
		\return Un vecteur de pointeurs d'objetCarte
	*/
	vector<objetCarte*> getCase(pair<int,int> slot);
	
	//! Permet de convertir les caractéristiques d'une carte en string. 
	/*!
	Fonction utilisée dans la sauvegarde.
	\return Une string formatée ainsi :  0 pour une case vide. | le séparateur de case. $ le séparateur des éléments se trouvant sur une case
	*/
	string toString();

	//! Permet de renvoyer le vecteur de vecteur de vecteur d'objetCarte
	/*!
		\return Un vecteur de vecteur de vecteur d'objetCarte.
	*/
	vector<vector<vector<objetCarte*>>> getAireJeu();

	//! Supprime un objet dans le vecteur d'objetCarte
	/*!
	Utiliser lors du ramassage d'un objet (lorsque un objet est dans l'équipement d'un joueur, on enléve cet objet de la carte)
	x et y sont les coordonnées de la case où se trouve l'objet
	position est la position de l'objet dans le vecteur d'objet Carte
	*/
	void delObjet(int x, int y, int position);
	
	//! Destructeur de carte
	~carte();
};
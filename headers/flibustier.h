﻿#pragma once

#include <math.h>
#include "../headers/carte.h"
#include "../headers/ennemi.h"


//!
/*!
Cette classe héritant d'ennemi.
Elle représente un personnage étant controlé par l'ordinateur.
Elle ne possède pas d'attributs supplémentaire par rapport à sa classe mère.
Elle sera initialisée avec les attributs décrits dans le sujet : 
	- possibilité d'attaquer les joueurs sur la même case que lui, ou une case autour (porteeATT = 1),
	- possibilité de se déplacer de 1 case autour de lui en 1 tour (porteeDEP = 1).
*/
class flibustier : public ennemi
{
	public:
		//! Constructeur permettant de créer un boucanier.
		/*!
		Le constructeur de la classe mère (ennemi) est appelé.
		Initilalisé de la même façon qu'un ennemi mais avec ces particularités :
			- porteeATT = 1.
		*/
		flibustier(string nom_n, bool ramassable_n);
		
		//! Destructeur de flibustier.
		~flibustier();

		//Virtual & override

		//! Fonction definissant une zone dans laquelle une entité peut attaquer.
		/*!
		On prend la stat de portée d'attaque, et on étend entre 2 points:
		- le point supérieur gauche (i-porteeATT, j-porteeATT) = a,
		- le point inférieur droit (i+porteeATT, j+porteeATT) = b.
		Ensuite, on fait une boucle ij qui part de a et qui va jusqu'à b en remplissant vectPort avec toutes les cases rencontrées.
		On crée donc un carré autour de l'entité, définissant sa zone d'attaque.
		Les cases en dehors de la carte ne sont pas incluses.
		*/
		void setVectPort(pair<int, int> slot_n, int tailleMap) override;

		void seDeplacer(carte mappe) override;

		//* Fonction permettant d'attaquer un adversaire.
		/*!
			On calcule à partir du scoreATT du flibustier et de la defense de l'adversaire, les chances /100 de tuer cet adversaire.
			On fait un tirage aléatoire entre 1 et 100, si ce tirage est inférieur aux calculs précédents, l'adversaire est alors tué.
			\return Booléen à true si l'adversaire a été tué.
		*/
		bool attaquer(entite * adver) override;
		
		//! Permet de convertir les caractéristiques d'un flibustier en string.
		/*!
		Fonction utilisée dans la sauvegarde.
		On rappelle le code de la classe mère, qui renvoie :  nom .
		\return Une string formatée ainsi :  F / nom.
		*/
		string toString() override;
};
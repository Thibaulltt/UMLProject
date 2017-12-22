#pragma once

#include <math.h>
#include "../headers/carte.h"
#include "../headers/ennemi.h"


//!
/*!
Cette classe héritant d'ennemi. 
Elle représente un personnage étant controlé par l'ordinateur.
Elle ne possède pas d'attributs supplémentaire par rapport à sa clase mère.
Elle sera initialisé avec les attributs décrits dans le sujet : 
	- possibilité d'attaquer  les joueurs sur la même case que lui, ou une case autour (porteeATT = 1)
	- possibilité de se déplacer de 1 case1 autour de lui en 1 tour (porteeDEP = 1)
*/
class flibustier : public ennemi
{
	public:
		//! Constructeur permettant de créer un boucanier.
		/*!
		Le constructeur de la classe mère (ennemi) est appelé.
		Initilalisé de la même façon qu'un ennemi mais avec ces particularités :
			- porteeATT = 1
		*/
		flibustier(string nom_n, bool ramassable_n);
		
		//! Destructeur de flibustier
		~flibustier();

		//Virtual & override

		//! Fonction definissant une zone dans laquelle une entité peut attaquer
		/*!
		On prend la stat de portée d'attaque, et on étend entre 2 points:
		- le point supérieur gauche (i-porteeATT, j-porteeATT) = a
		- le point inférieur droit (i+porteeATT, j+porteeATT) = b
		Ensuite, on fait une boucle ij qui part de a et qui va jusqu'à b
		en remplissant vectPort avec toutes les cases rencontrées.
		On créé donc un carré autour de l'entité, définissant sa zone d'attaque.
		Les cases en dehors de la carte ne sont pas inclus.
		*/
		void setVectPort(pair<int, int> slot_n, int tailleMap) override;

		void seDeplacer(carte mappe) override;

		bool attaquer(entite * adver) override;	// Attaque de l'ennemi
		
		//! Permet de convertir les caractéristiques d'un flibustier en string. 
		/*!
		Fonction utilisée dans la sauvegarde.
		On rappelle le code de la classe mère, qui renvoie :  nom 
		\return Une string formatée ainsi :  F / nom
		*/
		string toString() override;
};
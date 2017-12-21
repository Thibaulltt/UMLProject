#pragma once

#include "../headers/carte.h"
#include "../headers/ennemi.h"

//!
/*!
Cette classe héritant d'ennemi. 
Elle représente un personnage étant controlé par l'ordinateur.
Elle ne possède pas d'attributs supplémentaire par rapport à sa clase mère.
Elle sera initialisé avec les attributs décrits dans le sujet : 
	- possibilité d'attaquer seulement les joueurs sur la même case que lui (porteeATT = 0)
	- possibilité de se déplacer de 2 cases autour de lui en 1 tour (porteeDEP = 0)
*/
class boucanier : public ennemi
{
	public:
		//! Constructeur permettant de créer un boucanier.
		/*!
		Le constructeur de la classe mère (ennemi) est appelé.
		Initilalisé de la même façon qu'un ennemi mais avec ces particularités :
			- porteeDEP = 2
		*/
		boucanier(string nom_n, bool ramassable_n);
		
		//! Destructeur de bouvanier
		~boucanier();

		//Virtual & override
		
		void seDeplacer(carte mappe) override;

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
		

		void attaquer() override;	// Attaque de l'ennemi
		
		//! Permet de convertir les caractéristiques d'un boucanier en string. 
		/*!
		Fonction utilisée dans la sauvegarde.
		On rappelle le code de la classe mère, qui renvoie :  nom 
		\return Une string formatée ainsi :  B / nom
		*/
		string toString() override;
};
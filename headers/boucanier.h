#pragma once

#include "../headers/carte.h"
#include "../headers/ennemi.h"

//!
/*!
Cette classe hérite d'ennemi.
Elle représente un personnage étant contrôlé par l'ordinateur.
Elle ne possède pas d'attributs supplémentaire par rapport à sa classe mère.
Elle sera initialisée avec les attributs décrits dans le sujet : 
	- possibilité d'attaquer seulement les joueurs sur la même case que lui (porteeATT = 0),
	- possibilité de se déplacer de 2 cases autour de lui en 1 tour (porteeDEP = 2).
*/
class boucanier : public ennemi
{
	public:
		//! Constructeur permettant de créer un boucanier.
		/*!
		Le constructeur de la classe mère (ennemi) est appelé.
		Initialisé de la même façon qu'un ennemi mais avec ces particularités :
			- porteeDEP = 2.
		*/
		boucanier(string nom_n, bool ramassable_n);
		
		//! Destructeur de boucanier.
		~boucanier();

		//Virtual & override

		void seDeplacer(carte mappe) override;

		//! Fonction définissant une zone dans laquelle une entité peut attaquer
		/*!
		On prend la stat de portée d'attaque, et on étend entre 2 points:
		- le point supérieur gauche (i-porteeATT, j-porteeATT) = a,
		- le point inférieur droit (i+porteeATT, j+porteeATT) = b.
		Ensuite, on fait une boucle ij qui part de a et qui va jusqu'à b en remplissant vectPort avec toutes les cases rencontrées.
		On crée donc un carré autour de l'entité, définissant sa zone d'attaque.
		Les cases en dehors de la carte ne sont pas incluses.
		*/
		void setVectPort(pair<int, int> slot_n, int tailleMap) override;
			
		//* Fonction permettant d'attaquer un adversaire
		/*!
			On calcule à partir du scoreATT du boucanier et de la defense de l'adversaire, les chances /100 de tuer cet adversaire.
			On fait un tirage aléatoire entre 1 et 100, si ce tirage est inférieur aux calculs précédents, l'adversaire est alors tué.
			\return Booléen à true si l'adversaire a été tué.
		*/
		bool attaquer(entite * adver) override;	
		
		//! Permet de convertir les caractéristiques d'un boucanier en string. 
		/*!
		Fonction utilisée dans la sauvegarde.
		On rappelle le code de la classe mère, qui renvoie :  nom.
		\return Une string formatée ainsi :  B / nom.
		*/
		string toString() override;
};
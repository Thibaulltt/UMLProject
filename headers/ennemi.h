#pragma once

#include "../headers/carte.h"
#include "../headers/entite.h"

//!
/*!
Cette classe hérite directement de la classe entité. 
Elle représente un personnage étant controlé par l'ordinateur.
Elle ne possède pas d'attributs supplémentaire par rapport à sa clase mère.
De cette classe vont hériter les deux types d'ennemis présents dans le jeu : le flibustier et le boucannier.
*/

class ennemi : public entite //Classe ennemi heritant d'entite
{
	public:
	//! Constructeur permettant de créer un ennemi.
	/*!
	Le constructeur de la classe mère (entite) est appelé.
	Un ennemi est initialisé avec un scoreATT et scoreDEF à 100 afin de pouvoir tuer un joueur sans équipement.
	*/
		ennemi(string nom_n, bool ramassable_n);

	//Virtual & override

	//! Permet de convertir les caractéristiques d'un ennemi en string. 
	/*!
	Fonction utilisée dans la sauvegarde.
	On rappelle le code de la classe mère, qui renvoie :  nom 
	\return Une string formatée ainsi :  nom
	*/
		virtual string toString() override;

		virtual void seDeplacer(carte mappe) override;	// Deplacement de l'ennemi

		//! Fonction definissant une zone dans laquelle une entité peut attaquer
		virtual void setVectPort(pair<int, int>, int) override;		
		
		//* Fonction permettant d'attaquer un ennemi
		/*!
			\return Booléen à true si l'adversaire a été tuée.
		*/
		bool attaquer(entite adver) override;
		
		//! Destructeur d'ennemi
		virtual ~ennemi();
};
#pragma once

#include "../headers/objetCarte.h"

//!
/*!
Classe héritant d’objetCombat et regroupant les objets de combat. 
On appelle objet de combat les objets ayant une influence sur les stats scoreATT et scoreDEF.
On a donc comme attributs supplémentaires :
	- attack : entier à ajouter aux stats du joueur augmentant son scoreATT (nombre entier)
	- defense : entier à ajouter aux stats du joueur augmentant son scoreDEF (nombre entier).
Les objets Armure et Mousquet seront des instances de cette classe.
*/
class objetCombat : public objetCarte
{
	protected:
		//! Points d'attaque donnés par l'objet
		int attack;
		//! Points de défense donnés par l'objet
		int defense;

	public:
		//! Constructeur permettant de créer un objet de combat
		/*!
			Le constructeur de la classe mère est appelé.
			L'objet sera initialisé avec les valeurs supplémentaires suivantes :
			- attack = attack_n
			- defense = defense_n
		*/
		objetCombat(string nom_n, int att_n, int def_n, bool ramassable_n);
		
		//! Fonction retournant l'attaque donnée par un objetCombat
		int getAttack() override;

		//! Fonction retournant la défense donnée par un objetCombat
		int getDefense() override;

		//! Permet de convertir les caractéristiques d'un objet en string. 
		/*!
		Fonction utilisée dans la sauvegarde.
		On rappelle le code de la classe mère, qui renvoie :  nom 
		\return Une string formatée ainsi :  C / nom / attack : defense
		*/
		string toString() override;
		
		//! Destructeur d'objetCombat
		~objetCombat();
};

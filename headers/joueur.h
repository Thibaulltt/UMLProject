#pragma once

#include <string>
#include <vector>

#include "../headers/carte.h"
#include "../headers/entite.h"
#include "../headers/io.h"
#include "../headers/objetCarte.h"

using namespace std;

//!
/*!
Cette classe hérite directement de la classe entité. 
Elle représente un personnage étant joué par un joueur.
En plus des propriétés de la classe “Entite”, celle-ci possède :
- pellePoss : indique si le joueur a trouvé la pelle, et donc, si il peut creuser. (booléen)
- victoire : indique si un joueur a gagné la partie ou pas. Par défaut à false et passe à true si le joueur trouve le trésor. (booléen)
- equipement :  vecteur contenant les objets trouvés par le joueur.
*/
class joueur : public entite
{
	//! Booléen indiquant si le joueur possède une pelle
	bool pellePoss;
	//! Booléen indiquant si le joueur a gagné ou pas
	bool victoire;
	//! Vecteur d'objetCarte. Ici, servira a stocker les objets trouvés par le joueur.
	vector<objetCarte *> equipement;

public:
	//! Constructeur permettant de créer un joueur.
	/*!
	Le constructeur de la classe mère (entite) est appelé.
	Un joueur est initalisé comme la classe entite.
	*/
	joueur(string nom_n, bool ramassable_n);
	
	//! Fonction retournant si un joueur possède une pelle ou pas.
	/*!
	Utilisée dans la fonction ramasser() pour savoir si il est possible de ramasser le trèsor, ou pas.
	\return Un bool. True si le joueur possède une pelle, false sinon.
	*/
	bool getPellePoss();
	
	//! Fonction retournant si un joueur gagne la partie ou pas.
	/*!
	Actuellement, la seule condition de victoire est de trouver le trésor, mais on pourrait imaginer des évolutions dans le futur (tuer tous les ennemis, trouver une sortie, etc...)
	\return Un bool. True si le joueur a gagné, false sinon.
	*/
	bool getVictoire();
	
	//! Destructeur de joueur
	~joueur();

	//! Fonction permettant de savoir si le joueur possède un objet nomObjet
	/*!
		Utilisée dans ramasser() pour qu'un joueur ne ramasse pas un objet qu'il possède déjà.
		Parcours du vecteur d'equipement du joueur, si on trouve un objet qui a le même nom que l'argument, retourne true. False Sinon
		\return Un booléen. True si l'objet passé en argument a été trouvé dans l'équipement du joueur. False sinon.
	*/
	bool checkPoss(string nomObjet);

	//! Fonction permettant à un joueur de ramasser des objets sur la carte
	/*!
		On récupère les coordonées du joueur.
		On vérifie si la case sur laquelle il se trouve contient autre chose que lui même.
		Si oui, on vérifie qu'il s'agit d'objet ramassables.
		Si oui, on vérifie qu'il ne posséde pas l'objet dans son équipement, s'il ne l'a pas, on le rajoute dans son vecteur d'équipement et on supprime l'objet de la case.
		Si cet objet était un objetCombat, on met à jour les stats scoreDED et scoreATT du joueur.
		Si le joueur se trouve sur le trésor, on vérifie d'abord qu'il posséde un pelle avant de ramasser.
	*/
	void ramasser(carte mappe);

	void equiper(objetCarte obj_o);

	//Virtual & override
	void seDeplacer(carte mappe) override;
	void attaquer() override;

	//! Permet de convertir les caractéristiques d'une entité en string. 
	/*!
	Fonction utilisée dans la sauvegarde.
	On rappelle le code de la classe mère, qui renvoie :  nom / porteeATT : scoreATT : scoreDEF
	\return Une string formatée ainsi : nom / porteeDEP : scoreATT : scoreDEF / objet1 § objet2 § objet3
	*/
	string toString() override;
};

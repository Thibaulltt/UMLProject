#pragma once

#include <string>
#include <vector>

#include "../headers/carte.h"
#include "../headers/objetCarte.h"

//!
/*!
La classe “Entite” est une super-classe abstraite, heritant d'objetCarte (une entite est un élement se trouvant sur la carte) regroupant toutes les entités présentes dans notre jeu.
Elle sera la classe mère des classes "joueur" et ennemi".
Toutes celles-ci ont des propriétés communes :
- etatVie : une unité est soit envie, soit morte (booléen).
- scoreATT, porteeATT, scoreDef : propriétés donnant les stats d’une entité. Celles-ci seront affectées par le type d’unité, ou bien les objets pouvant être ramassés au cours de la partie (nombre entier).
- porteeDep : donne la portée de déplacement permise en un tour. Par exemple, une portée de 2 permet de se déplacer sur 2 cases autour de l’entité.
*/


class entite : public objetCarte
{
	protected :
		//! Portee de deplacement
		int porteeDEP;
		//! Points d'attaque (affecté par type d'unité et objets ramassés)
		int scoreATT;
		//! Portée d'attaque
		int porteeATT;
		//! Points de defense (affecté par type d'unité et objets ramassés)
		int scoreDEF;
		//! Etat de vie de l'unité
		bool vivant;

		vector<pair<int,int>> vectPort;

	public :
		//! Constructeur permettant de créer une entité.
		/*!
		Le constructeur de la classe mère (objetCarte) est appelé.
		Une entité est initalisée ainsi :
		- portée de déplacement de 1
		- scoreATT, porteeATT, scoreDEF à 0
		- vivante = true
		*/
		entite(string nom_n, bool ramassable_n);

		vector<pair<int, int>> getVectPort();	//Retourne le vecteur de portée

		//! Fonction retournant le scoreATT de l'entité
		/*!
		Utilisée lors du combat.
		\return Un entier donnant le scoreATT
		*/
		int getScoreATT();

		//! Fonction retournant le scoreDEF de l'entité
		/*!
		Utilisée lors du combat.
		\return Un entier donnant le scoreDEF
		*/
		int getScoreDEF();	

		//! Fonction retournant l'état de vie d'un entité
		/*!
			\return Un booléen, true si l'entité est en vie, false sinon.
		*/
		bool getVivant();

		//! Fonction permettant de faire vivre ou mourir une entité
		/*!
		Utilisé en combat lors de la mort d'une entité par exemple
		*/
		void setVivant(bool vivant_n);		
					

		//Virtual & override
		virtual void seDeplacer(carte mappe);
		virtual void setVectPort(pair<int, int>, int);		// Set vector portee
		virtual void attaquer();	// Attaque de l'ennemi
		
		//! Permet de convertir les caractéristiques d'une entité en string. 
		/*!
		Fonction utilisée dans la sauvegarde.
		On rappelle le code de la classe mère, qui renvoie le nom.
		\return Une string formatée ainsi : nom / porteeATT : scoreATT : scoreDEF
		*/
		virtual string toString() override;
		
		//!Destructeur d'entité
		virtual ~entite();
};

/*Refonte fonctionnement portée [POUR DOC, PAS SUPPR PLZ]
Désormais, on prend la stat de portée d'attaque, et on entre 2 points:
- le point supérieur gauche (i-porteeATT, j-porteeATT) = a
- le point inférieur droit (i+porteeATT, j+porteeATT) = b
Ensuite, on fait une boucle ij qui part de a et qui va jusqu'à b
en remplissant vectPort avec toutes les cases rencontrées.
Résumé: on crée un carré autour de l'entité et on remplit.
Avantages: moins sale qu'avant; permet d'avoir toutes les cases
(l'ancienne méthode ne rajoutait que les lignes droites et diagonales).
Inconvénient: oblige à réécrire cette fonction pour chaque entité qui a
un pattern différent, mais c'était pareil avant.
*/

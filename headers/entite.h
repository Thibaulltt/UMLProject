#pragma once

#include <string>
#include <vector>

#include "../headers/carte.h"
#include "../headers/objetCarte.h"

//!
/*!
La classe �Entite� est une super-classe abstraite, heritant d'objetCarte (une entite est un �lement se trouvant sur la carte) regroupant toutes les entit�s pr�sentes dans notre jeu.
Elle sera la classe m�re des classes "joueur" et ennemi".
Toutes celles-ci ont des propri�t�s communes :
- etatVie : une unit� est soit envie, soit morte (bool�en).
- scoreATT, porteeATT, scoreDef : propri�t�s donnant les stats d�une entit�. Celles-ci seront affect�es par le type d�unit�, ou bien les objets pouvant �tre ramass�s au cours de la partie (nombre entier).
- porteeDep : donne la port�e de d�placement permise en un tour. Par exemple, une port�e de 2 permet de se d�placer sur 2 cases autour de l�entit�.
*/


class entite : public objetCarte
{
	protected :
		//! Portee de deplacement
		int porteeDEP;
		//! Points d'attaque (affect� par type d'unit� et objets ramass�s)
		int scoreATT;
		//! Port�e d'attaque
		int porteeATT;
		//! Points de defense (affect� par type d'unit� et objets ramass�s)
		int scoreDEF;
		//! Etat de vie de l'unit�
		bool vivant;

		vector<pair<int,int>> vectPort;

	public :
		//! Constructeur permettant de cr�er une entit�.
		/*!
		Le constructeur de la classe m�re (objetCarte) est appel�.
		Une entit� est initalis�e ainsi :
		- port�e de d�placement de 1
		- scoreATT, porteeATT, scoreDEF � 0
		- vivante = true
		*/
		entite(string nom_n, bool ramassable_n);

		vector<pair<int, int>> getVectPort();	//Retourne le vecteur de port�e

		//! Fonction retournant le scoreATT de l'entit�
		/*!
		Utilis�e lors du combat.
		\return Un entier donnant le scoreATT
		*/
		int getScoreATT();

		//! Fonction retournant le scoreDEF de l'entit�
		/*!
		Utilis�e lors du combat.
		\return Un entier donnant le scoreDEF
		*/
		int getScoreDEF();	

		//! Fonction retournant l'�tat de vie d'un entit�
		/*!
			\return Un bool�en, true si l'entit� est en vie, false sinon.
		*/
		bool getVivant();

		//! Fonction permettant de faire vivre ou mourir une entit�
		/*!
		Utilis� en combat lors de la mort d'une entit� par exemple
		*/
		void setVivant(bool vivant_n);		
					

		//Virtual & override
		virtual void seDeplacer(carte mappe);
		virtual void setVectPort(pair<int, int>, int);		// Set vector portee
		virtual void attaquer();	// Attaque de l'ennemi
		
		//! Permet de convertir les caract�ristiques d'une entit� en string. 
		/*!
		Fonction utilis�e dans la sauvegarde.
		On rappelle le code de la classe m�re, qui renvoie le nom.
		\return Une string format�e ainsi : nom / porteeATT : scoreATT : scoreDEF
		*/
		virtual string toString() override;
		
		//!Destructeur d'entit�
		virtual ~entite();
};

/*Refonte fonctionnement port�e [POUR DOC, PAS SUPPR PLZ]
D�sormais, on prend la stat de port�e d'attaque, et on entre 2 points:
- le point sup�rieur gauche (i-porteeATT, j-porteeATT) = a
- le point inf�rieur droit (i+porteeATT, j+porteeATT) = b
Ensuite, on fait une boucle ij qui part de a et qui va jusqu'� b
en remplissant vectPort avec toutes les cases rencontr�es.
R�sum�: on cr�e un carr� autour de l'entit� et on remplit.
Avantages: moins sale qu'avant; permet d'avoir toutes les cases
(l'ancienne m�thode ne rajoutait que les lignes droites et diagonales).
Inconv�nient: oblige � r��crire cette fonction pour chaque entit� qui a
un pattern diff�rent, mais c'�tait pareil avant.
*/
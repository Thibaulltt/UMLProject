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
- etatVie : une unité est soit en vie, soit morte (booléen),
- scoreATT, porteeATT, scoreDef : propriétés donnant les stats d’une entité. Celles-ci seront affectées par le type d’unité, ou bien les objets pouvant être ramassés au cours de la partie (nombre entier),
- porteeDep : donne la portée de déplacement permise en un tour. Par exemple, une portée de 2 permet de se déplacer sur 2 cases autour de l’entité.
*/


class entite : public objetCarte
{
	protected :
		//! Portee de déplacement.
		int porteeDEP;
		//! Points d'attaque (affecté par type d'unité et objets ramassés).
		int scoreATT;
		//! Portée d'attaque
		int porteeATT;
		//! Points de défense (affecté par type d'unité et objets ramassés).
		int scoreDEF;
		//! Etat de vie de l'unité.
		bool vivant;
		//! Vecteur donnant la zone dans laquelle une entité a la possibilité d'attaquer.
		vector<pair<int,int>> vectPort;

	public :

		//! Constructeur permettant de créer une entité.
		/*!
		Le constructeur de la classe mère (objetCarte) est appelé.
		Une entité est initalisée ainsi :
		- portée de déplacement de 1,
		- scoreATT, porteeATT, scoreDEF à 0,
		- vivante = true.
		*/
		entite(string nom_n, bool ramassable_n);

		//! Retourne le vecteur de portée.
		vector<pair<int, int>> getVectPort();

		//! Fonction retournant le scoreATT de l'entité.
		/*!
		Utilisée lors du combat.
		\return Un entier donnant le scoreATT.
		*/
		int getScoreATT();

		//! Fonction retournant le scoreDEF de l'entité.
		/*!
		Utilisée lors du combat.
		\return Un entier donnant le scoreDEF.
		*/
		int getScoreDEF();	

		//! Fonction retournant l'état de vie d'un entité.
		/*!
			\return Un booléen, true si l'entité est en vie, false sinon.
		*/
		bool getVivant() override;

		//! Fonction permettant de faire vivre ou mourir une entité.
		/*!
			Utilisé en combat lors de la mort d'une entité par exemple.
		*/
		void setVivant(bool vivant_n);		
					


		//Virtual & override
		
		virtual void seDeplacer(carte mappe);
		
		//! Fonction définissant une zone dans laquelle une entité peut attaquer.
		/*!
			Cette fonction sera définie précisement dans les classes filles, permettant de gérer les différents cas possible d'attaque. (Par exemple, si un ennemi peut seulement attaquer en diagonale).
		*/
		virtual void setVectPort(pair<int, int>, int);

		//! Fonction permettant d'attaquer un adversaire.
		virtual bool attaquer(entite * adver);	

		//! Permet de convertir les caractéristiques d'une entité en string.
		/*!
		Fonction utilisée dans la sauvegarde.
		On rappelle le code de la classe mère, qui renvoie le nom.
		\return Une string formatée ainsi : nom / porteeATT : scoreATT : scoreDEF.
		*/
		virtual string toString() override;
		
		//!Destructeur d'entité.
		virtual ~entite();
};
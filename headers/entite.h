#pragma once

#include <string>
#include <vector>

#include "objetCarte.h"

class entite : public objetCarte
{
	protected :
		int porteeDEP;		// Portee de deplacement
		int scoreATT;		// Points d'attaque
		int porteeATT;		// Portee d'attaque
		int scoreDEF;		// Points de defense
		bool vivant;		// Est il/elle vivant(e) ?
		vector<pair<int,int>> vectPort;

	public :
		~entite();				// Destruction
		string getNom();			// Retourne le nom de l'unite
		int getScoreATT();			// Retourne le nb de points d'attaque
		int getScoreDEF();			// Retourne le nb de points de defense
		void setVivant(bool vivant_n);		// IT'S ALIVE !!!
		bool getVivant();			// It's alive ???

		//Virtual & override
		virtual vector<pair<int, int>> getVectPort();
		virtual void seDeplacer();
		virtual void setVectPort(pair<int, int>, int);		// Set vector portee
		virtual void attaquer();	// Attaque de l'ennemi
		entite(string nom_n) override;
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
#pragma once

#include <string>
#include <vector>

#include "../headers/carte.h"
#include "../headers/objetCarte.h"

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
		entite(string nom_n, bool ramassable_n);
		string getNom();			// Retourne le nom de l'unite
		vector<pair<int, int>> getVectPort();	//Retourne le vecteur de port�e
		int getScoreATT();			// Retourne le nb de points d'attaque
		int getScoreDEF();			// Retourne le nb de points de defense
		void setVivant(bool vivant_n);		// IT'S ALIVE !!!
		bool getVivant();			// It's alive ???
		

		//Virtual & override
		virtual void seDeplacer(carte mappe);
		virtual void setVectPort(pair<int, int>, int);		// Set vector portee
		virtual void attaquer();	// Attaque de l'ennemi
		virtual string toString() override;
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
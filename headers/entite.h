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
		vector<pair<int, int>> getVectPort();	//Retourne le vecteur de portée
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
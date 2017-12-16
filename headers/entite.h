#pragma once

#include <vector>
#include <string>

#include "objetCarte.h"

class entite : public objetCarte
{
	protected:
		string nom;		// Nom de l'entite
		int porteeDEP;		// Portee de deplacement
		int scoreATT;		// Points d'attaque
		int scoreDEF;		// Points de defense
		bool vivant;		// Est il/elle vivant(e) ?
		int porteeATT;		// Portee d'attaque
		vector<pair<int,int>> vectPort;

	public :
		entite(string nom_n);			// Construction de l'entite
		~entite();				// Destruction
		string getNom();			// Retourne le nom de l'unite
		int getScoreATT();			// Retourne le nb de points d'attaque
		int getScoreDEF();			// Retourne le nb de points de defense
		void setVivant(bool vivant_n);		// IT'S ALIVE !!!
		bool getVivant();			// It's alive ???
		vector<pair<int,int>> getVectPort();		// Get vector portee
		void setVectPort(pair<int,int>, int);		// Set vector portee
		virtual string getType() override;	// Override de la fonction pere, renvoyant le type
};

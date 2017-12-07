#include <string>
#include "entite.h"
#include "coords.h"
#include <vector>

#pragma once

using namespace std;

class joueur : public entite
{
	bool pelle;
	bool victoire;
	//vector<objet> equipement;


public:
	joueur(string nom_n);
	~joueur();
	coords getSlot();

	bool getPelle();
	void deplacerJoueur();
	void creuser();
	void ramasser();
	bool getVictoire();

};
#include <string>
#include <vector>

#include "../headers/entite.h"
#include "../headers/coords.h"

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
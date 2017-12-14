﻿#pragma once

#include <string>
#include <vector>

#include "../headers/armure.h"
#include "../headers/entite.h"
#include "../headers/carte.h"
#include "../headers/coords.h"
#include "../headers/mousquet.h"
#include "../headers/pelle.h"
#include "../headers/objet.h"
#include "../headers/tresor.h"
#include "../headers/io.h"

using namespace std;

class joueur : public entite
{
	bool pellePoss;
	bool victoire;
	vector<objet> equipement;

public:
	joueur(string nom_n);
	~joueur();

	bool getPellePoss();
	void deplacerJoueur(carte map);
	void ramasser(carte map);
	bool getVictoire();
	string joueurString();

};
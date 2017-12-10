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
	void deplacerJoueur();
	void ramasser(carte map);
	bool getVictoire();
	string joueurString();

};
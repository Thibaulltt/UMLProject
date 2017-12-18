#pragma once

#include <string>
#include <vector>

#include "../headers/carte.h"
#include "../headers/entite.h"
#include "../headers/io.h"
#include "../headers/objetCarte.h"

using namespace std;

class joueur : public entite
{
	bool pellePoss;
	bool victoire;
	vector<objetCarte> equipement;

public:
	joueur(string nom_n, bool ramassable_n);
	bool getPellePoss();
	void ramasser(carte mappe);
	bool getVictoire();
	string joueurString();
	~joueur();

	//Virtual & override
	void seDeplacer(carte mappe) override;
	void attaquer() override;
};
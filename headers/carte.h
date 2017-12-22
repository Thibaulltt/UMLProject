﻿#pragma once

#include <string>
#include <vector>

#include "../headers/objetCarte.h"

using namespace std;


//!
/*!
Classe représentant la carte où se déroule le jeu
*/
class carte
{
	unsigned int taille;
	vector<vector<vector<objetCarte*>>> aireJeu;

public:
	carte();
	carte(int taille_n);
	int getTaille();
	void setCase(pair<int, int> slot, objetCarte * objC);
	vector<objetCarte*> getCase(pair<int,int> slot);
	string toString();
	vector<vector<vector<objetCarte*>>> getAireJeu();
	void delObjet(int x, int y, int position);
	~carte();
};
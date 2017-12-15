#pragma once

#include <vector>

#include "../headers/coords.h"

class entite
{
protected:
	string nom;
	int porteeDEP;
	int scoreATT;
	int scoreDEF;
	bool vivant;
	int porteeATT;
	vector<coords> vectPort;
	coords slot;

public :
	entite(string nom_n);
	~entite();
	string getNom();
	int getScoreATT();
	int getScoreDEF();
	void setSlot(pair<int, int> slot_n);
	coords getSlot();
	void setVectPort(coords slot_n, int tailleMap);
	vector<coords> getVectPort();
	void setVivant(bool vivant_n);
	bool getVivant();
};
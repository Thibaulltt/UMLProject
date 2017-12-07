#include <vector>

#pragma once

using namespace std;

class carte
{
	unsigned int taille;
	vector<vector<int>> aireJeu;

public:
	carte();
	int getTaille();
	void setAireJeu(pair<int, int> slot, int value);
	void setCase(pair<int, int> slot, int value);
	vector<vector<int>> getAireJeu();
	~carte();
};
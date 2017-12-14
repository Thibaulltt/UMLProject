#include <iostream>

#pragma once

using namespace std;

class coords
{
	pair<int, int> valeurs;

public:
	coords();
	~coords();
	void setValeurs(pair<int, int> valeurs_n);
	void setValeurs(coords valeurs_n);
	pair<int, int> getValeurs();
};
#include "../headers/objet.h"

#pragma once

class objetCombat : public objet
{
protected:
	int attack;
	int defense;

public:
	objetCombat(int ID_n);
	~objetCombat();
};

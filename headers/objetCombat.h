#pragma once
#include "objet.h"


class objetCombat : public objet
{
protected:
	int attack;
	int defense;

public:
	objetCombat(int ID_n);
	~objetCombat();
};

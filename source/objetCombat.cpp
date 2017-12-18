
#include "../headers/objetCombat.h"

objetCombat::objetCombat(string nom_n, int att_n, int def_n, bool ramassable_n) : objetCarte(nom_n, ramassable_n)
{
	nom = nom_n;
	attack = att_n;
	defense = def_n;
	ramassable = true;
}

int objetCombat::getAttack()
{
	return this->attack;
}

int objetCombat::getDefense()
{
	return this->defense;
}

objetCombat::~objetCombat()
{
}
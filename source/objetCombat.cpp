#include "../headers/objetCombat.h"

objetCombat::objetCombat(int ID_n) : objet(ID_n)
{
	attack = 0;
	defense = 0;
}

int objetCombat::getAttack()
{
	return this->attack;
}

int objetComabt::getDefense()
{
	return this->defense;
}
objetCombat::~objetCombat()
{

}
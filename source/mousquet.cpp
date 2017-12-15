#include "../headers/mousquet.h"

mousquet::mousquet() : objetCombat()
{
	attack = 150;
}

string mousquet::getType() {
	return std::string("mousquet");
}
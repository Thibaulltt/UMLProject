#include "../headers/armure.h"

armure::armure() : objetCombat()
{
	defense = 91;
}

string armure::getType() {
	return std::string("armure");
}
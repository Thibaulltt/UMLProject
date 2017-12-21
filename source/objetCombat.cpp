
#include "../headers/objetCombat.h"
#include <iostream>

using namespace std;
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

string objetCombat::toString() //Format retour : nom / attack : defense
{
	string stringRetour += objetCarte::toString();

	stringRetour += "/C/";

	string stats = "";
	
	//Ajout stats
	stats = to_string(attack) + ":" + to_string(defense);
	
	stringRetour += ":" + stats;
	return stringRetour;
}

objetCombat::~objetCombat()
{
}
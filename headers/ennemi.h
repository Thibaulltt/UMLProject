#include "../headers/coords.h"
#include "../headers/entite.h"

#pragma once

class ennemi : public entite //Classe ennemi heritant d'entite
{
	

public:

	ennemi(string nom_n);
	void attaquer();
	void deplacerMob();
};
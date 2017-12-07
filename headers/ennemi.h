#include "coords.h"
#pragma once

#include "entite.h"


class ennemi : public entite //Classe ennemi heritant d'entite
{
	

public:

	ennemi(string nom_n);
	void attaquer();
	void deplacerMob();
};
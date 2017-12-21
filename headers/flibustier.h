#pragma once

#include "../headers/carte.h"
#include "../headers/ennemi.h"

class flibustier : public ennemi
{
	public:
		flibustier(string nom_n, bool ramassable_n);
		~flibustier();

		//Virtual & override
		void seDeplacer(carte mappe) override;
		void attaquer() override;	// Attaque de l'ennemi
		string toString() override;
};
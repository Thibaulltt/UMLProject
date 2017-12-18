#pragma once

#include "../headers/carte.h"
#include "../headers/ennemi.h"

class boucanier : public ennemi
{
	public:
		boucanier(string nom_n, bool ramassable_n);
		~boucanier();

		//Virtual & override
		void seDeplacer(carte mappe) override;
		void setVectPort(pair<int, int> slot_n, int tailleMap) override;
		void attaquer() override;	// Attaque de l'ennemi
};
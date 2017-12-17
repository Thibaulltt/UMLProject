#pragma once

#include "../headers/carte.h"
#include "../headers/ennemi.h"

class flibustier : public ennemi
{
	public:
		flibustier(string nom_n);
		void seDeplacer(carte mappe) override;
};
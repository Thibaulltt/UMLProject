#pragma once

#include "../headers/carte.h"
#include "../headers/entite.h"

class ennemi : public entite //Classe ennemi heritant d'entite
{
	public:
		ennemi(string nom_n, bool ramassable_n);	// Construction d'un ennemi
		std::string ennemiString();	// Fonction pour la sauvegarde

		//Virtual & override
		virtual void seDeplacer(carte mappe) override;	// Deplacement de l'ennemi
		virtual void setVectPort(pair<int, int>, int) override;		// Set vector portee
		virtual void attaquer() override;	// Attaque de l'ennemi
		virtual ~ennemi();
};
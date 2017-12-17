#pragma once

#include "../headers/entite.h"

class ennemi : public entite //Classe ennemi heritant d'entite
{
	public:
		ennemi(string nom_n) override;	// Construction d'un ennemi
		string ennemiString();	// Fonction pour la sauvegarde

		//Virtual & override
		virtual void attaquer() override;	// Attaque de l'ennemi
		virtual void seDeplacer() override;	// Deplacement de l'ennemi
		virtual void setVectPort(pair<int, int>, int) override;		// Set vector portee
};
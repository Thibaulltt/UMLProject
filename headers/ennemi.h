#pragma once

#include "../headers/entite.h"

class ennemi : public entite //Classe ennemi heritant d'entite
{
	public:
		ennemi(string nom_n);	// Construction d'un ennemi
		void attaquer();	// Attaque de l'ennemi
		void deplacerMob();	// Deplacement de l'ennemi
		string ennemiString();	// Fonction pour la sauvegarde
		virtual string getType() override;
};
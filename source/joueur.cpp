#include "../headers/coords.h"
#include "../headers/joueur.h"

//Fonctions classe joueur
joueur::joueur(string nom_n) : entite(nom_n)
{
	this->equipement.resize(5);
}

coords joueur::getSlot()
{
	return slot;
}

bool joueur::getPelle()
{
	return pelle;
}

void joueur::deplacerJoueur()
{
	//mettre à jour nouvelle position (slot)
	//en utilisant setSlot() et la position précédente + direction de déplacement
}


void joueur::ramasser()
{
	//Vecteur contenant les objets de la carte
	vector<vector<int>> aireJeu = game.getAireJeu();

	//Coordonnées du joueur
	int x = this.slot.getValeurs().first;
	int y = this.slot.getValeurs().second;


	if (aireJeu[x][y] != 0) //Si la case n'est pas vides
	{
		//Case tresor
		if (aireJeu[x][y] == 1) //Si on est sur le tresor
		{
			if (this.pelle == true) //Si le joueur a une pelle
			{
				tresor coffre;
				this->equipement[1] = coffre;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				cout << "Vous avez trouvé le trésor ! " << endl;									////////// COUT A MODIFIER ////////////
			}
		}

		//Case pelle
		if (aireJeu[x][y] == 2) //Si on est sur la pelle
		{
			if (this.pelle == false) //Si le joueur n'a pas de pelle
			{
				this.pelle = true;
				pelle shovel;	
				this->equipement[2] = shovel;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				cout << "Bravo ! Vous avez trouvé la pelle !" << endl;								////////// COUT A MODIFIER ////////////
			}
			
			if (this.pelle == false) //Si le joueur a déjà une pelle
			{
				cout << "Vous avez trouvé une pelle, mais vous en avez déjà une." << endl;			////////// COUT A MODIFIER ////////////
			}
		}

		//Case mousquet
		if (aireJeu[x][y] == 3) //Si on est sur une case avec mousquet
		{
			if (this.equipement[3] == NULL) //Si le joueur n'a pas de mousquet
			{
				mousquet fusil;
				this->equipement[3] = fusil;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				this->scoreATT += fusil.getAttack(); //MaJ stat joueur
				cout << "Bravo ! Vous avez trouvé le mousquet !" << endl;							////////// COUT A MODIFIER ////////////
			}

			if (this.equipement[3] != NULL) //Si le joueur a déjà un mousquet
			{
				cout << "Vous avez trouvé un mousquet, mais vous en avez déjà un." << endl;			////////// COUT A MODIFIER ////////////
			}
		}

		//Case armure
		if (aireJeu[x][y] == 4) //Si on est sur une case avec armure
		{
			if (this.equipement[4] == NULL) //Si le joueur n'a pas d'armure
			{
				armure armor;
				this->equipement[4] = armor;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				this->scoreATT *= 2; //MaJ stat joueur (attaque)
				this->scoreDEF += armor.getDefense(); //MaJ stat joueur (defense)
				cout << "Bravo ! Vous avez trouvé l'armure !" << endl;								////////// COUT A MODIFIER ////////////
			}

			if (this.equipement[4] != NULL) //Si le joueur a déjà un mousquet
			{
				cout << "Vous avez trouvé une armure, mais vous en avez déjà une." << endl;			////////// COUT A MODIFIER ////////////
			}
		}
	}
}

bool joueur::getVictoire()
{
	return victoire;
}

joueur::~joueur()
{

}
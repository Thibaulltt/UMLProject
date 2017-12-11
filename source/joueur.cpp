#include "../headers/coords.h"
#include "../headers/jeu.h"
#include "../headers/joueur.h"

//Fonctions classe joueur
joueur::joueur(string nom_n) : entite(nom_n)
{
	this->equipement.resize(5);
}

bool joueur::getPellePoss()
{
	return pellePoss;
}

void joueur::deplacerJoueur()
{
	//mettre à jour nouvelle position (slot)
	//en utilisant setSlot() et la position précédente + direction de déplacement
}


void joueur::ramasser(carte map)
{
	//Vecteur contenant les objets de la carte
	vector<vector<int>> aireJeu = map.getAireJeu();

	//Coordonnées du joueur
	int x = slot.getValeurs().first;
	int y = slot.getValeurs().second;


	if (aireJeu[x][y] != 0) //Si la case n'est pas vides
	{
		//Case tresor
		if (aireJeu[x][y] == 1) //Si on est sur le tresor
		{
			if (pellePoss == true) //Si le joueur a une pelle
			{
				tresor coffre(1);
				this->equipement[1] = coffre;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				cout << "Vous avez trouvé le trésor ! " << endl;									////////// COUT A MODIFIER ////////////
			}
		}

		//Case pelle
		if (aireJeu[x][y] == 2) //Si on est sur la pelle
		{
			if (pellePoss == false) //Si le joueur n'a pas de pelle
			{
				pellePoss = true;
				pelle shovel(2);
				this->equipement[2] = shovel;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				cout << "Bravo ! Vous avez trouvé la pelle !" << endl;								////////// COUT A MODIFIER ////////////
			}
			
			if (pellePoss == false) //Si le joueur a déjà une pelle
			{
				cout << "Vous avez trouvé une pelle, mais vous en avez déjà une." << endl;			////////// COUT A MODIFIER ////////////
			}
		}

		//Case mousquet
		if (aireJeu[x][y] == 3) //Si on est sur une case avec mousquet
		{
			if (equipement[3].getID() != 3) //Si le joueur n'a pas de mousquet
			{
				mousquet fusil(3);
				equipement[3] = fusil;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				this->scoreATT += fusil.getAttack(); //MaJ stat joueur
				cout << "Bravo ! Vous avez trouvé le mousquet !" << endl;							////////// COUT A MODIFIER ////////////
			}

			if (equipement[3].getID() == 3 ) //Si le joueur a déjà un mousquet
			{
				cout << "Vous avez trouvé un mousquet, mais vous en avez déjà un." << endl;			////////// COUT A MODIFIER ////////////
			}
		}

		//Case armure
		if (aireJeu[x][y] == 4) //Si on est sur une case avec armure
		{
			if (equipement[4].getID( ) != 4) //Si le joueur n'a pas d'armure
			{
				armure armor(4);
				equipement[4] = armor;
				aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
				this->scoreATT *= 2; //MaJ stat joueur (attaque)
				this->scoreDEF += armor.getDefense(); //MaJ stat joueur (defense)
				cout << "Bravo ! Vous avez trouvé l'armure !" << endl;								////////// COUT A MODIFIER ////////////
			}

			if (equipement[4].getID() == 4) //Si le joueur a déjà un mousquet
			{
				cout << "Vous avez trouvé une armure, mais vous en avez déjà une." << endl;			////////// COUT A MODIFIER ////////////
			}
		}
	}
}


string joueur::joueurString() //Format retour : nom / idObjet1 : idObjet2 : idObjet3 : idObjet4 / coordX : coordY / boolVivant : boolPossPelle / porteeDEP : scoreATT : scoreDEF
{
	string stringRetour = "";

	//Ajout vecteur objet 
	string idObjet = "";
	for (int i = 1; i < equipement.size(); i++)
	{
		if (i != (equipement.size()) - 1)
		{
			idObjet = idObjet + to_string(equipement[i].getID()) + ":";
		}
		else
		{
			idObjet = idObjet + to_string(equipement[i].getID());
		}
	}

	//Ajout coordonnées
	string coordonnees = to_string(slot.getValeurs().first) + ":" + to_string(slot.getValeurs().second);

	//Ajout bool
	string booleens = to_string(vivant) + ":" + to_string(pellePoss);

	//Ajout stats
	string stats = to_string(porteeATT) + ":" + to_string(scoreATT) + ":" + to_string(scoreDEF);

	//String final
	stringRetour = nom + "/" + idObjet + "/" + coordonnees + "/" + booleens + "/" + stats;


	return stringRetour;
}

bool joueur::getVictoire()
{
	return victoire;
}

joueur::~joueur()
{

}
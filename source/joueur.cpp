#include "../headers/jeu.h"
#include "../headers/joueur.h"
#include "../headers/io.h"
#include <typeinfo>

//Fonctions classe joueur
joueur::joueur(string nom_n, bool ramassable_n) : entite(nom_n, ramassable_n)
{
	nom = nom_n;
	ramassable = ramassable_n;
}

bool joueur::getPellePoss()
{
	return pellePoss;
}

void joueur::seDeplacer(carte mappe)
{
	//mettre à jour nouvelle position (slot)
	//en utilisant setSlot() et la position précédente + direction de déplacement
	// Ici, on utilise la valeur slot dans entite.h pour modifier la case joueur
	pair<int,int> positionJoueur = getCoordonnees();
	io::choisirCase(mappe, positionJoueur);
}

bool joueur::checkPoss(string nomObjet)
{
	for (int i = 0; i < equipement.size(); i++)
	{
		if (equipement[i]->getNom() == nomObjet)
		{
			return true;
		}
	}
	return false;
}


void joueur::ramasser(carte mappe)
{
	//Vecteur contenant les objets de la carte
	vector<vector<vector<objetCarte *>>> aireJeu = mappe.getAireJeu();

	////Coordonnées du joueur
	int x = coordonnees.first;
	int y = coordonnees.second;


	if (aireJeu[x][y].size() > 1) //Si il y a autre chose qu'un joueur sur la case
	{
		for (int i = 0; i < aireJeu[x][y].size(); i++) //Parcours de ce qu'il se trouve dans la case
		{
			if (aireJeu[x][y][i]->getRamassable())
			{

				//Pelle
				if (aireJeu[x][y][i]->getNom() == "pelle") //Si on est sur une case avec pelle
				{
					if (!checkPoss("pelle")) //Si le joueur n'a pas de pelle
					{
						equipement.push_back(aireJeu[x][y][i]); //On met la pelle dans l'equipement du joueur
						mappe.delObjet(x, y, i); //Suppression de l'objet de la case
						cout << "Vous avez trouvé la pelle ! " << endl;													//////////// COUT A MODIFIER ///////////

					}
					else
					{
						cout << "Vous avez déjà une pelle ! " << endl;													//////////// COUT A MODIFIER ///////////
					}
				}

				//Tresor
				if (checkPoss("pelle")) //On ne peur chercher le tresor que si on a une pelle
				{
					if (aireJeu[x][y][i]->getNom() == "tresor") //Si on est sur la case tresor
					{
						if (!checkPoss("pelle")) //Si le joueur n'a pas de pelle
						{
							equipement.push_back(aireJeu[x][y][i]); //On met le tresor dans l'equipement du joueur
							mappe.delObjet(x, y, i); //Suppression de l'objet de la case
							cout << "Vous avez trouvé le tresor  ! " << endl;													//////////// COUT A MODIFIER ///////////

						}
					}
				}

				//Mousquet
				if (aireJeu[x][y][i]->getNom() == "mousquet") //Si on est sur une case avec un mousquet
				{
					if (!checkPoss("mousquet")) //Si le joueur n'a pas de mousquet
					{
						equipement.push_back(aireJeu[x][y][i]); //On met le mousquet dans l'equipement du joueur
						scoreATT += aireJeu[x][y][i]->getAttack(); //MaJ stats
						scoreDEF += aireJeu[x][y][i]->getDefense();
						mappe.delObjet(x, y, i); //Suppression de l'objet de la case
						cout << "Vous avez trouvé le mousquet ! " << endl;													//////////// COUT A MODIFIER ///////////

					}
					else
					{
						cout << "Vous avez déjà un mousquet ! " << endl;													//////////// COUT A MODIFIER ///////////
					}
				}

				//Armure
				if (aireJeu[x][y][i]->getNom() == "armure") //Si on est sur une case avec une armure 
				{
					if (!checkPoss("armure")) //Si le joueur n'a pas d'armure
					{
						equipement.push_back(aireJeu[x][y][i]); //On met l'armure
						scoreATT += aireJeu[x][y][i]->getAttack(); //MaJ stats
						scoreDEF += aireJeu[x][y][i]->getDefense();
						mappe.delObjet(x, y, i); //Suppression de l'objet de la case
						cout << "Vous avez trouvé l'armure ! " << endl;													//////////// COUT A MODIFIER ///////////
					}
					else
					{
						cout << "Vous avez déjà une armure ! " << endl;													//////////// COUT A MODIFIER ///////////
					}
				}
			}
		}
	}
}

void joueur::equiper(objetCarte vect_o)
{
	equipement.push_back(&vect_o);

	if (vect_o.getType() == "objetCombat")
	{
		scoreATT += vect_o.getAttack();
		scoreDEF += vect_o.getDefense();
	}
	else if (vect_o.getNom() == "pelle")
	{
		pellePoss = true;
	}
}

string joueur::toString() //Format retour : J / nom / objet1 § objet2 § objet3
{
	string stringRetour =  "J/" + entite::toString();

	//Ajout vecteur objet 
	string allObjet = "";
	
	for (int i = 0; i < equipement.size(); i++)
	{
		if (i != (equipement.size()) - 1)
		{
			allObjet = allObjet + equipement[i] -> toString() + "§";
		}
		else
		{
			allObjet = allObjet + equipement[i] -> toString();
		}
	}

	//String final
	stringRetour += "/" + allObjet;

	return stringRetour;
}

bool joueur::getVictoire()
{
	return victoire;
}

void joueur::attaquer()
{

}

joueur::~joueur()
{
}
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


void joueur::ramasser(carte mappe)
{
	////Vecteur contenant les objets de la carte
	//vector<vector<vector<objetCarte>>> aireJeu = mappe.getAireJeu();

	////Coordonnées du joueur
	//int x = getCoordonnees().first;
	//int y = getCoordonnees().second;


	//if (aireJeu[x][y] != 0) //Si la case n'est pas vide
	//{
	//	//Case tresor
	//	if (aireJeu[x][y] == 1) //Si on est sur le tresor
	//	{
	//		/*if (pellePoss == true) //Si le joueur a une pelle
	//		{
	//			tresor coffre();								/////// A METTRE A JOUR
	//			this->equipement[1] = coffre;							/////// A METTRE A JOUR
	//			aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
	//			cout << "Vous avez trouvé le trésor ! " << endl;									////////// COUT A MODIFIER ////////////
	//		}*/
	//	}

	//	//Case pelle
	//	if (aireJeu[x][y] == 2) //Si on est sur la pelle
	//	{
	//		/*if (pellePoss == false) //Si le joueur n'a pas de pelle
	//		{
	//			pellePoss = true;
	//			pelle shovel();									/////// A METTRE A JOUR
	//			this->equipement[2] = shovel;							/////// A METTRE A JOUR
	//			aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
	//			cout << "Bravo ! Vous avez trouvé la pelle !" << endl;								////////// COUT A MODIFIER ////////////
	//		}*/
	//		
	//		if (pellePoss == false) //Si le joueur a déjà une pelle
	//		{
	//			cout << "Vous avez trouvé une pelle, mais vous en avez déjà une." << endl;			////////// COUT A MODIFIER ////////////
	//		}
	//	}

	//	//Case mousquet
	//	if (aireJeu[x][y] == 3) //Si on est sur une case avec mousquet
	//	{
	//		/*if (equipement[3].getID() != 3) //Si le joueur n'a pas de mousquet
	//		{
	//			mousquet fusil();								/////// A METTRE A JOUR
	//			equipement[3] = fusil;								/////// A METTRE A JOUR
	//			aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
	//			this->scoreATT += fusil.getAttack(); //MaJ stat joueur				/////// A METTRE A JOUR
	//			cout << "Bravo ! Vous avez trouvé le mousquet !" << endl;							////////// COUT A MODIFIER ////////////
	//		}*/

	//		/*if (equipement[3].getID() == 3 ) //Si le joueur a déjà un mousquet			/////// A METTRE A JOUR
	//		{
	//			cout << "Vous avez trouvé un mousquet, mais vous en avez déjà un." << endl;			////////// COUT A MODIFIER ////////////
	//		}*/
	//	}

	//	//Case armure
	//	if (aireJeu[x][y] == 4) //Si on est sur une case avec armure
	//	{
	//		/*if (equipement[4].getID( ) != 4) //Si le joueur n'a pas d'armure			/////// A METTRE A JOUR
	//		{
	//			armure armor();									/////// A METTRE A JOUR
	//			equipement[4] = armor;								/////// A METTRE A JOUR
	//			aireJeu[x][y] = 0; //On enleve de la carte l'objet trouvé
	//			this->scoreATT *= 2; //MaJ stat joueur (attaque)
	//			this->scoreDEF += armor.getDefense(); //MaJ stat joueur (defense)		/////// A METTRE A JOUR
	//			cout << "Bravo ! Vous avez trouvé l'armure !" << endl;								////////// COUT A MODIFIER ////////////
	//		}*/

	//		/*if (equipement[4].getID() == 4) //Si le joueur a déjà un mousquet
	//		{
	//			cout << "Vous avez trouvé une armure, mais vous en avez déjà une." << endl;			////////// COUT A MODIFIER ////////////
	//		}*/
	//	}
	//}
}


string joueur::toString() //Format retour : nom / porteeDEP : scoreATT : scoreDEF / objet1 § objet2 § objet3
{
	string stringRetour =  entite::toString();

	//Ajout vecteur objet 
	string allObjet = "";
	
	for (int i = 0; i < equipement.size(); i++)
	{
		if (i != (equipement.size()) - 1)
		{
			allObjet = allObjet + equipement[i].toString() + "§";
		}
		else
		{
			allObjet = allObjet + equipement[i].toString();
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

string joueur::getType() {
	return typeid(this).name();
}

joueur::~joueur()
{
}
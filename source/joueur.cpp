#include "../headers/coords.h"
#include "../headers/joueur.h"

//Fonctions classe joueur
joueur::joueur(string nom_n) : entite(nom_n)
{

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
	//mettre � jour nouvelle position (slot)
	//en utilisant setSlot() et la position pr�c�dente + direction de d�placement
}

void joueur::creuser()
{
	//utiliser la nouvelle position, comparer avec la carte (aireJeu)
	//pour identifier si le tr�sor se trouve sur la case
	//si le tr�sor s'y trouve, mettre le bool victoire � true.
}

void joueur::ramasser()
{
	//mettre � jour le joueur (remplir son vecteur d'�quipement)
	//s'il a ramass� la pelle, mettre � jour son bool pelle
	//si l'objet correspond (par l'ID) � un objet qu'il a d�j�, ne pas ramasser
}

bool joueur::getVictoire()
{
	return victoire;
}

joueur::~joueur()
{

}
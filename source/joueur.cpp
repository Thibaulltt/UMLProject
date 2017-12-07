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
	//mettre à jour nouvelle position (slot)
	//en utilisant setSlot() et la position précédente + direction de déplacement
}

void joueur::creuser()
{
	//utiliser la nouvelle position, comparer avec la carte (aireJeu)
	//pour identifier si le trésor se trouve sur la case
	//si le trésor s'y trouve, mettre le bool victoire à true.
}

void joueur::ramasser()
{
	//mettre à jour le joueur (remplir son vecteur d'équipement)
	//s'il a ramassé la pelle, mettre à jour son bool pelle
	//si l'objet correspond (par l'ID) à un objet qu'il a déjà, ne pas ramasser
}

bool joueur::getVictoire()
{
	return victoire;
}

joueur::~joueur()
{

}
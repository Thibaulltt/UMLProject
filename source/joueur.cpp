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
}

void joueur::equiper(vector<objetCarte*> vect_o)
{
	for (int i = 0; i < vect_o.size(); i++)
	{
		equipement.push_back(vect_o[i]);

		if (vect_o[i]->getType() == "objetCombat")
		{
			scoreATT += vect_o[i]->getAttack();
			scoreDEF += vect_o[i]->getDefense();
		}
		else if (vect_o[i]->getNom() == "pelle")
		{
			pellePoss = true;
		}
	}
}

string joueur::toString() //Format retour : nom / porteeDEP : scoreATT : scoreDEF / objet1 § objet2 § objet3
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

string joueur::getType() {
	return typeid(this).name();
}

joueur::~joueur()
{
}
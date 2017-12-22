#include "../headers/ennemi.h"
#include <stdlib.h>
#include <utility>

using namespace std;

ennemi::ennemi(string nom_n, bool ramassable_n) : entite(nom_n, ramassable_n)
{
	nom = nom_n;
	scoreATT = 100;
	scoreDEF = 100;
	ramassable = ramassable_n;
}


void ennemi::seDeplacer(carte mappe)
{
	int directionDeplacement = (rand() % 3)-1; // Modulo entre 0 et 1 (originellement entre 1 et 3-1)
	// On fait un intervalle
	int modulo = (porteeDEP+1) * 2 - porteeDEP;
	int deplacement = rand() % modulo;
	if (directionDeplacement == 0) {
		// Deplacement gauche-droite
		// Si on est > 0 et inferieur a taille map
		if (coordonnees.first+deplacement > 0 || coordonnees.first + deplacement < mappe.getTaille()) {
			// Deplacement car on peut
			// YES WE CAN
			setCoordonnees(std::make_pair(coordonnees.first+deplacement, coordonnees.second));
		}
	} else {
		// Deplacement haut-bas
		if (coordonnees.second+deplacement > 0 || coordonnees.second + deplacement < mappe.getTaille()) {
			// Deplacement car on peut
			// YES WE CAN
			setCoordonnees(std::make_pair(coordonnees.first, coordonnees.second+deplacement));
		}
	}
}

void ennemi::setVectPort(pair<int, int>, int)
{
}

bool ennemi::attaquer(entite * adver)
{
}

string ennemi::toString()
{
	string stringRetour = entite::toString();
	return stringRetour;
}

ennemi::~ennemi()
{
}
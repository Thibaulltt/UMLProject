#include <math.h>
#include <string>
#include <vector>

#include "../headers/coords.h"
#include "../headers/entite.h"

using namespace std;

//Fonctions classe entite

entite::entite(string nom_n)
{
	nom = nom_n;
	porteeDEP = 1;
	scoreATT = 0;
	porteeATT = 0;
	scoreDEF = 0;
	vivant = true;
}

string entite::getNom()
{
	return nom;
}

int entite::getScoreATT()
{
	return scoreATT;
}

int entite::getScoreDEF()
{
	return scoreDEF;
}

void entite::setVectPort(coords slot_n, int tailleMap) //[A DEPLACER DANS ENTITE CONCERNEE]
{
	pair<int, int> pair_c = slot_n.getValeurs();
	coords dummy;

	/*Refonte fonctionnement portée
	Désormais, on prend la stat de portée d'attaque, et on entre 2 points:
	- le point supérieur gauche (i-porteeATT, j-porteeATT) = a
	- le point inférieur droit (i+porteeATT, j+porteeATT) = b
	Ensuite, on fait une boucle ij qui part de a et qui va jusqu'à b
	en remplissant vectPort avec toutes les cases rencontrées.
	Résumé: on crée un carré autour de l'entité et on remplit.
	Avantages: moins sale qu'avant; permet d'avoir toutes les cases
	(l'ancienne méthode ne rajoutait que les lignes droites et diagonales).
	Inconvénient: oblige à réécrire cette fonction pour chaque entité qui a
	un pattern différent, mais c'était pareil avant.
	*/

	pair<int, int> sup_g = make_pair(pair_c.first - porteeATT, pair_c.second - porteeATT);
	pair<int, int> inf_d = make_pair(pair_c.first + porteeATT, pair_c.second + porteeATT);

	vectPort.resize(pow(sup_g.second - sup_g.first + 1, 2));

	dummy.setValeurs(pair_c);
	vectPort.push_back(dummy);

	for (int i = sup_g.first; i <= inf_d.first; i++)
	{
		for (int j = sup_g.second; j <= inf_d.second; j++)
		{
			if (i < 0 || j < 0 || i > tailleMap || j > tailleMap)	//hors map
			{
				continue;
			}

			dummy.setValeurs(make_pair(i, j));
			vectPort.push_back(dummy);
		}
	}
}

vector<coords> entite::getVectPort()
{
	return vectPort;
}

void entite::setVivant(bool vivant_n)
{
	vivant = vivant_n;
}

bool entite::getVivant()
{
	return vivant;
}

entite::~entite() {}

string entite::getType() {
	return std::string("entite");
}

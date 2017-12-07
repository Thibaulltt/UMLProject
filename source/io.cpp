// Corps de toutes les fonctions du namespace IO

#include <iostream>
#include "../headers/io.h"

#define BLANK "\033[0m"
#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define MAGENTA "\033[95m"

using namespace std;

namespace io {

	void choisirCase(coords &posJ){
		//a faire dans joueur.cpp, fonction deplacerJoueur :
		/*
		prendre coordonnees joueur actuelles
		les mettre dans un type <coords>
		appeller choisirCase(positionJoueur)
		la nouvelle coordonnee sera mise dans la position actuelle joueur
		*/
		// a faire ici :
		/*
		variables : x,y (tiennent temporairement la position voulue par le joueur)

		prendre coordonnees actuelles
		verifier ou il peut aller (en regardant coordonnees + taille carte)
		proposer les bons prompt sur le message de bas d'ecran
		mettre a jour le message de bas d'ecran
		afficher une croix ou le joueur peut aller
		mettre a jour la carte
		faire :
			- attendre entree clavier
			- quand entree clavier, verifier que on peut l'accepter (joueur peut se deplacer la)
			- mettre a jour affichage
			- mettre a jour coordonnees choisies
		tant que entree != touche valider
		une fois la case choisie :
		mettre x,y dans posJ
		mettre a jour affichage
		retourner
		*/
		cout << BLUE << "blue text " << BLANK << GREEN << "green text" << BLANK << endl;
		return;
	}

}
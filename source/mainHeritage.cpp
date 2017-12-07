#include "../headers/flibustier.h"
#include "../headers/boucanier.h"
#include "../headers/joueur.h"
#include "../headers/pelle.h"
#include "../headers/tresor.h"
#include "../headers/armure.h"
#include "../headers/mousquet.h"

#include <iostream>

using namespace std;

int main()
{
	flibustier flib;
	boucanier bouc;
	joueur player;

	cout << flib.getNom() <<  endl;
	cout << bouc.getNom() << endl;
	cout << player.getNom() << endl;

	pelle shovel(1);
	tresor tres(2);
	armure armor(3);
	mousquet fusil(4);

	cout << shovel.getID() << endl;
	cout << tres.getID() << endl;
	cout << armor.getID() << endl;
	cout << fusil.getID() << endl;


}
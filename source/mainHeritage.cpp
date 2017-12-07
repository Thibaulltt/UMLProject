#include "flibustier.h"
#include "boucanier.h"
#include "joueur.h"
#include "pelle.h"
#include "tresor.h"
#include "armure.h"
#include "mousquet.h"

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
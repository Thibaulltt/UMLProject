#include "objet.h"

//Fonctions classe objet
objet::objet(int ID_n)
{
	ID = ID_n;
	ramasse = false;
}

int objet::getID()
{
	return this -> ID;
}

objet::~objet()
{

}
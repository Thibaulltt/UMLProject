﻿#include "../headers/objet.h"

//Fonctions classe objet
objet::objet()
{
	ID = -1;
}

objet::objet(int ID_n)
{
	ID = ID_n;
}

int objet::getID()
{
	return this -> ID;
}

objet::~objet()
{

}
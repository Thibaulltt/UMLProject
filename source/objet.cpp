#include <string>

#include "../headers/objet.h"

//Fonctions classe objet
objet::objet() {}

objet::~objet() {}

string objet::getType() {
	return std::string("objet");
}
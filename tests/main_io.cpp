#include <iostream>
#include <utility>
#include "../headers/io.h"

using namespace io;
using namespace std;

int main(){
	printf("Tests du namespace IO :\n");
	carte c;
	coords j;
	printf("Valeurs : (%d,%d)\n", 0, 0);
	j.setValeurs(std::make_pair(0,0));
	choisirCase(c,j);
	afficherMessage();
	updateMessage(0, "this is an example string, this is an example string");
	return 0;
}
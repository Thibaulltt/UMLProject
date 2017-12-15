# The flags passed to the compiler for each instruction
FLAGS=-Wall -pedantic -std=c++11
# Target files
TARGET=jeu
# Rajoute .cpp pour l'entree
SOURCEFILE=source/$(TARGET).cpp
# Rajoute .o pour la sortie
OUTPUTFILE=objects/$(TARGET).o
HEADERFILE=headers/$(TARGET).h

# Commande permettant de compiler tous fichiers 1 par 1
object: $(SOURCEFILE) $(HEADERFILE)
	@echo "Compiling $(SOURCEFILE) into $(OUTPUTFILE) ..."
	@g++ $(FLAGS) -c $(SOURCEFILE) -o $(OUTPUTFILE)
	@echo "Compiling of $(OUTPUTFILE) complete."

Dig_or_die: objects/%.o headers/%.h
	@echo "Compiling $@ ..."
<<<<<<< HEAD
	@g++ -c $< -o objects/carte.o -std=c++11
	@echo "Compilation of $@ done."

all: source/$(wildcard*.cpp)
	cd source && g++ -std=c++11 -Wall -pedantic armure.cpp boucanier.cpp carte.cpp coords.cpp ennemi.cpp entite.cpp flibustier.cpp io.cpp jeu.cpp joueur.cpp mainJeu.cpp mousquet.cpp objet.cpp objetCombat.cpp pelle.cpp tresor.cpp -o ../Dig_or_die
=======
	@echo $<
>>>>>>> 40daae720a4689edec2ccecea84845eb7a4f4c52

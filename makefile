# The flags passed to the compiler for each instruction
FLAGS=-Wall -pedantic -std=c++11
# Target files
TARGET=jeu
# Rajoute .cpp pour l'entree
SOURCEFILE=source/$(TARGET).cpp
# Rajoute .o pour la sortie
OUTPUTFILE=objects/$(TARGET).o
HEADERFILE=headers/$(TARGET).h
ALL_OBJECTS=source/armure.cpp source/boucanier.cpp source/ennemi.cpp source/entite.cpp source/flibustier.cpp source/joueur.cpp source/mousquet.cpp source/objet.cpp source/objetCombat.cpp source/pelle.cpp source/tresor.cpp headers/armure.h headers/boucanier.h headers/ennemi.h headers/entite.h headers/flibustier.h headers/joueur.h headers/mousquet.h headers/objet.h headers/objetCombat.h headers/pelle.h headers/tresor.h 

# Commande permettant de compiler tous fichiers 1 par 1
object: $(SOURCEFILE) $(HEADERFILE)
	@echo "Compiling $(SOURCEFILE) into $(OUTPUTFILE) ..."
	@g++ $(FLAGS) -c $(SOURCEFILE) -o $(OUTPUTFILE)
	@echo "Compiling of $(OUTPUTFILE) complete."

Dig_or_die: objects/%.o headers/%.h
	@echo "Compiling $@ ..."
	@echo $<

all_objects: 
	@echo "Compiling all objects ..."
	@ for loopTarget in armure boucanier ennemi entite flibustier joueur mousquet objet objetCombat pelle tresor; do \
		make object TARGET=$$loopTarget; \
	done
	@echo "Compiling complete."

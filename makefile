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
	@echo $<
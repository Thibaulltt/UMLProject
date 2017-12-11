test_io: headers/io.h source/io.cpp tests/main_io.cpp obj_io obj_carte obj_coords
	@g++ tests/main_io.cpp objects/io.o objects/coords.o objects/carte.o -o tests/main_io.exe -std=c++11

obj_io: source/io.cpp headers/io.h obj_carte obj_coords
	@echo "Compiling $@ ..."
	@g++ -c source/io.cpp -o objects/io.o -std=c++11
	@echo "Compilation of $@ done."

obj_coords: source/coords.cpp headers/coords.h
	@g++ -c source/coords.cpp -o objects/coords.o -std=c++11

obj_carte: source/carte.cpp headers/carte.h
	@echo "Compiling $@ ..."
	@g++ -c $< -o objects/carte.o -std=c++11
	@echo "Compilation of $@ done."
